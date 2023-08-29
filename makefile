
SRCS:=ElevatorCar.cc elevator.cc
OBJS:=$(SRCS:.cc=.o)
TARGET=elevator
CC=g++
CFlAGS=-g
LINKER=g++ -o
LFLAGS=-Wall

all: $(OBJS)
	$(LINKER) $(TARGET) $(OBJS)

.cc.o:
	@echo "using $< to make $@"
	$(CC) $(CLFAGS) -o $@ -c $<

echo:
	@echo "SRCS=$(SRCS)"
	@echo "OBJS=$(OBJS)"

clean:
	@rm $(OBJS) $(TARGET)
