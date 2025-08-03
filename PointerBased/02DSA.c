#include <stdio.h>
#include <stdlib.h>

int **userInput(int count){
    int **arr = malloc(count * sizeof(int *));
    if(!arr){
        printf("Memory Allocation is Failed !!\n");
        exit(1);
    }
    for (int i = 0; i < count; i++){
        arr[i] = malloc(sizeof(int));
        if(!arr[i]){
            printf("Memory Allocation is Failed !!\n");
            exit(1);
        }
        printf("Enter %d Element : ",i+1);
        scanf("%d", arr[i]);
    }
    return arr;
    
}
void Display(int **arr,int count){
    printf("\nArray : [ ");
    for(int i=0;i<count;i++){
        printf("%d ",*arr[i]);
    }printf("]\n");
}
int **merged(int **arr1,int count1,int **arr2,int count2){
    int total = count1 + count2;
    int **mixArr = malloc(total * sizeof(int *));
    if(!mixArr){
        printf("Memory Allocation is Failed !!!");
        exit(1);
    }
    for(int i = 0; i<count1;i++){
        mixArr[i] = malloc(sizeof(int));
        *mixArr[i] = *arr1[i];
    }
    for(int i=0;i<count2;i++){
        mixArr[i + count1] = malloc(sizeof(int));
        *mixArr[i + count1] = *arr2[i];
    }
    return mixArr;
}
void freeMe(int **arr,int count){
    for(int i=0;i<count;i++){
        free(arr[i]);
    }
    free(arr);
}
int main(){
    int E1,E2;
    
    printf("Enter NOE in 1st Array: ");
    scanf("%d",&E1);
    int **arr1 = userInput(E1);
    Display(arr1,E1);
    
    printf("Enter NOE in 2nd Array: ");
    scanf("%d",&E2);
    int **arr2 = userInput(E2);
    Display(arr2,E2);
    
    int **mergedArr = merged(arr1,E1,arr2,E2);
    Display(mergedArr,E1+E2);
    
    freeMe(arr1,E1);
    freeMe(arr2,E2);
    freeMe(mergedArr,E1+E2);
    return 0;
}