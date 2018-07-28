#include "lattice.h"

Lattice::Lattice(int n, int m)
{

	if(n > m)
	{
		cout<<"Existence of dependent vectors in the basis. Terminating the program\n";
		exit(-1);
	}
	srand(SEED);
	
	rows = n;
	cols = m;
	
	//B = (mpz_class **) malloc (n * sizeof(mpz_class **));
	
	for(int i = 0; i < n; ++i)
	{
		//B[i] = (mpz_class *) malloc (m * sizeof(mpz_class *));
		for(int j = 0; j < m; ++j)
		{
			B[i][j] = 0;
		}
	}
}

int Lattice::getrows()
{
	return rows;
}

int Lattice::getcols()
{
	return cols;
}

void Lattice::createBasis()
{
	for(int i = 0; i < rows; ++i)
	{
		for(int j = i; j < cols; ++j)
		{
			B[i][j] = (rand() % RANDOMNESS_LIMIT) + 1;
		}	
	}
}

void Lattice::randBasis()
{
	int pos1, pos2, val;
	
	for(int r = 0 ; r < RANDOMNESS; ++r)
	{
		pos1 = rand() % rows;
		pos2 = rand() % rows;
		if(pos1 == pos2)
		{
			continue;
		}
		else
		{
			val = (rand() % RANDOMNESS_LIMIT) + 1;
			for(int j = 0; j < cols; ++j)
				B[pos1][j] = B[pos1][j] + (val * B[pos2][j]);
		}
	}
}

void Lattice::printBasis()
{
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < cols; ++j)
		{
			cout<<B[i][j]<<" ";
		}	
		cout<<endl;
	}
}
