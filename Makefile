CXX = g++
CXXFLAGS = -g -Wall

# Add any new .h and .inl files to the INCLUDES definition below:
INCLUDES1 = largeNum.h largeNum2.h
INCLUDES2 = largeNum2.h

# If you create any new non-templated classes, add an appropriate .o file
# to the OBJECTS definition below:
OBJECTS = largeNum.o largeNum2.o

# If you create a new test program, add the name of the test program
# to the PROGRAMS definition below and then create a rule for that program
PROGRAMS = test sumPower

all: $(PROGRAMS)

test: $(INCLUDES) largeNum.cc largeNum2.cc test.cc
	$(CXX) $(CXXFLAGS) largeNum.cc largeNum2.cc $@.cc -Wall -o $@

sumPower: sumPower.cc
	$(CXX) $(CXXFLAGS) sumPower.cc -Wall -o $@

#test: test.cc largeNum.o
#	$(CXX) $(CXXFLAGS) test.cc -o $@

%.o: %.cc %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAMS)

.PHONY: all clean
