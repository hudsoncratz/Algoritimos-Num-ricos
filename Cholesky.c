#include<stdio.h>
#include <stdlib.h>
#include<math.h>


 int main(){

    int n;

    printf("Digite n: ");
    scanf("%d", &n);

    float a[n][n], L[n][n], v, soma;
    int i=0 , j=0, k=0;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("Digite o valor na matriz A[%d][%d]:\t ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }

     for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%f\t", a[i][j] );
        }
        printf("\n");
    }
    if(a[0][0] <= 0){
        printf("Matriz não é definida positiva");
        return 0;
    }
    else{
            L[0][0] = sqrt(a[0][0]);
    }
    for(j=1;j<n;j++){
        L[j][0] = a[j][0]/L[0][0];
    }
    for (k=0;k<n;k++) {
        soma = 0;
        for (j=0;j<=k-1;j++) {
            soma = soma + pow(L[k][j],2);
        }
        v = a[k][k] - soma;
        L[k][k] = sqrt(v);
        for (i=k+1;i<n;i++) {
            soma = 0;
            for (j=0;j<=k-1;j++) {
                soma = soma + L[i][j]*L[k][j];
            }
            L[i][k] = (a[i][k] - soma) / L[k][k];
        }
    }
    printf("\n" );
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%f\t", L[i][j] );
        }
        printf("\n" );
    }
    return 0;

 }
