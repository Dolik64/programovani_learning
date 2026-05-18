//pole_double

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 37, m = 5;
    double** a = (double **) malloc(sizeof(double *) * m);
    for (size_t i = 0; i < m; ++i){
        a[i] = (double *) malloc(sizeof(double) * n);
    }
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j){
            a[i][j] = 3.14;
        }
    }
    for (size_t i = 0; i < m; ++i) {
        free(a[i]);
    }
    free(a);
}
