#include<stdio.h>
#include <stdlib.h>
#include<math.h>


 int main(){
 	int m;
 	printf("Digite a prdem do polinomio:");
 	scanf("%d", &m);

	float x[m],y[m],z, c, d,r;
	int i,j;
	for(i=0;i<m;i++){
		printf("Digite o valor de x[%d]: ", i+1);
		scanf("%f", &x[i]);
	}
	for(i=0;i<m;i++){
		printf("Digite o valor de y[%d]: ", i+1);
		scanf("%f", &y[i]);
	}
		printf("Digite o valor o valor de z: ");
		scanf("%f", &z);


	for(i=0;i<m;i++){
		c = 1.0;
		d = 1.0;
		for(j=0;j<m;j++){
			if(i!=j){
				c = c*(z-x[j]);
				d = d*(x[i] - x[j]);
			}
		}
		r = r + y[i]*c/d;
	}

	printf("O valor de r é: %f", r );


}
