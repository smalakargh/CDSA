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
## 📘1 Question

**Write a c program that create two 2d arrays named arr1 and arr2 dynamically from user;
perform array transpose operation on arr1 and display the result; perform both matrix
multiplication operation between arr1 and arr2 and display the results.**

---

## ✅ Output
    Enter row = column for 1st Matrix: 2
    Enter [1][1] :8
    Enter [1][2] :5
    Enter [2][1] :6
    Enter [2][2] :1
    Array-1:
    8 5 
    6 1 
    Enter row = column for 2nd Matrix: 2
    Enter [1][1] :4
    Enter [1][2] :5
    Enter [2][1] :6
    Enter [2][2] :7
    Array-2:
    4 5 
    6 7 
    
    Transpose of Array-1:
    8 6 
    5 1 
    
    Multiplication of Array-1 with Array-2:
    62 75 
    30 37 

```c
// https://github.com/smalakargh
#include <stdio.h>
#include <stdlib.h>
void feeding(int **arr,int size){
    for(int i=0;i<size;i++){
        arr[i] = malloc(size * (sizeof(int)));
        for(int j=0;j<size;j++){
            printf("Enter [%d][%d] :",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
}
void display(int **arr,int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",arr[i][j]);
        }printf("\n");
    }
}
int **transpose(int **arr1,int size1){
    int **arrTrans = malloc(size1 * (sizeof(int *)));
    for(int i=0;i<size1;i++){
        arrTrans[i] = malloc(size1 * (sizeof(int *)));
        for(int j=0;j<size1;j++){
            arrTrans[i][j] = arr1[j][i];
        }
    }
    return arrTrans;
}
int **multiply(int **arr1, int size1, int **arr2, int size2) {
    if (size1 != size2) {
        printf("Matrix sizes must match for multiplication.\n");
        return NULL;
    }

    int **mulArr = malloc(size1 * sizeof(int *));
    for (int i = 0; i < size1; i++) {
        mulArr[i] = malloc(size1 * sizeof(int));
        for (int j = 0; j < size1; j++) {
            mulArr[i][j] = 0;
            for (int k = 0; k < size1; k++) {
                mulArr[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return mulArr;
}

int main() {
    int size1,size2;
    int **arr1 = malloc(size1 * (sizeof(int *)));
    int **arr2 = malloc(size2 * (sizeof(int *)));
    
    printf("Enter row = column for 1st Matrix: ");
    scanf("%d",&size1);
    feeding(arr1,size1);
    printf("Array-1:\n");
    display(arr1,size1);
    
    printf("Enter row = column for 2nd Matrix: ");
    scanf("%d",&size2);
    feeding(arr2,size2);
    printf("Array-2:\n");
    display(arr2,size2);
    
    printf("\nTranspose of Array-1:\n");
    display(transpose(arr1,size1),size1);
    printf("\nMultiplication of Array-1 with Array-2:\n");
    display(multiply(arr1,size1,arr2,size2),size1);
    
    return 0;
}
```
