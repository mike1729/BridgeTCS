CC=g++
CFLAGS=-std=c++11 -c -Wall -O2
TESTFLAGS=-lgtest -lgtest_main -pthread
LDFLAGS=
SOURCES=Arbiter.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TESTSOURCE=ArbiterTest.cpp
TESTOBJECT=$(TESTSOURCE:.cpp=.o)
TESTEXECUTABLE=ArbiterTest

test : $(TESTEXECUTABLE)
	./$(TESTEXECUTABLE)

$(TESTEXECUTABLE) : $(OBJECTS) $(TESTOBJECT)
	$(CC) $(LDFLAGS) $(TESTFLAGS) $^ -o $@ 

%.o : %.cpp
	$(CC) $(CFLAGS) $^ -o $@

$(TESTOBJECT) : test/$(TESTSOURCE)
	$(CC) $(CFLAGS) $(TESTFLAGS) $^ -o $@

clean :
	rm -f Arbiter.o ArbiterTest.o ArbiterTest

.PHONY : test clean

