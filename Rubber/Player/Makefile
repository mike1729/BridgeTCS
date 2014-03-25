CC=g++
CFLAGS=-std=c++11 -c -Wall -O2
TESTFLAGS=-lgtest -lgtest_main -pthread
LDFLAGS=
SOURCES=Player.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TESTSOURCE=PlayerTest.cpp
TESTOBJECT=$(TESTSOURCE:.cpp=.o)
TESTEXECUTABLE=PlayerTest

test : $(TESTEXECUTABLE)
	./$(TESTEXECUTABLE)

$(TESTEXECUTABLE) : $(OBJECTS) $(TESTOBJECT)
	$(CC) $(LDFLAGS) $(TESTFLAGS) $^ -o $@ 

%.o : %.cpp
	$(CC) $(CFLAGS) $^ -o $@

$(TESTOBJECT) : test/$(TESTSOURCE)
	$(CC) $(CFLAGS) $(TESTFLAGS) $^ -o $@

clean :
	rm -f Player.o PlayerTest.o PlayerTest

.PHONY : test clean

