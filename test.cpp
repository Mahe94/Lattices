#include "lattice.h"
#include "functions.h"

int main(){
	
	int n , m;
	n = 10;
	m = 10;
	Lattice L = Lattice(n, m);
	
	cout<<"----------------------------------------------------------\n\n";
	cout<<"Creating a new lattice with the following basis\n";
	L.createBasis();
	L.printBasis();
	cout<<"----------------------------------------------------------\n\n";
	
	//cout<<endl;
	//L.randBasis();
	
	//L.printBasis();
	cout<<endl;
	
	cout<<"----------------------------------------------------------\n\n";
	cout<<"Printing norm square of the basis vectors\n";
	for(int i = 0; i < m; ++i) {
		print(L.B[i], m);
		cout<<norm(L.B[i], m)<<"\n\n";
	}
	cout<<endl;
	cout<<"----------------------------------------------------------\n\n";
	
	mpz_class v[m];
	addvector(L.B[0], L.B[1], v, m);
	
	print(v, m);
	
	intmult(v, 10, v, m);
	print(v, m);
	
	mpq_class u[m];
	
	mpz_class numerator, denominator;
	numerator = "4";
	denominator = "3";
	mpq_class val;
	val = mpq_class (numerator , denominator);
	
	val = 1/val;
	val.canonicalize();
	cout<<val<<endl;
	
	ratmult(v, val, u, m);
	print(u, m);
	
	mpq_class G[MAXSIZE][MAXSIZE];
	gso(L.B, G, n , m);
	
	cout<<endl;
	print(G, n, m);
	cout<<endl;
	
	
	addvector(L.B[n-1], L.B[n-2], L.B[n-2], m);
	mpf_class X[MAXSIZE][MAXSIZE], Y[MAXSIZE][MAXSIZE];
	gson(L.B, X, Y, n, m);
	
	cout<<endl;
	print(X, n, m);
	cout<<endl;
	print(Y, n, m);
	return 0;
}
