CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lSDL2 -lGL -lGLEW 

SOURCE = $(wildcard src/*.cpp)

all: build run

build:
	$(CC) $(CFLAGS) $(SOURCE) $(LDFLAGS) -o bin/build

run:
	./bin/build

clean:
	rm -f bin/build
	