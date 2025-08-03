#include <stdio.h>
#include <stdlib.h>

int main(){
    int count1,i;
    printf("Enter no. of Element: ");
    scanf("%d",&count1);
    int *arr1=malloc(count1 * sizeof(int));
    if(!arr1){
        printf("Failed to allocate Memory.");
        exit(1);
    }
    for(i=0;i<count1;i++){
        printf("Enter %d Element: ",i+1);
        scanf("%d", &arr1[i]);
    }
    for(i=0;i<count1;i++){
        printf("%d ", arr1[i]);
    }
    return 0;
}