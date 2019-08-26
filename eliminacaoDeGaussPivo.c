#include<stdio.h>
#include <stdlib.h>
#include<math.h>


 int main(){

 	int n;

    printf("Digite n: ");
    scanf("%d", &n);

 	float a[n][n], b[n], x[n], m, s, max, aux;
 	int i=0 , j=0, k, ind;

     for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("Digite o valor na matriz A[%d][%d]:\t ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
        printf("Digite o valor vetor solucao B[%d]:\t ", i+1);
        scanf("%f", &b[i]);
    }

	 for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%f\t", a[i][j] );
        }
        printf(" = %f\t ", b[i] );
        printf("\n");
    }

    //PIVOTAMENTO
    for(j=0;j<n;j++){
        ind = j;
        max = fabs(a[j][j]);
        for(k=j+1;k<n;k++){
            if(fabs(a[k][j]) > max){
                max = fabs(a[i][k]);
                ind = k;
            }
        }
        if(ind != j){
            for(k=0;k<n;k++){
                aux = a[j][k];
                a[j][k] = a[ind][k];
                a[ind][k] = aux;
                aux = b[j];
                b[j] = b[ind];
                b[ind] = aux;
            }
        }
    }

    //ELIMINAÇÃO
    for(k=0;k<(n-1);k++){
        for(i=(k+1);i<n;i++){
            m = a[i][k] / a[k][k];
            a[i][k] = 0;
            for(j=(k+1);j<n;j++){
                a[i][j] = a[i][j] - (m*a[k][j]);
            }
            b[i] = b[i] - (m* b[k]);
        }
    }

    printf("\n");

    //RESOLUÇÃO DO SISTEMA
    x[n-1] = b[n-1] / a[n-1][n-1];

    for(k=(n-2);k>=0;k--){
        s=0;
        for(j=(k+1);j<n;j++){
            s = s + (a[k][j]*x[j]);
        }

        x[k] = (b[k] - s) / a[k][k];
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){

        }
        printf("%f\t ", x[i] );
        printf("\n");
    }

}
