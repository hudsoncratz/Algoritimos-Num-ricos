#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#define m 3
#define n 4

float Function (int i,float x) {
    if(i == 0) return(pow(x,2));
    if(i == 1) return(x);
    //(i == 2)
    else  return(1);

}

void FunctionI_J(float f[m][m],float x[n]) {
    int i,j,k;
    float soma;
    for(i=0;i<=m-1;i++) {
        for(j=i;j<=m-1;j++) {
            soma=0;
            for(k=0;k<=n-1;k++) {
                soma=soma+Function(i,x[k])*Function(j,x[k]);
            }
            f[i][j]=soma;
            f[j][i]=f[i][j];
        }
    }
}

void VetB(float b[m],float x[n],float y[n]) {
    int i,k;
    float soma;
    for(i=0;i<=m-1;i++) {
        soma = 0;
        for(k=0;k<=n-1;k++) {
            soma = soma + y[k]*Function(i,x[k]);
        }
        b[i] = soma;
    }
}

void solve(float f[m][m],float b[m]) {
    int indice,k,i,j;
    float maxValue,s;
    float aux, razao, x[m];
    for (k=0;k<m;k++) {
        indice = k;
        maxValue = f[k][k];
        for (i=k+1;i<m;i++) {
            if (maxValue < f[i][k]) {
                maxValue = f[i][k];
                indice = i;
            }
        }
        for (j=0;j<m;j++) {
            aux = f[k][j];
            f[k][j] = f[indice][j];
            f[indice][j] = aux;
        }
        aux = b[k];
        b[k] = b[indice];
        b[indice] = aux;
    }

    i = 0,j = 0,k = 0;

    //Eliminação

    while (k < m) {
        i = k + 1;
        while (i < m) {
            razao = f[i][k] / f[k][k];
            f[i][k] = 0.0;
            j = k + 1;
            while (j < m) {
                f[i][j] = f[i][j] - razao*f[k][j];
                j++;
            }
            b[i] = b[i] - razao*b[k];
            i++;
        }
        k++;
    }

    x[m-1] = b[m-1] / f[m-1][m-1];
    k = m - 2;

    //Resolução

    while (k >= 0) {
        s = 0;
        j = k + 1;
        while (j < m) {
            s = s + f[k][j]*x[j];
            j++;
        }
        x[k] = (b[k] - s) / f[k][k];
        k--;
    }

    printf("Resultado: \n");
    i = 0;

    //Resultado

    while (i < m) {
        printf("a[%d]: %f\n", i+1, x[i]);
        i++;
    }
}

int main() {
    float x[n]={-2,-1,1,2},
            y[n]={0,2,2,10}, //(-2,0), (-1,2), (1,2), (2,10)
            f[m][m],b[m];

    FunctionI_J(f,x);
    VetB(b,x,y);
    solve(f,b);

    return 0;
}


