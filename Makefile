# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -O3

# ****************************************************
# Targets needed to bring the executable up to date

test: test.o lattice.o functions.o
	$(CXX) $(CXXFLAGS) -o test test.o lattice.o functions.o -lgmp -lgmpxx

# The test.o target can be written more simply

test.o: test.cpp lattice.h functions.h
	$(CXX) $(CXXFLAGS) -c test.cpp -lgmp -lgmpxx

lattice.o: lattice.cpp lattice.h
	$(CXX) $(CXXFLAGS) -c lattice.cpp -lgmp -lgmpxx
	
functions.o: functions.cpp functions.h lattice.h
	$(CXX) $(CXXFLAGS) -c functions.cpp -lgmp -lgmpxx
