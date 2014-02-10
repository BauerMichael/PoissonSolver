#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstdio>
#include <vector>
using namespace std;

double f(double,double);
double g(double,double);
vector<double> operator-(const vector<double>&,const vector<double>&);
void operator+=(vector<double>&,const vector<double>&);
vector<double> operator*(double, vector<double>);
double operator|(const std::vector<double>&,const std::vector<double>&);

class Matrix {
    private:
        int dim;
        int n;
        double diagonal;
        double tridiagonal;
        double identity;
    public:
        Matrix(int,double,double,double);
        ~Matrix();
        void PrintMatrix();
        vector<double> operator*(const vector<double>&);
};

class Vector {
    private:
        int n;
        double h;
    public:
        Vector(int);
        ~Vector();
        vector<double> x;
        vector<double> b;
        vector<double> solved;
        void PrintVector(const vector<double>&);
        void WriteToFile(const vector<double>&);
};

class Algorithms {
	private:
		int dim;
		int n;
        double h;
	public:
		Algorithms(int);
		~Algorithms();
        void JacobiRelaxation(Matrix&,vector<double>&,const vector<double>&,int);
        void Restriction(const vector<double>&,vector<double>&,int);
        void Interpolation(const vector<double>&,vector<double>&,int);
        vector<double> MultiGridAlgorithm(Matrix&,vector<double>&,const vector<double>&,int);
        void MultiGridMethod(Matrix&,vector<double>&,const vector<double>&,const vector<double>&);
};

#endif