/*
*File: main.c
*Author: Nguyen Gia Phuc
*Date: 20/07/2023
*Description: Revision of Variable
*/
#include <stdio.h>



extern void test_extern();

/*
//static
int *ptr;
void test(){
    static int i =0;
    ptr = &i;
    printf("\ni= %d",i++);
}
*/
int main(int argc, char const *argv[])
{

    test_extern();
    test_extern();
    test_extern();

    return 0;
}
