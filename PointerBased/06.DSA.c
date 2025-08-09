#include <stdio.h>
#include <stdlib.h>

// Function to input polynomial terms
int **poly_term(int term) {
    // Allocate space for 2 rows: coefficients and powers
    int **result = malloc(2 * sizeof(int *));
    if (!result) {
        printf("Memory Allocation Failed !!!\n");
        exit(1);
    }

    result[0] = malloc(term * sizeof(int)); // Coefficients
    result[1] = malloc(term * sizeof(int)); // Powers

    if (!result[0] || !result[1]) {
        printf("Memory Allocation Failed !!!\n");
        exit(1);
    }

    for (int i = 0; i < term; i++) {
        printf("Enter Coefficient for Term %d: ", i + 1);
        scanf("%d", &result[0][i]);
        printf("Enter Power for Term %d: ", i + 1);
        scanf("%d", &result[1][i]);
    }

    return result;
}

// Function to display a polynomial
void poly_display(int **poly, int count, const char *label) {
    printf("\n%s: ", label);
    for (int i = 0; i < count; i++) {
        printf("(%dX^%d)", poly[0][i], poly[1][i]);
        if (i < count - 1) printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
int **sumPolynomial(int **poly1, int **poly2, int term1, int term2, int *resultTerms) {
    int **sum = malloc(2 * sizeof(int *));
    int maxTerms = term1 + term2;

    sum[0] = malloc(maxTerms * sizeof(int)); // Coefficients
    sum[1] = malloc(maxTerms * sizeof(int)); // Powers

    if (!sum || !sum[0] || !sum[1]) {
        printf("Memory Allocation Failed !!!\n");
        exit(1);
    }

    int k = 0;

    // Add matching powers from poly1 and poly2
    for (int i = 0; i < term1; i++) {
        int found = 0;
        for (int j = 0; j < term2; j++) {
            if (poly1[1][i] == poly2[1][j]) {
                sum[0][k] = poly1[0][i] + poly2[0][j];
                sum[1][k] = poly1[1][i];
                found = 1;
                break;
            }
        }
        if (!found) {
            sum[0][k] = poly1[0][i];
            sum[1][k] = poly1[1][i];
        }
        k++;
    }

    // Add remaining terms from poly2
    for (int j = 0; j < term2; j++) {
        int found = 0;
        for (int i = 0; i < term1; i++) {
            if (poly2[1][j] == poly1[1][i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            sum[0][k] = poly2[0][j];
            sum[1][k] = poly2[1][j];
            k++;
        }
    }

    *resultTerms = k;
    return sum;
}

// Main function
int main() {
    int term1, term2, resultTerms;

    printf("Enter Number of Terms in 1st Polynomial: ");
    scanf("%d", &term1);
    int **poly1 = poly_term(term1);
    poly_display(poly1, term1, "1st Polynomial");

    printf("\nEnter Number of Terms in 2nd Polynomial: ");
    scanf("%d", &term2);
    int **poly2 = poly_term(term2);
    poly_display(poly2, term2, "2nd Polynomial");

    int **poly_sum = sumPolynomial(poly1, poly2, term1, term2, &resultTerms);
    poly_display(poly_sum, resultTerms, "Sum Polynomial");

    // Free allocated memory
    for (int i = 0; i < 2; i++) {
        free(poly1[i]);
        free(poly2[i]);
        free(poly_sum[i]);
    }
    free(poly1);
    free(poly2);
    free(poly_sum);

    return 0;
}
