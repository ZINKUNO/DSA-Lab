#include <stdio.h>
#include <stdlib.h>

// Brute Force Method
void brute(int a[], double x[], int n) {
    printf("Brute Force: ");
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j <= i; ++j) {
            sum += a[j];
        }
        x[i] = (double)sum / (i + 1);
        printf("%lf ", x[i]);
    }
    printf("\n");
}

// Optimized Method
void optimal(int a[], double x[], int n) {
    printf("Optimized:   ");
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        x[i] = (double)sum / (i + 1);
        printf("%lf ", x[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    double *x1 = (double *)malloc(n * sizeof(double));
    double *x2 = (double *)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &a[i]);
    }

    brute(a, x1, n);
    optimal(a, x2, n);

    free(a);
    free(x1);
    free(x2);
    return 0;
}
