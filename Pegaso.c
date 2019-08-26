#include <stdio.h>
#include <math.h>

float funcao1 (float z){
	float f;
	f = 2*pow(z,3) - cos(z+1) - 3;
	return f;
}

int main(){

	float a, b, x, fa, fb, fx, precisao = 0.001, k = 1.0, interMax, del;
	float raiz, CondErro;
	a = -1;
	b = 2;

	fa = funcao1(a);
	fb = funcao1(b);
	x = b;
	fx = fb;

	printf ("\n \t =========================================================\n ") ;
	printf ("\n \t ==================== Metodo Pegasus =====================\n ") ;
	printf ("\n \t =========================================================\n ") ;
	printf ("\n \t k |    a     |     b    |  (b - a)  |     x    |  f ( x )    \n ") ;

	printf ("\n \t %f | %f | %f | %f | %f | %f  \n ", k, a, b, ( b - a ), x, fx ) ;

	while( fabs (a-b)> precisao && fabs(fx) > precisao){

		del= (-fx/(fb - fa))*(b - a);
		x = x + del;
		fx = funcao1(x);

		if(fx*fb < 0){
			a = b;
			fa = fb;

		}
		else{
			fa = fa*(fb/(fb + fx));
		}
		b = x;
		fb = fx;
		k = k + 1.0;
		printf ("\n \t %f | %f | %f | %f | %f | %f  \n ", k, a, b, ( b - a ), x, fx ) ;
	}
	raiz = x;
	printf ("\n \t Raiz : %f \n ", x);
	printf("\nContador: %f", k);
	}
