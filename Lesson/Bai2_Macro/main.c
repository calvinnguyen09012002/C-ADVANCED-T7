/*
*File: main.c
*Author: Nguyen Gia Phuc
*Date: 08/07/2023
*Description: Revision of Macro
*/
#include <stdio.h>

/*
#define Size 10

void test(){
    printf("\nHello world");
}

#define PRINT test()

#define TONG(a,b) a+b

int main(int argc, char const *argv[])
{
    int array[Size];

    PRINT;

    printf("\nTong a va b la: %d",TONG(5,6));
    return 0;
}
*/

/*
#define INPUT_DISPLAY(var, cmd, cond)   \
int var;                                \
do                                      \
{                                       \
    printf(cmd);                        \
    scanf("%d",&var);                   \
} while (cond);                         \
printf(#var);                           \
printf(" = %d\n",var);   

#define VARIABLE(name)  \
int int_##name;         \
double double_##name;   \
char char_##name;

#define TEST(var, ...)  \
__VA_ARG__              \
var
*/

#define SIZE 9
#if SIZE > 10
void test(){
    printf("Nguyen Gia Phuc dep trai");
}
#elif SIZE == 10
void test(){
    printf("Nguyen Gia Phuc tai nang");
}
#else
void test(){
    printf("Nguyen Gia Phuc hoc gioi");
}
#endif

int main(int argc, char const *argv[])
{
   // INPUT_DISPLAY(i, "Nhap vao i(i<5): ", i>=5);

    // VARIABLE(bien);

   // TEST(ABC, fgs123);

   test();
    return 0;
}
