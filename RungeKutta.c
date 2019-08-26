
#include <stdio.h>
#include <math.h>

double fx(double Ca, double Vy, double Vx, double m, double mi) {
    double value = sqrt(pow(Vx, 2) + pow(Vy,2));
    return -(1/m)*Ca*(value* Vx) - mi*Vx;
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
    double k11, k12, k13,k14,k21,k22,k23,k24,k31,k32,k33,k34, k41,k42,k43,k44;
    double m = 0.01;
    double Ca = 0.0001;
    double mi = 18.68*pow(10,-6);
    double g = 9.8;

    double t = 0;
    double h = 0.001;
    double x = 0;
    double y = 0.3;
    double V0 = 100;
    double tetha =  3.14159 * 30 / 180;
    double Vx = V0 * cos(tetha);
    double Vy = V0 * sin(tetha);

    while (y > 0.0001) {
        k11 = h * fx(Ca,Vy, Vx, m, mi);
        k12 = h * fy(Ca,Vy, Vx, g, m, mi);
        k13 = h * gx(Vx);
        k14 = h * gy(Vy);

        t = t + 0.5 * h ;

        k21  = h * fx( Ca, Vy + 0.5 * k12, Vx + 0.5 * k11, m, mi ) ;
        k22  = h * fy( Ca, Vy + 0.5 * k12, Vx + 0.5 * k11, g, m, mi ) ;
        k23  = h * gx( Vx + 0.5 * k11 ) ;
        k24  = h * gy( Vy + 0.5 * k12 ) ;

        k31  = h * fx( Ca, Vy + 0.5 * k22, Vx + 0.5 * k21, m, mi ) ;
        k32  = h * fy( Ca, Vy + 0.5 * k22, Vx + 0.5 * k21, g, m, mi ) ;
        k33  = h * gx( Vx + 0.5 * k21 ) ;
        k34  = h * gy( Vy + 0.5 * k22 ) ;

        t = t + 0.5 * h ;

        k41  = h * fx( Ca, Vy + k32, Vx + k31, m, mi ) ;
        k42  = h * fy( Ca, Vy + k32, Vx + k31, g, m, mi ) ;
        k43  = h * gx( Vx + k31 ) ;
        k44  = h * gy( Vy + k32 ) ;

        Vx = Vx + (1.0/6.0) * ( 1.0 * k11 + 2.0 * k21 + 2.0 * k31 + 1.0 * k41 ) ;
        Vy = Vy + (1.0/6.0) * ( 1.0 * k12 + 2.0 * k22 + 2.0 * k32 + 1.0 * k42 ) ;
        x  =  x + (1.0/6.0) * ( 1.0 * k13 + 2.0 * k23 + 2.0 * k33 + 1.0 * k43 ) ;
        y  =  y + (1.0/6.0) * ( 1.0 * k14 + 2.0 * k24 + 2.0 * k34 + 1.0 * k44 ) ;

    }
    printf("\nAlCance: %f", x);
    
}
