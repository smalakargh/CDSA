// Program to Initialize an Array and Taking User Input as an Element of the array, Also Updateding and Deleting Element in the array; 
// This is the Updated Version of '01Ques'
// More User Friendly..UI

#include <stdio.h>
#define max 4               //You can change the max-Value

int main() {
    int arr[max];
    int i;
    printf(":: Enter Elements Of Array ::\n");
    for(i=0;i<max;i++){
        printf("Enter %d Element: ",i+1);
        scanf("%d",&arr[i]);
    }printf("\n");
    
    printf("\nEntered Array: [ ");
            for(i=0;i<max;i++){
                printf("%d ",arr[i]);
            }printf("]\n");
    
    int Choose;
    char RepeatProgram;
    do{
        printf("\n:: Choose One of the Following :: ");
        printf("\n--> Press 1 For Update");
        printf("\n--> Press 2 For Delete");
        printf("\n--> Press 3 For Exit");
        printf("\n-> Enter one of the Above: ");
        scanf("%d",&Choose);
    
    switch(Choose){
        case 1:
            int UpdatePosition,UpdateValue;
            printf("\n-> Enter Position Of Element To be Updated: ");
            scanf("%d",&UpdatePosition);
            
            printf("-> Enter Value that To be Updated: ");
            scanf("%d",&UpdateValue);
            
            arr[UpdatePosition - 1] = UpdateValue;
            
            printf("\nUpdated Array: [ ");
            for(i=0;i<max;i++){
                printf("%d ",arr[i]);
            }printf("]");
            break;
        case 2:
            int newArr[max-1],PositionDelete;
            printf("\n-> Enter Position of Element to be Deleted: ");
            scanf("%d",&PositionDelete);
            
            if(PositionDelete<max){
                for(i=0;i<PositionDelete-1;i++){
                newArr[i] = arr[i];
                }
                for(i=PositionDelete;i<max;i++){ 
                    newArr[i-1] = arr[i];
                }
                
                printf("Deleted Array: [ ");
                for(i=0;i<max-1;i++){
                    printf("%d ",newArr[i]);
                }printf("]");
            }else{
                printf("\nYou Enter a InValid Data.Try Again !!!");
            }
            
            break;
        case 3:
            printf("\nYou Exited Successfully !!!");
            break;
        default:
            printf("Invalid Data !!!");
    }
    if(Choose != 3){
        printf("\n\n-> Do You want to perform another Operation (y/n): ");
        scanf(" %c",&RepeatProgram);
    }else{
        RepeatProgram = 'n';
    }
    }while(RepeatProgram == 'y' || RepeatProgram == 'Y');

    return 0;
}