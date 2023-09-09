#ifndef _MQTT_TEMPERATURE_PUBLISHER_HPP_
#define _MQTT_TEMPERATURE_PUBLISHER_HPP_

#include "Observer.hpp"
#include <mqtt/async_client.h>
#include <string>
#include <memory>

class MqttTemperaturePublisher : public Observer {
public:
    MqttTemperaturePublisher(const std::string& broker_address, const std::string& topic, const std::string& thingName);
    virtual ~MqttTemperaturePublisher();

    virtual void Update(Subject* theChangedSubject) override;

private:
    std::unique_ptr<mqtt::async_client> client;
    std::unique_ptr<mqtt::connect_options> connectOptions;
    std::string topic;
    std::string thingName;
};

#endif // _MQTT_TEMPERATURE_PUBLISHER_HPP_
