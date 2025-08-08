#include <stdio.h>
#include <stdlib.h>
int **poly_term(int term){
    int **result =  malloc(2 * sizeof(int *));
    int i;
    if(!result){
        printf("Memory Allocation Failed !!!\n");
        exit(1);
    }
    
    result[0] = malloc(term * sizeof(int *));
    result[1] = malloc(term * sizeof(int *));
    
    for(i=0;i<term;i++){
        printf("Enter %d Term Co-efficient: ",i+1);
        scanf("%d", &result[0][i]);
        printf("Enter %d Term Power: ",i+1);
        scanf("%d", &result[1][i]);
    }
    return result;
}
void poly_display(int **poly,int count,char *string){
    printf("\n%s : ",string);
    for(int i=0;i<count;i++){
        printf("%dX^%d ",poly[0][i],poly[1][i]);
        if(i < count - 1) printf("+ ");
    }
}
int main() {
    int term1,term2;
    printf("Enter No. of Terms (1st Polynomial): ");
    scanf("%d", &term1);
    int **poly1 = poly_term(term1);
    poly_display(poly1,term1,"1st Polynomial");
    printf("\n\nEnter No. of Terms(2nd Polynomial): ");
    scanf("%d", &term2);
    int **poly2 = poly_term(term2);
    poly_display(poly2,term2,"2nd Polynomial");
    
    return 0;
}