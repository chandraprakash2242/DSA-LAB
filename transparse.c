#include <stdio.h>

#define MAX 100

void transposeSparse(int a[MAX][3]) {
    int b[MAX][3];
    int i, j, k = 1, n;

    n = a[0][2];  // number of non-zero elements

    // First row of transpose
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = n;

    // For each column of original
    for (i = 0; i < a[0][1]; i++) {
        for (j = 1; j <= n; j++) {
            if (a[j][1] == i) {
                b[k][0] = a[j][1];
                b[k][1] = a[j][0];
                b[k][2] = a[j][2];
                k++;
            }
        }
    }

    // Print transpose
    printf("\nTranspose of Sparse Matrix:\n");
    for (i = 0; i <= n; i++) {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}

int main() {
    int a[MAX][3];
    int rows, cols, i, j, k = 1, nonZero = 0;
    int matrix[MAX][MAX];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                nonZero++;
            }
        }
    }

    // First row
    a[0][0] = rows;
    a[0][1] = cols;
    a[0][2] = nonZero;

    // Fill sparse representation
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                a[k][0] = i;
                a[k][1] = j;
                a[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    printf("\nSparse Matrix Representation:\n");
    for (i = 0; i <= nonZero; i++) {
        printf("%d\t%d\t%d\n", a[i][0], a[i][1], a[i][2]);
    }

    transposeSparse(a);

    return 0;
}
