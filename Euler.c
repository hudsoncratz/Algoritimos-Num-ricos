#include <stdio.h>
#include <math.h>

double fx(double Ca, double Vy, double Vx, double m, double mi) {
    double value = sqrt(pow(Vx, 2) + pow(Vy,2));
    return -(1/m) *Ca*(value*Vx) -mi*Vx;
}

double fy(double Ca, double Vy, double Vx, double g ,double m, double mi) {
    double value = sqrt(pow(Vx, 2) + pow(Vy,2));
    return -g -(1/m)*Ca*(value*Vy) - mi*Vy;
}

double gx(double Vx) {
    return Vx;
}

double gy(double Vy) {
    return Vy;
}


int main () {
    double m = 0.01;
    double Ca = 0.0001;
    double mi = 18.68*pow(10,-6);
    double g = 9.8;

    double t = 0;
    double h = 0.0001;
    double x = 0;
    double y = 0.3;
    double V0 = 100;
    double tetha =  3.14159 * 30 / 180;
    double Vx = V0 * cos(tetha);
    double Vy = V0 * sin(tetha);

    while (y > 0.0001) {
        t = t + h ;
        Vx = Vx + h * fx( Ca, Vy, Vx, m ,mi) ;
        Vy = Vy + h * fy( Ca, Vy, Vx, g, m ,mi) ;
        x  =  x + h * gx( Vx ) ;
        y  =  y + h * gy( Vy ) ;
    }

    printf("Alcance: %f", x);




    return 0;
}

