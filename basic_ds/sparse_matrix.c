#include <stdio.h>

void main() {
    static int array[10][10];
    int i, j, m, n;
    int counter = 0;

    printf("Enter the order of the matrix \n");
    printf("Enter the number of rows in array: ");
    scanf("%d", &m);
    printf("Enter the number of columns in array: ");
    scanf("%d", &n);

    printf("Enter the co-efficients of the matrix: \n");
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &array[i][j]);
            if (array[i][j] == 0) {
                ++counter;
            }
        }
    }

    if (counter > ((m * n) / 2)) {
        printf("The given matrix is sparse matrix \n");
    }

    else
        printf("The given matnix is not a sparse matrix \n");
    printf("There are %d number of zeros\n", counter);
}