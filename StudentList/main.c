/*
*File: main.c
*Author: Nguyen Gia Phuc
*Date: 06/08/2023
*Description: 
    1. Them thong tin sinh vien vao file
    2. Doc thong tin sinh vien tu file
    Ordinal | Student ID | Name | Year of birth
     1         2010528     Phuc   2002
    
    3. Sap xep the alphabet
    4. Dem so ten giong nhau
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>


char string[] = "";
char khoangtrang[]= " ";
typedef struct {
        uint32_t id;
        char name[100];
        uint16_t yearOfbirth;
    }Student;

/*
* Function: DeleteDownLine
* Description: Xoa ki tu xuong dong
*/

void DeleteDownLine(char x[])
{
    size_t len = strlen(x);
    if(x[len-1]=='\n'){
        x[len-1]='\0';
    }
}

/*
* Function: EnterInfor_Individual
* Description: Nhap thong tin sinh vien, su dung nhieu trong EnterInfor_list
*/
void EnterInfor_Individual(Student *sv){
    
    printf("\nID: "); scanf("%d", &sv->id);

    printf("\nStudent name: ");fflush(stdin);fgets(sv->name,sizeof(sv->name),stdin);DeleteDownLine(sv->name);

    printf("\nYear of birth: "); scanf("%d", &sv->yearOfbirth);
}

/*
* Function: DisplayInfor_Individual
* Description: Xuat thong tin sinh vien, Su dung nhieu trong DisplayInfor_list
*/
void DisplayInfor_Individual(Student sv){
    printf("%10d \t %10s \t %10d",sv.id, sv.name, sv.yearOfbirth);
}

/*
* Function: EnterInfor_list
* Description: Tong hop lai thong tin da nhap
*/
void EnterInfor_list(Student a[], int n)
{
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nInformation of Student %d:", i+1);
        EnterInfor_Individual(&a[i]);
        printf("\n____________________________________\n");
    }

}

/*
* Function: DisplayInfor_list
* Description: Xuat danh sach sinh vien
*/
void DisplayInfor_list(Student a[], int n)
{
    for(int i = 0;i < n;++i){
        DisplayInfor_Individual(a[i]);
        printf("\n");
    }
}

/*
* Function: isEqual, *splitString, sortAlphabet, test, counter
* Description: Sap xep va dem ten giong nhau
* Input:
*   String[] : mang chua ten sinh vien
* Output:
*  1. ptr chua ten duoc sap xep theo alphabet
*  2. Dem so ten giong nhau thong qua bien NumberoftheSameName trong main
*/
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
    /*Nhap so luong hoc sinh*/
    int n =0 ;
    do{
        printf("Enter the number of Student: "); scanf("%d", &n);
    }while (n<=0);

    /*
    Them thong tin sinh vien
    Xuat thong tin sinh vien
    */
    Student a[n];
    EnterInfor_list(a, n);
    printf("%10s \t %10s \t %10s","ID","Name", "Year of birth"); printf("\n");
    DisplayInfor_list(a, n);
    

    FILE *f;

    /* Ghi vao file */

    f = fopen("student.csv","w");
    if (f == NULL)
    {
        printf("ERROR OPEN FILE TO WRITE");
        exit(1);
    }

    for(int i=0;i<n;i++)
    {
        fprintf(f,"%d,%s,%d\n",a[i].id,a[i].name,a[i].yearOfbirth);
    }

    fclose(f);


    /* Doc file */
    printf("DATA IN FILE: \n");
    f = fopen("student.csv","r");
    if (f == NULL)
    {
        printf("ERROR OPEN FILE TO READ");
        exit(1);
    }
    
    char line[100];
    int temp = 0;
    while (fgets(line, 100, f) != NULL) {
        char *token = strtok(line, ",");// Tách các giá trị trong dòng bằng dấu phẩy
        while (token != NULL) {
            // In ra từng giá trị
            switch (temp) {
            case 0: // ID
                token = strtok(NULL, ",");
                temp ++;
                break;
            case 1: // Ten
            /* lu ten sinh vien trong string */
                strcat(string, token);
                strcat(string, khoangtrang);
                token = strtok(NULL, ",");
                temp ++;
                break;
            case 2: // Nam sinh
                token = strtok(NULL, ",");
                temp = 0;
                break;
            default:
                break;
            }
        }
    }
    fclose(f);

//------------- Sap xep va dem so ten giong nhau
/* line 250 line 251, ten sinh vien duoc luu trong string*/
    words *ptr = splitString(string);

    sortAlphabet(ptr,n);

    printf("-----------------\n");
    printf("Danh sach sau khi sap xep: \n");
    for (int i = 0; i < n; i++)
    {
        test(ptr[i]);
        printf("\n");
    }
    printf("-----------------\n");
    printf("Sau khi thong ke ta co: \n");


    int pos = 0;
    int NumberoftheSameName = 1;
    while(pos<=12)
    {
        if(counter(ptr[pos],ptr[pos+1])) 
        {
            pos++;
            NumberoftheSameName++;
        }
        else{
            
            printf("   Co %d ten ",NumberoftheSameName); 
            test(ptr[pos]);
            printf("\n"); 
            pos++;
            NumberoftheSameName = 1;
        }
    }
    return 0;
}
