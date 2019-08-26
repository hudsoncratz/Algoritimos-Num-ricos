#include <stdio.h>
#include <math.h>

float funcao1 (float x){
	float fx;

	fx = cos(x) - x;
	return fx;
}

float Dfuncao1 (float x){
	float Dfx;

	Dfx = -sin(x) - 1;
	return Dfx;
}

int main(){

	float x, fx, Dfx, precisao = 0.001, k = 1.0;


	printf ("n \t =========================================================\n ") ;
	printf ("\n \t ================== Metodo da Bissecao ===================\n ") ;
	printf ("\n \t =========================================================\n ") ;
	printf ("\n \t k |     x    |  f ( x )    \n ") ;

	x = 0.01;
	fx = funcao1(x);
	Dfx = Dfuncao1(x);
    printf ("\n \t %f | %f | %f  \n ", k, x, fx ) ;
	while(fabs(fx) > precisao){

		x = x - (fx / Dfx);
		fx = funcao1(x);
		Dfx = Dfuncao1(x);
		k = k + 1.0;

		printf ("\n \t %f | %f | %f  \n ", k, x, fx ) ;
	}

	printf ("\n \t Raiz : %f \n ", x ) ;

}
