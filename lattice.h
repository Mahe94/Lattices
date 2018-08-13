//=================================
// include guard
#ifndef __LATTICE_H_INCLUDED__
#define __LATTICE_H_INCLUDED__

#include <iostream>
#include <stdlib.h>
#include <gmpxx.h>

#define SEED 0
#define MAXSIZE 40
#define RANDOMNESS 20
#define RANDOMNESS_LIMIT 500000

using namespace std;

class Lattice
{
	private:
		int rows, cols;
	public:
		mpz_class B[MAXSIZE][MAXSIZE];
		
		Lattice(int n, int m);
		int getrows();
		int getcols();
		
		void createBasis();
		void randBasis();
		
		void printBasis();
		
};

#endif
