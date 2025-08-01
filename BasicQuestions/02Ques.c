// Program to Initialize an Array and Taking User Input as an Element of the array, Also Updateding and Deleting Element in the array; 

#include <stdio.h>
#define max 4
int main() {
    int arr[max];
    int i;
    printf(":: Enter Elements Of Array ::\n\n");
    for(i=0;i<max;i++){
        printf("Enter %d Element: ",i+1);
        scanf("%d",&arr[i]);
    }printf("\n");
    
    int UpdatePosition,UpdateValue;
    printf("Enter Position Of Element To be Updated: ");
    scanf("%d",&UpdatePosition);
    
    printf("Enter Value that To be Updated: ");
    scanf("%d",&UpdateValue);
    
    arr[UpdatePosition - 1] = UpdateValue;
    
    printf("\nUpdated Array: ");
    for(i=0;i<max;i++){
        printf("%d ",arr[i]);
    }
    
    int newArr[max-1],PositionDelete;
    printf("\n\nEnter Position of Element to be Deleted: ");
    scanf("%d",&PositionDelete);
    
    for(i=0;i<PositionDelete-1;i++){ //2-1 = 1
        newArr[i] = arr[i];
    }
    for(i=PositionDelete;i<max;i++){ // 2
        newArr[i-1] = arr[i];
    }
    
    printf("\nDeleted Array: ");
    for(i=0;i<max-1;i++){
        printf("%d ",newArr[i]);
    }

    return 0;
}