#include<stdio.h>
#include <stdlib.h>
#include<math.h>


 int main(){
 	int m;
 	printf("Digite a prdem do polinomio:");
 	scanf("%d", &m);

	float x[m],y[m],Dely[m],z, r;
	int i,j, k;
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
		Dely[i] = y[i];
	}
	for(k=0;k<m;k++){
		for(i=m-1;i>k;i--){
			Dely[i] = (Dely[i]-Dely[i-1])/(x[i]-x[i-k-1]);
		}
	}

	r = Dely[m-1];
	for (i=m-2;i>=0;i--){
		r = r*(z-x[i])+Dely[i];
	}
	printf("O valor de r e: %f", r );


}
