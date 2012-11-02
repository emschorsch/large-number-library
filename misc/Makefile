CXX = g++
CXXFLAGS = -g

# Add any new .h and .inl files to the INCLUDES definition below:
INCLUDES = largeNum.h

# If you create any new non-templated classes, add an appropriate .o file
# to the OBJECTS definition below:
OBJECTS = largeNum.o

# If you create a new test program, add the name of the test program
# to the PROGRAMS definition below and then create a rule for that program
PROGRAMS = test sumPower

all: $(PROGRAMS)

test: $(INCLUDES) largeNum.cc test.cc
	$(CXX) $(CXXFLAGS) largeNum.cc $@.cc -Wall -o $@

sumPower: sumPower.cc
	$(CXX) $(CXXFLAGS) sumPower.cc -Wall -o $@

#test: test.cc largeNum.o
#	$(CXX) $(CXXFLAGS) test.cc -o $@

%.o: %.cc %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAMS)

.PHONY: all clean
