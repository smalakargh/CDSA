// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
int **poly_term(int term){
    int **coeff = malloc(term * sizeof(int *));
    int **power = malloc(term * sizeof(int *));
    int i;
    if(!coeff || !power){
        printf("Memory Allocation Failed !!!\n");
        exit(1);
    }
    for(i=0;i<term;i++){
        coeff[i] = malloc(sizeof(int));
        power[i] = malloc(sizeof(int));
        printf("Enter %d Co-efficient: ",i+1);
        scanf("%d", coeff[i]);
        printf("Enter %d Power: ",i+1);
        scanf("%d", power[i]);
    }
    return coeff;
}
void Display(int **arr,int count,char *string){
    printf("\n%s : [ ",string);
    for(int i=0;i<count;i++){
        printf("%d ",*arr[i]);
    }printf("]\n");
}
int main() {
    int term1;
    printf("Enter No. of Terms: ");
    scanf("%d", &term1);
    int **coeff = poly_term(term1);
    Display(coeff,term1,"Coefficient");
    return 0;
}