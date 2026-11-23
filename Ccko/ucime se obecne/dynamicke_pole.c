//dynamicke_pole

#include <stdio.h>
#include <stdlib.h>

void print_array (int a[], int n);
int* create_array (int n);

int main() {
    int n;
    int r = scanf("%d", &n);
    if (r == 1) {
        printf("%d\n", n);
    }
    int* a = create_array(n);
    print_array(a, n);
    free(a);
    return 0;
}

int* create_array (int n) {
    int* tmp = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        tmp[i] = rand() % 20;
    }
    return tmp;
}

void print_array (int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    printf("\n");
}   