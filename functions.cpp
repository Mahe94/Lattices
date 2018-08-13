#include "functions.h"

mpz_class norm(mpz_class v[], int m)
{
	mpz_class val = 0;
	
	for(int i = 0; i < m; ++i)
		val = val + v[i]*v[i];
		
	return val;
}


mpq_class norm(mpq_class v[], int m)
{
	mpq_class val = 0;
	
	for(int i = 0; i < m; ++i)
		val = val + v[i]*v[i];
		
	val.canonicalize();
	return val;
}

mpf_class norm(mpf_class v[], int m)
{
	mpf_class val = 0;
	
	for(int i = 0; i < m; ++i)
		val = val + v[i]*v[i];
		
	return val;
}


mpz_class dotp(mpz_class u[], mpz_class v[], int m)
{
	mpz_class val = 0;
	for(int i = 0; i < m; ++i)
		val = val + u[i] * v[i];
	return val;
}

mpq_class dotp(mpz_class u[], mpq_class v[], int m)
{
	mpq_class val = 0;
	for(int i = 0; i < m; ++i)
		val = val + u[i] * v[i];
	
	val.canonicalize();
	return val;
}

mpq_class dotp(mpq_class u[], mpq_class v[], int m)
{
	mpq_class val = 0;
	for(int i = 0; i < m; ++i)
		val = val + u[i] * v[i];
		
	val.canonicalize();
	return val;
}

mpf_class dotp(mpz_class u[], mpf_class v[], int m)
{
	mpf_class val = 0;
	for(int i = 0; i < m; ++i)
		val = val + u[i] * v[i];
		
	return val;
}

mpf_class dotp(mpq_class u[], mpf_class v[], int m)
{
	mpf_class val = 0;
	for(int i = 0; i < m; ++i)
		val = val + u[i] * v[i];
		
	return val;
}

mpf_class dotp(mpf_class u[], mpf_class v[], int m)
{
	mpf_class val = 0;
	for(int i = 0; i < m; ++i)
		val = val + u[i] * v[i];
		
	return val;
}

void addvector(mpz_class u[], mpz_class v[], mpz_class w[], int m)
{
	for(int i = 0; i < m; ++i)
		w[i] = u[i] + v[i];
}

void addvector(mpz_class u[], mpq_class v[], mpq_class w[], int m)
{
	for(int i = 0; i < m; ++i)
	{
		w[i] = u[i] + v[i];
		w[i].canonicalize();	
	}
}

void addvector(mpq_class u[], mpq_class v[], mpq_class w[], int m)
{
	for(int i = 0; i < m; ++i)
	{
		w[i] = u[i] + v[i];
		w[i].canonicalize();
	}
}

void subvector(mpz_class u[], mpz_class v[], mpz_class w[], int m)
{
	for(int i = 0; i < m; ++i)
		w[i] = u[i] - v[i];
}

void subvector(mpz_class u[], mpq_class v[], mpq_class w[], int m)
{
	for(int i = 0; i < m; ++i)
	{
		w[i] = u[i] - v[i];
		w[i].canonicalize();
	}
}

void subvector(mpq_class u[], mpq_class v[], mpq_class w[], int m)
{
	for(int i = 0; i < m; ++i)
	{
		w[i] = u[i] - v[i];
		w[i].canonicalize();
	}
}

void subvector(mpz_class u[], mpf_class v[], mpf_class w[], int m)
{
	for(int i = 0; i < m; ++i)
	{
		w[i] = u[i] - v[i];
	}
}

void subvector(mpq_class u[], mpf_class v[], mpf_class w[], int m)
{
	for(int i = 0; i < m; ++i)
	{
		w[i] = u[i] - v[i];
	}
}

void subvector(mpf_class u[], mpf_class v[], mpf_class w[], int m)
{
	for(int i = 0; i < m; ++i)
	{
		w[i] = u[i] - v[i];
	}
}

void intmult(mpz_class u[], mpz_class mult, mpz_class w[], int m)
{
	for(int i = 0; i < m; ++i)
		w[i] = mult * u[i];
}

void intmult(mpq_class u[], mpz_class mult, mpq_class w[], int m)
{
	for(int i = 0; i < m; ++i)
	{
		w[i] = mult * u[i];
		w[i].canonicalize();
	}
}

void ratmult(mpz_class u[], mpq_class mult, mpq_class w[], int m)
{
	for(int i = 0; i < m; ++i)
		w[i] = mult * u[i];
}

void ratmult(mpq_class u[], mpq_class mult, mpq_class w[], int m)
{
	for(int i = 0; i < m; ++i)
	{
		w[i] = mult * u[i];
		w[i].canonicalize();
	}
}

void fltmult(mpz_class u[], mpf_class mult, mpf_class w[], int m)
{
	for(int i = 0; i < m; ++i)
	{
		w[i] = mult * u[i];
	}
}

void fltmult(mpq_class u[], mpf_class mult, mpf_class w[], int m)
{
	for(int i = 0; i < m; ++i)
	{
		w[i] = mult * u[i];
	}
}

void fltmult(mpf_class u[], mpf_class mult, mpf_class w[], int m)
{
	for(int i = 0; i < m; ++i)
	{
		w[i] = mult * u[i];
	}
}

void gso(mpz_class B[][MAXSIZE], mpq_class G[][MAXSIZE], int n, int m)
{
	int i, j, k;
	mpq_class temp[m], proj, num ,den;
	
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < m; ++j)
			G[i][j] = B[i][j];
		for(k = 0; k < i; ++k)
		{
			num = dotp(B[i], G[k], m);
			den = dotp(G[k], G[k], m);
			
			den = 1/den;
			
			proj = num * den;
			ratmult(G[k], proj, temp, m);
			
			subvector(G[i], temp, G[i], m);
		}
	}
}

void gson(mpz_class B[][MAXSIZE], mpf_class G[][MAXSIZE], mpf_class M[][MAXSIZE], int n, int m)
{
	int i, j, k;
	mpf_class temp[m], proj, num ,den, normval;
	
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < m; ++j)
			G[i][j] = B[i][j];
		for(k = 0; k < i; ++k)
		{
			num = dotp(B[i], G[k], m);
			den = dotp(G[k], G[k], m);
			
			den = 1/den;
			
			proj = num * den;
			
			M[i][k] = proj;
			
			fltmult(G[k], proj, temp, m);
			
			subvector(G[i], temp, G[i], m);
		}
		normval = norm(G[i], m);
		mpf_sqrt(normval.get_mpf_t(), normval.get_mpf_t());
		
		for(j = 0; j < m; ++j)
			G[i][j] = G[i][j] / normval;
			
		num = dotp(B[i], G[i], m);
		den = dotp(G[i], G[i], m);
		
		den = 1/den;
		
		proj = num * den;
		
		M[i][i] = proj;
	}
	
	
}

void print(mpz_class v[], int m)
{
	for(int i = 0; i < m; ++i)
		cout<<v[i]<<" ";
	cout<<endl;
}

void print(mpq_class v[], int m)
{
	for(int i = 0; i < m; ++i)
		cout<<v[i]<<" ";
	cout<<endl;
}

void print(mpz_class M[][MAXSIZE], int n, int m)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
}

void print(mpq_class M[][MAXSIZE], int n, int m)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
}

void print(mpf_class M[][MAXSIZE], int n, int m)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
}

void swap(mpz_class v[], mpz_class u[], int m)
{
	mpz_class temp;
	for(int i = 0; i < m; ++i)
	{
		temp = v[i];
		v[i] = u[i];
		u[i] = temp;
	}
}
