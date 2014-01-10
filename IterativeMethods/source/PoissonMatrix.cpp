#include "classes.h"

PoissonMatrix::PoissonMatrix(int n) {
	this->n=n;
	this->dim=n*n;
	this->diagonal=4.0*(n+1)*(n+1);
	this->tridiagonal=-1.0*(n+1)*(n+1);
	this->identity=tridiagonal;

    vector<int> tmp;
    tmp.assign(5,-1);
    for(int i=0;i<dim;i++) {
        if(i<n) {
            if(i==0) {
                tmp[0]=i;
                tmp[1]=i+1;
                tmp[2]=i+n;
                tmp[3]=-1;
                tmp[4]=-1;
            } else if(i%n!=n-1 && i!=0) {
                tmp[0]=i-1;
                tmp[1]=i;
                tmp[2]=i+1;
                tmp[3]=i+n;
                tmp[4]=-1;
            } else {
                tmp[0]=i-1;
                tmp[1]=i;
                tmp[2]=i+n;
                tmp[3]=-1;
                tmp[4]=-1;
            }
        } else if(i>=n && i<dim-n) {
            if(i%n==0) {
                tmp[0]=i-n;
                tmp[1]=i;
                tmp[2]=i+1;
                tmp[3]=i+n;
                tmp[4]=-1;
            } else if(i%n==n-1) {
                tmp[0]=i-n;
                tmp[1]=i-1;
                tmp[2]=i;
                tmp[3]=i+n;
                tmp[4]=-1;
            } else {
                tmp[0]=i-n;
                tmp[1]=i-1;
                tmp[2]=i;
                tmp[3]=i+1;
                tmp[4]=i+n;
            }
        } else if(i>=dim-n) {
            if(i==dim-1) {
                tmp[0]=i-n;
                tmp[1]=i-1;
                tmp[2]=i;
                tmp[3]=-1;
                tmp[4]=-1;
            } else if(i%n!=0 && i!=dim-1) {
                tmp[0]=i-n;
                tmp[1]=i-1;
                tmp[2]=i;
                tmp[3]=i+1;
                tmp[4]=-1;
            } else {
                tmp[0]=i-n;
                tmp[1]=i;
                tmp[2]=i+1;
                tmp[3]=-1;
                tmp[4]=-1;
            }
        }
        HashMatrix.push_back(tmp);
    }
}

PoissonMatrix::~PoissonMatrix() {
    vector<vector<int> >().swap(HashMatrix);
}

int PoissonMatrix::Size() {
	return dim;
}

double PoissonMatrix::Get(int i,int j) {
	if(i==j) {
		return diagonal;
	} else if(j==(i+1) && i%n!=(n-1)) {
		return tridiagonal;
	} else if(j==(i-1) && i%n!=0) {
		return tridiagonal;
	} else if(j==(i+n)) {
		return identity;
	} else if(j==(i-n)) {
		return identity;
	} else {
		return 0.0;
	}
}

void Matrix::PrintMatrix() {
	if(Size()>25){
		printf("Couldn't print Matrix! Dimension is too high.\n");
	} else {
		for(int i=0;i<Size();i++) {
			for(int j=0;j<Size();j++) {
				printf(" %.2f ",Get(i,j));
			}
			printf("\n");
		}
		printf("\n");
	}
}