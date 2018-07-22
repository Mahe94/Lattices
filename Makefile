# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -O3

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o lattice.o
	$(CXX) $(CXXFLAGS) -o main main.o lattice.o -lgmp -lgmpxx

# The main.o target can be written more simply

main.o: main.cpp lattice.h
	$(CXX) $(CXXFLAGS) -c main.cpp -lgmp -lgmpxx

lattice.o: lattice.cpp lattice.h
	$(CXX) $(CXXFLAGS) -c lattice.cpp -lgmp -lgmpxx
