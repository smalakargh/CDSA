# 🧠 Bash Practice: Count Lines in a File

## 📘 Question

**How can I count the number of lines in a file named `data.txt` using Bash?**

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

```bash
// https://github.com/smalakargh
#include <stdio.h>

int main() {
    int value = 24;
    int *m = &value;
    printf("Address Of m : %d\n",m);
    printf("value Of m : %d\n\n",*m);
    int **ab = &m;
    printf("Address Of ab: %d\n", *ab);
    printf("Content Of ab: %d\n\n", **ab);
    *m = 34;
    printf("Address Of ab: %d\n", *ab);
    printf("Content Of ab: %d\n\n", **ab);
    **ab = 7;
    printf("Address Of m : %d\n",m);
    printf("value Of m : %d\n\n",*m);
    return 0;
}
```

