#include<stdio.h>
#include<math.h>
#include<time.h>

int main(){
	float a, b , x, k = 0;
	float e1 = 0.001, e2 = 0.001, raiz;
	float fx, fa;

	//opcão 1
	//a = -1;
	//b = 1;

	//opcão 2
	//a = 0;
	//b = 1;

	//opcão 1
	//fb = 2.0*pow(b,3.0) - 4.0*pow(b,2.0) + 3.0*b;
	//fa = 2.0*pow(b,3.0) - 4.0*pow(b,2.0) + 3.0*b;

	//opcao 2
	//fb = cos(b) - b;
	//fa = cos(a) - a;


	if( (b - a) < e1){
        if(abs (fa) < e2){
            x = a;
        }
        else if(abs (fb) < e2){
            x = b;
        }
	}

	x = (a + b)/2;
    else
        while(abs(b-a) > precisao){
            k = k + 1.0;
            x = (a + b)/ 2;
            //opcão 1
            //fx = 2.0*pow(x,3.0) - 4.0*pow(x,2.0) + 3.0*x;
            //fa = 2.0*pow(a,3.0) - 4.0*pow(a,2.0) + 3.0*a;

            //opcao 2
            //fx = cos(x) - x;
            //fa = cos(a) - a;

            if( (fa*fx) == 0) break;
            if( (fa*fx) < 0 ){
                b = x;
            }
            else{
                a = x;
            }

        }

        printf("A raiz é: %f", x );
        printf("\nContador: %f", k);


}
