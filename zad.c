#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 10000000
#define VAL 0.12453f

int main(void) {
    FILE *file;
    file = fopen("error.csv", "w");
    if(file == NULL) {
        fprintf(stderr, "Error while opening data file\n");
        exit(1);
    }
    static float tab[MAX];
    int i;
    for(i = 0; i < MAX; i++) {
        tab[i] = VAL;
    }
    float sum = 0.0;
    for(i = 0; i < MAX; i++) {
        sum += tab[i];
        if(i % 50000 == 0 && i) {
            float temp_prod = VAL * i;
            printf("error on %dth iteration = %f ", i, fabs(temp_prod - sum));
            printf("(relative error = %f)\n", fabs((temp_prod - sum) / temp_prod));
            char buffer[64];
            sprintf(buffer, "%d,%f\n", i, fabs(temp_prod - sum));
            fwrite(buffer, 1, strlen(buffer), file);
        }
    }
    float product = MAX * VAL;
    printf("sum = %f\n", sum);
    printf("prod = %f\n", product);
    printf("error = %f\n", fabs(product - sum));
    printf("relative error = %f\n", fabs((product - sum)) / product);
    fclose(file);
}