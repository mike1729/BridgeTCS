CC=clang++
CFLAGS=-std=c++11 -c -Wall -O2
TESTFLAGS=-lgtest -lgtest_main -pthread
LDFLAGS=
SOURCES=Bidding.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TESTSOURCE=BiddingTest.cpp
TESTOBJECT=$(TESTSOURCE:.cpp=.o)
TESTEXECUTABLE=BiddingTest

HEADERS=*.hpp

test : $(TESTEXECUTABLE)
	./$(TESTEXECUTABLE)

$(TESTEXECUTABLE) : $(OBJECTS) $(TESTOBJECT)
	$(CC) $^ $(LDFLAGS) $(TESTFLAGS) -o $@ 

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(TESTOBJECT) : test/$(TESTSOURCE)
	$(CC) $(CFLAGS) $^ $(TESTFLAGS) -o $@

clean :
	rm -f $(OBJECTS) $(TESTEXECUTABLE) $(TESTOBJECT)

.PHONY : test clean
