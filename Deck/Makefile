CC=g++
CFLAGS=-std=c++11 -c -Wall -O2
TESTFLAGS=-lgtest -lgtest_main -pthread
LDFLAGS=
SOURCES=Deck.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TESTSOURCES=DeckTest.cpp
TESTOBJECTS=$(TESTSOURCES:.cpp=.o)
TESTEXECUTABLE=DeckTest

test : $(TESTEXECUTABLE)
	./$(TESTEXECUTABLE)

$(TESTEXECUTABLE) : $(OBJECTS) $(TESTOBJECTS)
	$(CC) $(LDFLAGS) $(TESTFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) $^ -o $@

%Test.o : test/%Test.cpp
	$(CC) $(CFLAGS) $(TESTFLAGS) $^ -o $@

clean :
	rm -f *.o DeckTest

.PHONY : test clean