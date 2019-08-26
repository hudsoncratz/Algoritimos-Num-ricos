#include<stdio.h>
#include <math.h>

double fy(double x) {
    double y = exp(-1*cos(x)) / sqrt(2*x + 4);
    return y;

}

int main () {
    double a = 0.0, b = 2.0, h, x, resultado;
    int m = 120, i=0;

    h = (b - a) / m;
    x = a;

    resultado = (3 * h * fy(x)) / 8;
    x = x + h;

    for (i = 1;i<m;i++) {
        if (i % 3 == 0) {
            resultado = ((3 * h * 2 * fy(x)) / 8) + resultado;
        }
        else {
            resultado = ((3 * h * 3 * fy(x)) / 8) + resultado;
        }
        x = x + h;
    }
    resultado = ((3 * h * fy(b)) / 8) + resultado;

    printf("H: %f \nRes: %f", h, resultado );


}
