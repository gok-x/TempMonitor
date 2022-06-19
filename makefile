OBJS = Thermistor.o MCP3002.o main.o Measurer.o PeriodicMeasurer.o Subject.o TemperatureData.o Observer.o Console.o View.o
TARGET = thermistorAtWater
CC = g++

CFLAGS = -Wall -lwiringPi

.SUFFIXES: .cpp .c .o

ALL: executable

debug: CFLAGS += -g3 -O0
debug: executable

executable: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS)

.c.o:	$<
	$(CC) -c $(CFLAGS) $<

.cpp.o:	$<
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJS) $(TARGET)
