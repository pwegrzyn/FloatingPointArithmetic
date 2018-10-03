#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10000000
#define VAL 0.12453f

float kahan(float *tab, int i) {
    float sum = 0.0f;
    float c = 0.0f;
    int j;
    for(j = 0; j < i; j++) {
        float y = tab[j] - c;
        float t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
}

int main(void) {
    static float tab[MAX];
    int i;
    for(i = 0; i < MAX; i++) {
        tab[i] = VAL;
    }
    float sum = kahan(tab, MAX);
    float product = MAX * VAL;
    printf("sum = %f\n", sum);
    printf("prod = %f\n", product);
    printf("error = %f\n", fabs(product - sum));
    printf("relative error = %f\n", fabs((product - sum)) / product);
}