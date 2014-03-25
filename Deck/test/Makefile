# Flags
LDFLAGS = -lgtest -lgtest_main -pthread

# Source files
SOURCES = CardTest.cpp DeckTest.cpp

all: Test

Test: $(SOURCES)
	g++ -std=c++11 -O2 -o Test $(SOURCES) $(LDFLAGS)

# Header dependencies for test files
include .depend