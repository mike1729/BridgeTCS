SOURCES=$(wildcard src/*.cpp)
TESTSOURCES=$(wildcard src/test/*.cpp)
LIBRARY=src/libbridge.a
TESTDEPLIBS=
LIBDEPLIBS=src/ui/libbridgeui.a

include Make.rules
