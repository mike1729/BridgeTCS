SOURCES=$(wildcard src/*.cpp)
TESTSOURCES=$(wildcard src/test/*.cpp)
LIBRARY=libbridge.a
TESTDEPLIBS=
LIBDEPLIBS=

include Make.rules
