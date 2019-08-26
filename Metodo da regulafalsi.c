#include <stdio.h>
#include <math.h>

int main(){

	float a, b, x, fa, fb, fx, e1 = 0.001, e2 = 0.001, k = 1.0;

	printf ("\n \t =========================================================\n ") ;
    printf ("\n \t ================= Metodo Regula-Falsi ===================\n ") ;
    printf ("\n \t =========================================================\n ") ;
    printf ("\n \t k |    a     |     b    |  (b - a) |     x    |     fx   |     fa   |   fb      \n ") ;

	//opcao 1
	a = -1.0;
	b = 1.0;

	//opcao 2
	//a = 0.0;
	//b = 1.0;

	//opcao 1
    fa = 2*pow(a,3.0) - 4*pow(a,2.0) + 3*a;
    fb = 2*pow(b,3.0) - 4*pow(b,2.0) + 3*b;


    //opcao 2
	//fa = cos(a) - a;
	//fb = cos(b) - b;


	x = (a*fb - b*fa)/(fb - fa);

    //opcao 1
    fx = 2*pow(x,3.0) - 4*pow(x,2.0) + 3*x;

    //opcao 2
    fx = fx = cos(x) - x;
	if( (b-a) < e1){
        if(fabs (fa) < e2 || fabs (fb) < e2) {
            x = a;
        }
        k=1.0;
	}
    else{
        printf ("\n \t %f | %f | %f | %f | %f | %f | %f | %f  \n ", k, a, b, ( b - a ), x, fx , fa , fb ) ;
        while( (fabs(b-a) > e1) && (fabs(fx) > e1)){

            k = k + 1.0;

            //opcao 1
            fa = 2*pow(a,3.0) - 4*pow(a,2.0) + 3*a;
            fb = 2*pow(b,3.0) - 4*pow(b,2.0) + 3*b;

            //opcao 2
            //fa = cos(a) - a;
            //fb = cos(b) - b;

            x = (a*fb - b*fa)/(fb - fa);

            //opcao 1
            fx = 2*pow(x,3.0) - 4*pow(x,2.0) + 3*x;

            //opcao 2
            //fx = cos(x) - x;



            if (fa*fx == 0) break;
            if (fa*fx > 0){
                a = x;
            }
            else {
                b = x;
            }

            printf ("\n \t %f | %f | %f | %f | %f | %f | %f | %f  \n ", k, a, b, ( b - a ), x, fx , fa , fb ) ;

        }
    }

	printf("A raiz é: %f", x );
	printf("\nContador: %f", k);


}
