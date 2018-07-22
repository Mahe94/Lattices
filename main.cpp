#include "lattice.h"

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
	return 0;
}
