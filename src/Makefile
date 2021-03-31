CC = g++
CFLAGS = -Wall
LDFLAGS = -lm

RM = rm -f
TARGET = main

OBJECTS = $(wildcard )

CPPFILES=$(filter %.cpp, $(PRJSRC))

all: main.o Teacher.o
	$(CC) -o main main.cpp Teacher.cpp

%.o: %.cpp 
	$(CC) $(CFLAGS) -c $<

run:
	./main

clean:
	$(RM) *.o $(TARGET)