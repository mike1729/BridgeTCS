CC=clang++
CFLAGS=-std=c++11 -c -Wall -O2
TESTFLAGS=-lgtest -lgtest_main -pthread
LDFLAGS=
SOURCES=Bidding.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TESTSOURCE=BiddingTest.cpp
TESTOBJECT=$(TESTSOURCE:.cpp=.o)
TESTEXECUTABLE=BiddingTest

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
