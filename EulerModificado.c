#include <stdio.h>
#include <math.h>

double fx(double Ca, double Vy, double Vx, double m, double mi) {
    double value = sqrt(pow(Vx, 2) + pow(Vy,2));
    return -(1/m)*Ca*(value*Vx) - mi*Vx;
}

double fy(double Ca, double Vy, double Vx, double g ,double m, double mi) {
    double value = sqrt(pow(Vx, 2) + pow(Vy,2));
    return -g -(1/m)*Ca*(value * Vy) - mi*Vy;
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
    double h = 0.0001;
    double x = 0;
    double y = 0.3;
    double V0 = 100;
    double tetha =  3.14159 * 30 / 180;
    double Vx = V0 * cos(tetha);
    double Vy = V0 * sin(tetha);

    while (y > 0.0001) {
        k11 = fx(Ca,Vy, Vx, m, mi);
        k12 = fy(Ca,Vy, Vx, g, m, mi);
        k13 = gx(Vx + 0.5 * h * k11);
        k14 = gy(Vy + 0.5 * h * k12);

        t = t + 0.33 * h;

        k21 = fx(Ca,Vy+0.5*h*k12, Vx+0.5*h*k11, m, mi);
        k22 = fy(Ca,Vy+0.5*h*k12, Vx+0.5*h*k11, g, m, mi);
        k23 = gx(Vx + 0.5*h*k11);
        k24 = gy(Vy + 0.5*h*k12);

        t = t + 0.33 * h;

        k31 = fx(Ca,Vy+0.5*h*k22, Vx+0.5*h*k21, m, mi);
        k32 = fy(Ca,Vy+0.5*h*k22, Vx+0.5*h*k21, g, m, mi);
        k33 = gx(Vx+0.5*h*k21);
        k34 = gy(Vy+0.5*h*k22);

        t = t + 0.34 * h;

        k41 = fx(Ca, Vy+0.5*h*k32, Vx + 0.5*h*k31, m, mi);
        k42 = fy(Ca, Vy+0.5*h*k32, Vx + 0.5*h*k31, g, m, mi);
        k43 = gx(Vx + 0.5 * h * k31);
        k44 = gy(Vy + 0.5 * h * k32);



        Vx = Vx + h * (0.17 * k11 + 0.33 * k21 + 0.33 * k31 + 0.17 * k41);
        Vy = Vy + h * (0.17 * k12 + 0.33 * k22 + 0.33 * k32 + 0.17 * k42);
        x = x + h * (0.17 * k13 + 0.33 * k23 + 0.33 * k33 + 0.17 * k43);
        y = y + h * (0.17 * k14 + 0.33 * k24 + 0.33 * k34 + 0.17 * k44);

    }

    printf("\nAlCance: %f", x);
}
