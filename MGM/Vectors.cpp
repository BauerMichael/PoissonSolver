#include "classes.h"

Vectors::Vectors(int m, Operators& O) {
    n=m;
    dim=n*n;

    vector<double> pushB;
    vector<double> pushX;
    pushB.resize(n);
    pushX.assign(n,0);
    x.assign(n,pushX);

    int k,i,j;
    double h=1.0/(double)(n+1);

    for(i=1;i<=n;i++) {
        for(j=1,k=0;j<=n;j++,k++) {
            if(i==1) {
                if (j==1) {
                    pushB[k] = O.f(h, h) + (n+1)*(n+1) * (O.g(0, h) + O.g(h, 0));
                } else if (j==n) {
                    pushB[k] = O.f(1-h, 1-h) + (n+1)*(n+1) * (O.g(1-h, 0) + O.g(1, h));
                } else {
                    pushB[k] = O.f(j*h, h) + (n+1)*(n+1) * O.g(j*h, 0);
                }
            } else if(i>1 && i<n) {
                if (j == 1) {
                    pushB[k] = O.f(h, i*h) + (n+1)*(n+1) * O.g(0, i*h);            
                } else if (j == n) {
                    pushB[k] = O.f(1-h, i*h) + (n+1)*(n+1) * O.g(1, i*h);
                } else {
                    pushB[k] = O.f(j*h, i*h);
                }
            } else {
                if (j==1) {
                    pushB[k] = O.f(h, 1-h) + (n+1)*(n+1) * (O.g(h, 1)+O.g(0, 1-h));
                } else if (j==n) {
                    pushB[k] = O.f(1-h, 1-h) + (n+1)*(n+1) * (O.g(1-h, 1)+O.g(1, 1-h));
                } else {
                    pushB[k] = O.f(j*h, 1-h) + (n+1)*(n+1) * O.g(j*h, 1);
                }
            }
        }
        b.push_back(pushB);
    }
}

Vectors::~Vectors() {
    vector<vector<double> >().swap(x);
    vector<vector<double> >().swap(b);
}

void Vectors::MatrixVectorMultiplyer(Matrix& M) {
    int dim=x.size();
    int n=sqrt(dim);
    for (int i=0;i<dim;i++) {
        b[i]+=x[i]*M.Get(i,i);
        if (i<(dim-n)) {
            b[i]+=x[i+n]*M.Get(i,i+n);
        } 
        if (i>=n) {
            b[i]+=x[i-n]*M.Get(i,i-n);
        }
        if (i%n!=0) {
            b[i]+=x[i-1]*M.Get(i,i-1);
            b[i-1]+=x[i]*M.Get(i-1,i);
        }
    }
}

void Vectors::PrintVector() {
    if(dim < 20)
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                printf("%f ", x[i][j]);
            }
        }
    printf("\n");
}

void Vectors::WriteToFile() {
    int i,j,k,m;
    double h=1.0/(double)(n+1);
    FILE *file;
    file=fopen("./Plot/plot.txt", "w");
    k=0;
    m=n+1;
    if(file==NULL)
        printf("ERROR: Could not open file!\n");
    for(i=0;i<m;i++) {
        for(j=0;j<m;j++) {
            if(i==0) {
                fprintf(file, "%f %d %f\n", (double)j/(double)n,i,O.g(j*h,i));
            } else if(i!=0) {
                if(j==0) {
                    fprintf(file, "%d %f %f\n", j,(double)i/(double)n,O.g(j,i*h));
                } else if(j!=0){
                    fprintf(file, "%f %f %f\n", (double)j/(double)n,(double)i/(double)n,x[k]);
                    k++;
                }
            }
        }
        fprintf(file, "\n");
    }
    fclose (file);
}

MGMVectors::MGMVectors(int m, Operators& O) {
    n=m;
    dim=n*n;

    vector<double> pushB;
    vector<double> pushX;
    pushB.resize(n);
    pushX.assign(n,0);
    x.assign(n,pushX);

    int k,i,j;
    double h=1.0/(double)(n+1);

    for(i=1;i<=n;i++) {
        for(j=1,k=0;j<=n;j++,k++) {
            if(i==1) {
                if (j==1) {
                    pushB[k] = O.f(h, h) + (n+1)*(n+1) * (O.g(0, h) + O.g(h, 0));
                } else if (j==n) {
                    pushB[k] = O.f(1-h, 1-h) + (n+1)*(n+1) * (O.g(1-h, 0) + O.g(1, h));
                } else {
                    pushB[k] = O.f(j*h, h) + (n+1)*(n+1) * O.g(j*h, 0);
                }
            } else if(i>1 && i<n) {
                if (j == 1) {
                    pushB[k] = O.f(h, i*h) + (n+1)*(n+1) * O.g(0, i*h);            
                } else if (j == n) {
                    pushB[k] = O.f(1-h, i*h) + (n+1)*(n+1) * O.g(1, i*h);
                } else {
                    pushB[k] = O.f(j*h, i*h);
                }
            } else {
                if (j==1) {
                    pushB[k] = O.f(h, 1-h) + (n+1)*(n+1) * (O.g(h, 1)+O.g(0, 1-h));
                } else if (j==n) {
                    pushB[k] = O.f(1-h, 1-h) + (n+1)*(n+1) * (O.g(1-h, 1)+O.g(1, 1-h));
                } else {
                    pushB[k] = O.f(j*h, 1-h) + (n+1)*(n+1) * O.g(j*h, 1);
                }
            }
        }
        b.push_back(pushB);
    }
}

MGMVectors::~MGMVectors() {
    vector<vector<double> >().swap(x);
    vector<vector<double> >().swap(b);
}

void MGMVectors::PrintVector() {
    if(dim < 20) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                printf("%f ", x[i][j]);
            }
        }
    }
    printf("\n");
}

// void MGMVectors::WriteToFile(Operators& O) {
//     int i,j,k,m;
//     double h=1.0/(double)(n+1);
//     FILE *file;
//     file=fopen("./Plot/plot.txt", "w");
//     k=0;
//     m=n+1;
//     if(file==NULL)
//         printf("ERROR: Could not open file!\n");
//     for(i=0;i<m;i++) {
//         for(j=0;j<m;j++) {
//             if(i==0) {
//                 fprintf(file, "%f %d %f\n", (double)j/(double)n,i,O.g(j*h,i));
//             } else if(i!=0) {
//                 if(j==0) {
//                     fprintf(file, "%d %f %f\n", j,(double)i/(double)n,O.g(j,i*h));
//                 } else if(j!=0){
//                     fprintf(file, "%f %f %f\n", (double)j/(double)n,(double)i/(double)n,x[k]);
//                     k++;
//                 }
//             }
//         }
//         fprintf(file, "\n");
//     }
//     fclose (file);
// }