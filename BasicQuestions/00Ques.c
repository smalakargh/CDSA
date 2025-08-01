#include <stdio.h>
#define max 10

int main() {
    int i,age[max];
    for(i=0;i<max;i++){
        printf("Enter %d Element: ",i+1);
        scanf("%d", &age[i]);
    }
    printf("\nThird Element: %d\nSeventh Element: %d",age[2],age[6]);
    
    age[0] = age[max-1] = 20;
    
    printf("\nArray age: [ ");
    for(i=0;i<max;i++){
        printf("%d ",age[i]);
    }printf(" ]");
    return 0;
}