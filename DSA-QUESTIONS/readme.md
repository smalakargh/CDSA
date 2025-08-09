# 🧠 Bash Practice: Count Lines in a File

## 📘1 Question

**Write a program in C to demonstrate how to handle pointers in a program.**

---

## ✅ Output
     Address of m : 0x7ffcc3ad291c
     Value of m : 29                                                                                              

     Now ab is assigned with the address of m.                                                                    
     Address of pointer ab : 0x7ffcc3ad291c                                                                       
     Content of pointer ab : 29                                                                                   

     The value of m assigned to 34 now.                                                                           
     Address of pointer ab : 0x7ffcc3ad291c                                                                       
     Content of pointer ab : 34                                                                                   

     The pointer variable ab is assigned with the value 7 now.                                                    
     Address of m : 0x7ffcc3ad291c                                                                                
     Value of m : 7 

```c
    // https://github.com/smalakargh
    #include <stdio.h>

    int main() {
        int value = 24;
        int *m = &value;
        printf("Address Of m : %p\n",m);
        printf("value Of m : %d\n\n",*m);
        int **ab = &m;
        printf("Address Of ab: %p\n", *ab);
        printf("Content Of ab: %d\n\n", **ab);
        *m = 34;
        printf("Address Of ab: %p\n", *ab);
        printf("Content Of ab: %d\n\n", **ab);
        **ab = 7;
        printf("Address Of m : %p\n",m);
        printf("value Of m : %d\n\n",*m);
        return 0;
    }
```
## 📘2 Question

**Write a program in C to demonstrate the use of the &(address of) and *(value at address) operators.**

---

## ✅ Output
    Using &
    -----------------
    Address of m: 0x7fffba932c78
    Address of fx: 0x7fffba932c70
    Address of cht: 0x7fffba932c68

    Using & and *
    -----------------
    Address of m: 300
    Address of fx: 300.067902
    Address of cht: z

    Using Only Pointer variable
    -----------------
    Value of m: 300
    Value of fx: 300.067902
    Value of cht: z

```c
    // https://github.com/smalakargh
#include <stdio.h>

int main() {
    int m = 300;
    float fx = 300.06789;
    char cht = 'z';
    int *ptr1 = &m;
    float *ptr2 = &fx;
    char *ptr3 = &cht;

    printf("Using &\n");
    printf("-----------------\n");
    printf("Address of m: %p\n", &ptr1);
    printf("Address of fx: %p\n", &ptr2);
    printf("Address of cht: %p\n\n", &ptr3);
    
    printf("Using & and *\n");
    printf("-----------------\n");
    printf("Address of m: %d\n", *(&m));
    printf("Address of fx: %f\n",*(&fx) );
    printf("Address of cht: %c\n\n", *(&cht));
    
    printf("Using Only Pointer variable\n");
    printf("-----------------\n");
    printf("Value of m: %d\n", *ptr1);
    printf("Value of fx: %f\n", *ptr2);
    printf("Value of cht: %c\n\n", *ptr3);
    return 0;
}
```
## 📘3 Question

**Write a program in C to get the Largest number from the user Input.**

---

## ✅ Output
    Enter No of Elements: 5
    Enter 1 Element: 104
    Enter 2 Element: 23
    Enter 3 Element: 222
    Enter 4 Element: 556
    Enter 5 Element: 254
    Largest Element: 556

```c
// https://github.com/smalakargh
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr = calloc(n,sizeof(int));
    printf("Enter No of Elements: ");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        printf("Enter %d Element: ",i+1);
        scanf("%d", arr + i);
    }
    
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    printf("Largest Element: %d", max);
    
    return 0;
}
```