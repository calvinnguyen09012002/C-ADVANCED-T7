/*
*File: main.c
*Author: Nguyen Gia Phuc
*Date: 05/08/2023
*Description: Assort name and count the same in list of student
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

//Cho 1 chuoi bat ki
char string[] = "phuc khanh khanh";

typedef struct{
    char *ptr;
    uint8_t length;
}words;

typedef struct{
    char *words;
    uint8_t length;
}wordsArray;


bool isEqual(const char arr1[], const char arr2[]){
    while (*arr1==*arr2){
        if(*arr1 == '\0'){
            return true;
        }
        arr1++;
        arr2++;
    }
    if (*arr1 > *arr2)
    {
        return true;
    } 
    return false; 
}

words *splitString(char string[]){
    uint8_t size = 1;
    char *ptr =string;
    while (*ptr != '\0')
    {
        if(*ptr == ' ') size++;
        ptr++;
    }

    words *array = (words*)malloc(sizeof(words)*size);
    uint8_t index =0;
    uint8_t count =1;

    array[index].ptr = string;
    while (*string != '\0' )
    {
        if(*string==' '){
            array[index].length = count;
            count = 1;
            string++;
            array[++index].ptr = string;
        }else{
            count++;
            string++;
        }

    }
    array[index].length = count;

    return array;  
}

void sortAlphabet(words array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        words temp;
        for (int j = i+1; j < size; j++)
        {
            if(isEqual(array[i].ptr,array[j].ptr)){
                temp = array [i];
                array[i] = array[j];
                array[j] = temp;
            }
        }   
    }  
}

//vd nhat xuat hien 2 lan
//hoang xuat hien 2 lan
//nam xuat hien 3 lan



void test(words test){
    for (int i = 0; i < test.length; i++)
    {
        printf("%c", test.ptr[i]);
    }
}

bool counter(words test1, words test2){
    //if(test1.length != test2.length) return false;

    for (int i = 0; i < test1.length; i++)
    {
        if(test1.ptr[i] != test2.ptr[i]) return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    words *ptr = splitString(string);

    sortAlphabet(ptr,12);

    printf("-----------------\n");
    printf("Danh sach sau khi sap xep: \n");
    for (int i = 0; i < 12; i++)
    {
        test(ptr[i]);
        printf("\n");
    }
    printf("-----------------\n");
    printf("Sau khi thong ke ta co: \n");


    int n = 0;
    int NumberoftheSameName = 1;
    while(n<=12)
    {
        if(counter(ptr[n],ptr[n+1])) 
        {
            n++;
            NumberoftheSameName++;
        }
        else{
            
            printf("   Co %d ten ",NumberoftheSameName); 
            test(ptr[n]);
            printf("\n"); 
            n++;
            NumberoftheSameName = 1;
        }
    }
    return 0;
}
