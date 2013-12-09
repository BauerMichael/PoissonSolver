#include "classes.h"

int main(int argc, char const *argv[]) {
    int arg,n;//,m;
    if (argc > 1) {
        arg = atoi(&*argv[1]);
    } else {
        arg = 8;
    }
    n=arg-1;
    //m=n-1;

    PoissonMatrix A(n);
    LowerMatrix L(n);
    UpperMatrix U(n);
    PoissonVector P(n);
    MGMVector M(n);
    PoissonOperators O;
    Algorithms Run;

    //Run.InitHashMatrix(n);

    printf("Started\n");
    double time,start=0.0,end=0.0;
    start = clock();

    //Run.LU(A,L,U,O);
    //Run.incompleteLU(A,L,U,O);
    //Run.incompleteCholesky(A,L,U,O);
    //Run.modifiedIncompleteLU(A,L,U,O);

    //Run.JacobiMethod(A,O,V.x,V.b);
    //Run.GaussSeidelMethod(A,O,V.x,V.b);
    //Run.SORMethod(A,O,V.x,V.b);
    //Run.SSORMethod(A,O,V);
    //Run.CG(A,O,V);
    //Run.PCG(A,O,L,U,V);
    //Run.MultiGridMethod(V.x,V.b,n,O);

    end = clock();
    time=(end-start)/CLOCKS_PER_SEC;
    printf("%f\n", time);

    vector<vector<double> > Try;
    vector<double> it;
    it.assign(2,5);
    Try.assign(2,it);

    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            printf("%f ", Try[i][j]);
        }
    }
    printf("\n");

    //A.PrintMatrix();
    //L.PrintMatrix();
    //U.PrintMatrix();

    V.PrintVector();
    Vmgm.PrintVector();
    //V.WriteToFile(O);

    return EXIT_SUCCESS;
}