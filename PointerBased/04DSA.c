#include <stdio.h>
#include <stdlib.h>

/* Helper to allocate an r x c int matrix */
int **alloc_matrix(int r, int c) {
    int **a = (int **)malloc(r * sizeof(int *));
    if (!a) return NULL;
    for (int i = 0; i < r; i++) {
        a[i] = (int *)malloc(c * sizeof(int));
        if (!a[i]) {
            for (int k = 0; k < i; k++) free(a[k]);
            free(a);
            return NULL;
        }
    }
    return a;
}

/* Free an r x c matrix allocated with alloc_matrix */
void free_matrix(int **a, int r) {
    if (!a) return;
    for (int i = 0; i < r; i++) free(a[i]);
    free(a);
}

/* Read values into matrix */
void read_matrix(int **a, int r, int c, const char *name) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%s[%d][%d]: ", name, i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

/* Print matrix with a title */
void print_matrix(const char *title, int **a, int r, int c) {
    printf("%s\n", title);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

/* Transpose: returns c x r matrix */
int **transpose(int **a, int r, int c) {
    int **t = alloc_matrix(c, r);
    if (!t) return NULL;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            t[j][i] = a[i][j];
    return t;
}

/* Sum of two r x c matrices */
int **add_matrices(int **a, int **b, int r, int c) {
    int **s = alloc_matrix(r, c);
    if (!s) return NULL;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            s[i][j] = a[i][j] + b[i][j];
    return s;
}

/* Product: (r1 x c1) * (r2 x c2). Returns NULL if c1 != r2 */
int **multiply_matrices(int **a, int r1, int c1, int **b, int r2, int c2) {
    if (c1 != r2) return NULL;
    int **p = alloc_matrix(r1, c2);
    if (!p) return NULL;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int sum = 0;
            for (int k = 0; k < c1; k++) {
                sum += a[i][k] * b[k][j];
            }
            p[i][j] = sum;
        }
    }
    return p;
}

int main(void) {
    int r, c;

    printf("Enter rows and columns (for both matrices): ");
    if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    int **arr1 = alloc_matrix(r, c);
    int **arr2 = alloc_matrix(r, c);
    if (!arr1 || !arr2) {
        printf("Memory allocation failed for input matrices.\n");
        free_matrix(arr1, r);
        free_matrix(arr2, r);
        return 1;
    }

    printf("\nEnter elements for arr1:\n");
    read_matrix(arr1, r, c, "arr1");
    printf("\nEnter elements for arr2:\n");
    read_matrix(arr2, r, c, "arr2");

    printf("\n");
    print_matrix("arr1:", arr1, r, c);
    print_matrix("\narr2:", arr2, r, c);

    /* Transpose of arr1 (c x r) */
    int **t = transpose(arr1, r, c);
    if (!t) {
        printf("\nFailed to compute transpose (memory error).\n");
        free_matrix(arr1, r);
        free_matrix(arr2, r);
        return 1;
    }
    print_matrix("\nTranspose of arr1:", t, c, r);

    /* Addition (r x c) */
    int **sum = add_matrices(arr1, arr2, r, c);
    if (!sum) {
        printf("\nFailed to compute sum (memory error).\n");
        free_matrix(t, c);
        free_matrix(arr1, r);
        free_matrix(arr2, r);
        return 1;
    }
    print_matrix("\narr1 + arr2:", sum, r, c);

    /* Multiplication: only possible if c == r */
    int **prod = multiply_matrices(arr1, r, c, arr2, r, c);
    if (!prod) {
        printf("\nMultiplication not possible: columns of arr1 (%d) != rows of arr2 (%d).\n", c, r);
    } else {
        print_matrix("\narr1 * arr2:", prod, r, c);
    }

    /* Cleanup */
    free_matrix(arr1, r);
    free_matrix(arr2, r);
    free_matrix(t, c);
    free_matrix(sum, r);
    if (prod) free_matrix(prod, r);

    return 0;
}
