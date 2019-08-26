#include<stdio.h>
#include <stdlib.h>
#include<math.h>


 int main(){

 	int n;

    printf("Digite n: ");
    scanf("%d", &n);

    float a[n][n], l[n][n], u[n][n], soma;
    int i=0 , j=0, k=0;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            l[i][j]=0;
            u[i][j]=0;
        }
    }
    for(j=0;j<n;j++){
    	l[j][j] = 1;
    }
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
        printf("\n" );
    }
    for(j=0;j<n;j++){
    	u[0][j] = a[0][j];
    	if(u[0][0]==0){
            printf("Fatoracao impossivel");
            break;
    	}
    }

    for(i=1;i<n;i++){
    	l[i][0]= a[i][0]/u[0][0];
    }
    for(i=1;i<n-1;i++){
    	soma=0;
    	for(k=0;k<=i-1;k++){
    	soma = soma + l[i][k]*u[k][i];
    	u[i][i] = a[i][i]-soma;
            if(u[i][i]==0){
                printf("Fatoracao impossivel");
                break;
            }
    	}
    	for(j=i+1;j<n;j++){
    		soma = 0;
    		for(k=0;k<=i-1;k++){
    			soma = soma + l[i][k]*u[k][k];
    			u[i][j] = (1/l[i][i])*(a[i][j]-soma);
    		}
    		soma = 0;
    		for (k=0;k<=i-1;k++){
    			soma = soma + l[j][k]*u[k][i];
    			l[j][i] = (1/u[i][i])*(a[j][i]-soma);
    		}
    	}
    	soma = 0;
    	for(k=0;k<n-1;k++){
    		soma = soma + l[n-1][k]*u[k][n-1];
    		u[n-1][n-1] = a[n-1][n-1] - soma;
    	}
        printf("\n\n" );
    	for(i=0; i<n; i++){
        	for(j=0; j<n; j++){
            	printf("%f\t", l[i][j] );
        	}
        	printf("\n" );
    	}
        printf("\n\n" );
    	for(i=0; i<n; i++){
        	for(j=0; j<n; j++){
            	printf("%f\t", u[i][j] );
        	}
        	printf("\n" );
    	}
        printf("\n\n" );
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                printf("%f\t", a[i][j] );
            }
            printf("\n" );
        }

    }

}
