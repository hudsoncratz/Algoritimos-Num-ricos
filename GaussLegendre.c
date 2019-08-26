#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct peso {
    double *A;
    double *T;
}typedef Peso;

double function(double x){
    return 2*pow(x,3) + 3*pow(x,2) + 6*x + 1;
}

Peso pesAbs(int n){
    Peso P;
    int i, j, k;
    int m = floor((n+1)*0.5);
    double z, z1, p1, p2, p3, pp;
    P.A = (double*)malloc(n*sizeof(double));
    P.T = (double*)malloc(n*sizeof(double));

    for(i=1;i<=m;i++){
        z = cos(M_PI*((i-0.25)/(n+0.5)));
        z1 = 100;

        while(fabs(z-z1) > pow(10,-15)){
            p1 = 1.0;
            p2 = 0.0;
            for(j=1 ; j<=n ; j++ ){
                p3 = p2;
                p2 = p1;
                p1 = ((2*j-1) * z * p2 - (j-1) * p3) / j;
            }
            pp = n*(z*p1-p2) /(pow(z,2)-1);
            z1 = z;
            z = z1 - (p1/pp);
        }
        k = m + 1 - i;
        P.T[i]  = z;
        P.A[i] = (2.0 / ((1 - pow(z,2)) * pow(pp,2)));
    }
    return P;
}

int sign(double x){
    if(x < 0.0) return -1;
    if(x > 0.0) return 1;
    return 0;
}

double gaussLegendre(double a, double b, int n, double *T, double *A){
    int i, k;
    double integ = 0.0;
    double c, c1, c2, t, x, y;
    double e1 = (b-a) * 0.5;
    double e2 = (b+a) * 0.5;

    if(n%2 == 0){
        c1 = 1.0;
        c2 = 0.5;
    }else{
        c1 = 0.0;
        c2 = 1.0;
    }

    for(i=1; i<=n; i++){
        k = floor(i - 0.5 * (n+1) + sign(i - 0.5 * (n + c1)) * c2);
        t = sign(k) * T[abs(k)];
        x = (e1 * t) + e2;
        y = function(x);
        c = A[abs(k)];
        integ = integ + c * y;
    }
    integ = e1 * integ;
    return integ;
}

int main(){
    double result;
    Peso P;

    int n = 2;
    double intervA = 1;
    double intervB = 5;

    P = pesAbs(n);
    result = gaussLegendre(intervA,intervB,n,P.T, P.A);
    printf("\nResultado: %.3f",result);
    return 0;
}
