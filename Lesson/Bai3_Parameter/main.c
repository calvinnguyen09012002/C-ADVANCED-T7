/*
*File: main.c
*Author: Nguyen Gia Phuc
*Date: 12/07/2023
*Description: Revision of Parameter
*/
#include <stdio.h>
#include <stdarg.h>


int Tong(int so_tham_so,...){
    va_list var;
    int bien_tong = 0;

    va_start(var, so_tham_so);

    for(int i=0; i<so_tham_so; i++){
        bien_tong += va_arg(var, int);
    }

    va_end(var);

    return bien_tong;

}

int main(int argc, char const *argv[])
{
    printf("\nTong la: %d",Tong(3,3,4,7));
    return 0;
}
