
#include <math.h>

double fy(double x) {
    double y = exp(-1.0*cos(x)) / sqrt(2.0*x + 4.0);
    return y;
}

int main () {
    double a = 0.0, b = 2.0, h = 0.0, x = 0.0, resultado = 0.0;
    int m = 100, i;

    h = (b - a) / m;
    x = a;

    resultado = (h*fy(x))/3.0;
    x = x + h;

    for (i = 1;i<m;i++) {
        if (i%2 != 0) {
            resultado = resultado + ((h*4*fy(x)) / 3.0);

        }
        else {
            resultado = resultado + ((h*2*fy(x)) / 3.0) ;
        }
        x = x + h;
    }
    resultado = resultado + ((h*fy(b)) / 3.0) ;

    printf("H: %f \nRes: %f", h, resultado);
}
