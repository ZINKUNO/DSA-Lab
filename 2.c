#include <stdio.h>

#define MAX_SIZE 1000  

// Brute Force Method
void brute(int a[], double x[], int n) {
    printf("Brute Force: ");
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += a[j];
        }
        x[i] = (double)sum / (i + 1);
        printf("%.2f ", x[i]);
    }
    printf("\n");
}

// Optimized Method
void optimal(int a[], double x[], int n) {
    printf("Optimized:   ");
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        x[i] = (double)sum / (i + 1);
        printf("%.2f ", x[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int a[MAX_SIZE];       //input array 
    double x1[MAX_SIZE];    //brute array
    double x2[MAX_SIZE];    //optimal array

    printf("Enter number of elements in array (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE || n <= 0) {
        printf("Invalid size. Please enter a value between 1 and %d.\n", MAX_SIZE);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &a[i]);
    }

    brute(a, x1, n);
    optimal(a, x2, n);

    return 0;
}
