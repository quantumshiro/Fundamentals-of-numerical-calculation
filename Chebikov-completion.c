#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double p(double x, int n, double xi[], double b[]) {
    double y;
    int l;
    y = b[n];
    
    for(l = n - 1; l >= 0; l--) y = (x - xi[l]) * y + b[l];

    return y;
}

int NewtonCoef(double xi[], int m, double f(double), double b[]) {
    int n, l;

    for(n = 0; n <= m; n++) {
        b[n] = f(xi[n]);

        for(l = 0; l <= n - 1; l++) {
            b[n] = (b[n] - b[l]) / (xi[n] - xi[l]);
        }
    }
    return 0;
}

double f(double x) {
    return exp(x);
}

int main(void) {
    int i, m, np;
    double  xi[8], b[8], dt, x, dx, y, Pi;

    m = 7;
    Pi = atan(1) * 4;
    dt = Pi/(m + 1);;

    for(i = 0; i <= m; i++) xi[i] = 0.5 * cos((i + 0.5) * dt);

    NewtonCoef(xi, m, f, b);

    printf("degree=%d\n", m);
    np = 10;
    dx = 1.0/np;
    
    for(i = 0; i <= np; i++) {
        x = -0.5 + i * dx;
        y = p(x, m, xi, b);

        printf("p(%4.1f)=%17.10e error=%9.2e\n", x, y, y - exp(x));
    }
    return 0;
}
