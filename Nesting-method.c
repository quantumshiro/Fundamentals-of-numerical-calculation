/* 
 * Calculating p(x) = 5x^4 + 4x^3 + 3x^2 + 2^x + 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double p(double x) {
    double a[5]={5, 4, 3, 2, 1}, y;
    int n=4, k;
    y = a[0];

    for(k = 1; k<= n; k++) {
        y = y * x + a[k];
    }

    return y;
}

int main(void) {
    double x = 0.1;
    printf("p(%3.1f)=%6.4f\n", x, p(x));

    return 0;
}
