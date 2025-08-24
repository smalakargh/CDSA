## 📘1 Question

**Write a c program that creates two 1D arrays dynamically of different array size taken from
user and merge them into one array. The result should display the resulting array.**

---

## ✅ Output
    Enter size of 1st Array: 3
    Enter size of 2nd Array: 2
    
    Enter Data for 1 Array:
    Enter 1 Element: 56
    Enter 2 Element: 55
    Enter 3 Element: 54
    
    Array-1 Data:
    1 Element is 56
    2 Element is 55
    3 Element is 54
    
    Enter Data for 2 Array:
    Enter 1 Element: 23
    Enter 2 Element: 24
    
    Array-2 Data:
    1 Element is 23
    2 Element is 24

```c
// https://github.com/smalakargh
#include <stdio.h>
#include <stdlib.h>

void inputData(int *arr, int size,int N){
    printf("Enter Data for %d Array:\n",N);
    for(int i=0;i<size;i++){
        printf("Enter %d Element: ",i+1);
        scanf("%d",&arr[i]);
    }printf("\n");
}
void display(int *arr,int size,int N){
    printf("Array-%d Data:\n",N);
    for(int i=0;i<size;i++){
        printf("%d Element is %d\n",i+1,arr[i]);
    }printf("\n");
}
void freeme(int *arr){
    free(arr);
}
int main() {
    int size1,size2;
    
    printf("Enter size of 1st Array: ");
    scanf("%d",&size1);
    printf("Enter size of 2nd Array: ");
    scanf("%d",&size2);
    printf("\n");
    
    int *arr1 = malloc(size1 *(sizeof(int)));
    int *arr2 = malloc(size2 *(sizeof(int)));
    
    if(arr1 == NULL || arr2 == NULL){
        printf("Memory Allocation Failed !!!");
        return 1;
    }
    
    inputData(arr1,size1,1);
    display(arr1,size1,1);
    
    inputData(arr2,size2,2);
    display(arr2,size2,2);
    
    freeme(arr1);
    freeme(arr2);
    
    return 0;
}
```