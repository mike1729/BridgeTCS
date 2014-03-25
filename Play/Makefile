CC=g++
CFLAGS=-std=c++11 -c -Wall -O2
TESTFLAGS=-lgtest -lgtest_main -pthread
LDFLAGS=
SOURCES=Play.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TESTSOURCE=TrickTest.cpp
TESTOBJECT=$(TESTSOURCE:.cpp=.o)
TESTEXECUTABLE=TrickTest

test : $(TESTEXECUTABLE)
	./$(TESTEXECUTABLE)

$(TESTEXECUTABLE) : $(OBJECTS) $(TESTOBJECT)
	$(CC) $(LDFLAGS) $(TESTFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) $^ -o $@

$(TESTOBJECT) : test/$(TESTSOURCE)
	$(CC) $(CFLAGS) $(TESTFLAGS) $^ -o $@

clean :
	rm -f Bidding.o BiddingTest.o BiddingTest

.PHONY : test clean

