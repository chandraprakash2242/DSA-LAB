#include <stdio.h>
#define MAX 100

void addSparse(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    int i = 1, j = 1, k = 1;
    
    // Check if dimensions match
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        printf("Addition not possible. Matrix sizes do not match.\n");
        return;
    }

    C[0][0] = A[0][0]; // rows
    C[0][1] = A[0][1]; // cols

    while(i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else { // same position
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    // Copy remaining elements
    while(i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    while(j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;

    // Print Result
    printf("\nSum of Sparse Matrices:\n");
    for(i = 0; i <= C[0][2]; i++) {
        printf("%d\t%d\t%d\n", C[i][0], C[i][1], C[i][2]);
    }
}

int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3];
    int matrixA[MAX][MAX], matrixB[MAX][MAX];
    int rows, cols, i, j, kA = 1, kB = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input Matrix A
    printf("Enter elements of Matrix A:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrixA[i][j]);
            if(matrixA[i][j] != 0) {
                A[kA][0] = i;
                A[kA][1] = j;
                A[kA][2] = matrixA[i][j];
                kA++;
            }
        }
    }
    A[0][0] = rows; A[0][1] = cols; A[0][2] = kA-1;

    // Input Matrix B
    printf("Enter elements of Matrix B:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrixB[i][j]);
            if(matrixB[i][j] != 0) {
                B[kB][0] = i;
                B[kB][1] = j;
                B[kB][2] = matrixB[i][j];
                kB++;
            }
        }
    }
    B[0][0] = rows; B[0][1] = cols; B[0][2] = kB-1;

    addSparse(A, B, C);

    return 0;
}
