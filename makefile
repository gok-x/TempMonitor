OBJS = Thermistor.o MCP3002.o main.o Measurer.o PeriodicMeasurer.o Subject.o TemperatureData.o Observer.o Console.o View.o MqttTemperaturePublisher.o
TARGET = thermistorAtWater
CC = g++

CFLAGS = -Wall
LDFLAGS = -lwiringPi -lpaho-mqttpp3 -lpaho-mqtt3a

.SUFFIXES: .cpp .c .o

ALL: executable

debug: CFLAGS += -g3 -O0
debug: executable

executable: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

.c.o:	$<
	$(CC) -c $(CFLAGS) $<

.cpp.o:	$<
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJS) $(TARGET)
