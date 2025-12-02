#include <stdio.h>
#include <stdlib.h>

void main(){
    int *ft,*st,f,s;
    printf("Enter First Number : ");
    scanf("%d",&f);
    printf("Enter Second Number : ");
    scanf("%d",&s);
    ft = &f,st = &s;
    printf("Sum of %d + %d = %d",f,s,*ft+*st);
}