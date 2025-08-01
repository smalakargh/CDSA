#include <stdio.h>
#define max 10
int main() {
    int i,arr[max];
    for(i=0;i<max;i++){
        printf("Enter %d Element: ",i+1);
        scanf("%d", &arr[i]);
    }
    arr[2] = 50;
    
    printf("\nArray: [ ");
    for(i=0;i<max;i++){
        printf("%d ",arr[i]);
    }printf("]");
    
    //Deleting index 3th Element
    int newArr[max];
    for(i=0;i<3;i++){
        newArr[i] = arr[i];
    }
    for(i=3;i<max;i++){
        newArr[i] = arr[i+1];
    }
    printf("\nArray After Deleted (Index 3) Element: [ ");
    for(i=0;i<max-1;i++){
        printf("%d ",newArr[i]);
    }printf("]");
    return 0;
}