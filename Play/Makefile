CC=g++
CFLAGS=-std=c++11 -c -Wall -O2
LDESTFLAGS=-lgtest -lgtest_main -pthread
LDFLAGS=
SOURCES=Play.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TESTSOURCE=TrickTest.cpp
TESTOBJECT=$(TESTSOURCE:.cpp=.o)
TESTEXECUTABLE=TrickTest

HEADERS=*.hpp

test : $(TESTEXECUTABLE)
	./$(TESTEXECUTABLE)

$(TESTEXECUTABLE) : $(OBJECTS) $(TESTOBJECT)
	$(CC) $^ $(LDFLAGS) $(LDESTFLAGS) -o $@ 

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(TESTOBJECT) : test/$(TESTSOURCE)
	$(CC) $(CFLAGS) $^ $(LDESTFLAGS) -o $@

clean :
	rm -f $(OBJECTS) $(TESTEXECUTABLE) $(TESTOBJECT)

.PHONY : test clean
