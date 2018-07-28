//=================================
// include guard
#ifndef __FUNCTIONS_H_INCLUDED__
#define __FUNCTIONS_H_INCLUDED__

#include <iostream>
#include <stdlib.h>
#include <gmpxx.h>
#include "lattice.h"


using namespace std;

mpz_class norm(mpz_class v[], int m);
mpq_class norm(mpq_class v[], int m);

mpz_class dotp(mpz_class u[], mpz_class v[], int m);
mpq_class dotp(mpz_class u[], mpq_class v[], int m);
mpq_class dotp(mpq_class u[], mpq_class v[], int m);

void addvector(mpz_class u[], mpz_class v[], mpz_class w[], int m);
void addvector(mpz_class u[], mpq_class v[], mpq_class w[], int m);
void addvector(mpq_class u[], mpq_class v[], mpq_class w[], int m);

void subvector(mpz_class u[], mpz_class v[], mpz_class w[], int m);
void subvector(mpz_class u[], mpq_class v[], mpq_class w[], int m);
void subvector(mpq_class u[], mpq_class v[], mpq_class w[], int m);

void intmult(mpz_class u[], mpz_class mult, mpz_class w[], int m);
void intmult(mpq_class u[], mpz_class mult, mpq_class w[], int m);

void ratmult(mpz_class u[], mpq_class mult, mpq_class w[], int m);
void ratmult(mpq_class u[], mpq_class mult, mpq_class w[], int m);

void gso(mpz_class B[][MAXSIZE], mpq_class G[][MAXSIZE], int n, int m);

void print(mpz_class v[], int m);
void print(mpq_class v[], int m);
void print(mpz_class M[][MAXSIZE], int n, int m);
void print(mpq_class M[][MAXSIZE], int n, int m);

#endif
