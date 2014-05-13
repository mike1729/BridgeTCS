SOURCES=$(wildcard *.cpp)
TESTSOURCES=$(wildcard test/*.cpp)
LIBRARY=
PROJECTROOT=.
TESTDEPLIBS=
LIBDEPLIBS=

include $(PROJECTROOT)/Make.rules
