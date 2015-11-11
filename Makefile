TARGET= hex
CC= g++
CFLAGS= -std=c++11 -Wall -g
CFILES= main.cpp game.cpp
HFILES= game.h

all:
	$(CC) $(CFLAGS) $(CFILES) $(HFILES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: default all clean 
