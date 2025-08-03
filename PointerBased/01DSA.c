#include <stdio.h>
#include <stdlib.h>
#define max 50

void userInput(int **arr,int E){
    for(int i=0;i<E;i++){
        arr[i]=(int *)malloc(sizeof(int));
        printf("Enter %d Element: ",i+1);
        scanf("%d", arr[i]);
    }
}
void display(int **arr,int E,int N){
    printf("\nArray %d : [ ",N);
    for(int i=0;i<E;i++){
        printf("%d ", *arr[i]);
        free(arr[i]);
    }printf("]");
}
int main() {
    int *arr1[max],E1,N1=1;
    printf("Enter NOE in 1st Arr: ");
    scanf("%d",&E1);
    userInput(arr1,E1);
    
    int *arr2[max],E2,N2=2;
    printf("\n2Enter NOE in 2nd Arr: ");
    scanf("%d",&E2);
    userInput(arr2,E2);
    
    display(arr1,E1,N1);
    display(arr2,E2,N2);
    
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>  

// #define max 50

// void userInput(int **arr,int E){
//     for(int i=0;i<E;i++){
//         arr[i]=(int *)malloc(sizeof(int));
//         printf("Enter %d Element: ",i+1);
//         scanf("%d", arr[i]);
//     }
// }
// void display(int **arr,int E,int N){
//     printf("\nArray %d : [ ",N);
//     for(int i=0;i<E;i++){
//         printf("%d ", *arr[i]);
//         free(arr[i]);
//     }printf("]");
// }
// int main() {
//     clock_t start, end;
//     double cpu_time_used;

//     start = clock();  // Start timing

//     int *arr1[max], E1, N1 = 1;
//     printf("Enter NOE in 1st Arr: ");
//     scanf("%d", &E1);
//     userInput(arr1, E1);

//     int *arr2[max], E2, N2 = 2;
//     printf("\nEnter NOE in 2nd Arr: ");
//     scanf("%d", &E2);
//     userInput(arr2, E2);

//     display(arr1, E1, N1);
//     display(arr2, E2, N2);

//     end = clock();  // End timing

//     cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
//     printf("\nExecution Time: %.6f seconds\n", cpu_time_used);

//     return 0;
// }
