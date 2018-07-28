#include "lattice.h"
#include "functions.h"

int main(){
	
	int n , m;
	n = 10;
	m = 10;
	Lattice L = Lattice(n, m);
	
	
	L.createBasis();
	L.printBasis();
	
	cout<<endl;
	L.randBasis();
	
	L.printBasis();
	cout<<endl;
	
	for(int i = 0; i < m; ++i)
		cout<<norm(L.B[i], m)<<endl;
	cout<<endl;
	
	mpz_class v[m];
	addvector(L.B[0], L.B[1], v, m);
	
	print(v, m);
	
	intmult(v, 10, v, m);
	print(v, m);
	
	mpq_class u[m];
	
	mpz_class numerator, denominator;
	numerator = "4";
	denominator = "2";
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
	return 0;
}
