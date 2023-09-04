/*
*File: main.c
*Author: Nguyen Gia Phuc
*Date: 22/07/2023
*Description: Revision of Pointer
*/
#include <stdio.h>
void tong(int a, int b){
    printf("Tong 2 so a va b: %d\n",a+b );
}
void hieu(int a, int b){
    printf("Tong 2 so a va b: %d\n",a-b );
}
int *test()
{
    static int var =10;
    printf("Test: %d\n",var);
    return &var;
}
int Tinhtoan(int a, int b, void(*ptr)(int, int))
{
    printf("Tinh toan:\n");
    ptr(a,b);
}

int main(int argc, char const *argv[])
{
    /*Dinh nghia pointer */
    int var = 10;
    printf("Gia tri var: %d, dia chi %p\n", var, &var);
    int *ptr = &var;
    printf("Gia tri ptr: %d, dia chi %p\n", *ptr, ptr);
    /*Ham tra ve con tro*/
    int *ptr_Test=test();
    *ptr_Test=50;
    test();
    /*Con tro Ham*/
    void (*ptr_func)(int, int) =&tong;
    ptr_func(7,3);
    ptr_func=&hieu;
    ptr_func(7,3);
    Tinhtoan(15,4,tong);
    /*Ep kieu dia chi*/
    char c = 'A';
    void *ptr2 = &c;
    printf("Gia tri ptr2: %c", *(char *)ptr2);
    return 0;
}
