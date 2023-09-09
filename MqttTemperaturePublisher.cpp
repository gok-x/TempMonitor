#include "MqttTemperaturePublisher.hpp"
#include "TemperatureData.hpp"
#include <mqtt/async_client.h>
#include <nlohmann/json.hpp>
#include <ctime>

MqttTemperaturePublisher::MqttTemperaturePublisher(const std::string& broker_address, const std::string& topic, const std::string& thingName) {
    // MQTTクライアントの初期化
    client = std::make_unique<mqtt::async_client>(broker_address, "");
    connectOptions = std::make_unique<mqtt::connect_options>();
    client->connect(*connectOptions)->wait();
    this->topic = topic;
    this->thingName = thingName;
}

MqttTemperaturePublisher::~MqttTemperaturePublisher() {
    // MQTTクライアントの切断
    client->disconnect()->wait();
}

void MqttTemperaturePublisher::Update(Subject* theChangedSubject) {
    if (auto temperatureData = dynamic_cast<TemperatureData*>(theChangedSubject)) {
        // 最新の温度データを取得
        float latestTemperature = temperatureData->GetLastTemperatureData();
        // 最新の時間データを取得
        struct tm* latestTime = temperatureData->GetLastTime();
        
        // tm構造体からUNIX時間に変換
        time_t unixTime = mktime(latestTime);

        // JSONオブジェクトを作成
        nlohmann::json j;
        j["thing_name"] = thingName;
        j["COOLANT_TEMP"] = latestTemperature;
        j["timestamp"] = unixTime;

        // MQTTでパブリッシュ
        mqtt::message_ptr pubmsg = mqtt::make_message(topic, j.dump());
        pubmsg->set_qos(1); // Quality of Service level 1
        client->publish(pubmsg)->wait();
        printf("↑published.\n");
    }
}
