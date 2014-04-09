SOURCES=$(wildcard src/*.cpp)
TESTSOURCES=$(wildcard src/test/*.cpp)
LIBRARY=bin/libbridge.a
TESTDEPLIBS=
LIBDEPLIBS=

include Make.rules
