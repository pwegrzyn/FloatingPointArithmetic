#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10000000
#define VAL 0.12453f

float sum_rec(float *tab, int i) {
    if(i == 0) return 0;
    if(i == 1) return tab[0];
    int mid = i / 2;
    int rsize = i - mid;
    float lsum = sum_rec(tab, mid);
    float rsum = sum_rec(tab + mid, rsize);
    return lsum + rsum;
}

int main(void) {
    static float tab[MAX];
    int i;
    for(i = 0; i < MAX; i++) {
        tab[i] = VAL;
    }
    float sum = sum_rec(tab, MAX);
    float product = MAX * VAL;
    printf("sum = %f\n", sum);
    printf("prod = %f\n", product);
    printf("error = %f\n", fabs(product - sum));
    printf("relative error = %f\n", fabs((product - sum)) / product);
}