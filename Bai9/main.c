/*
    Danh sach sinh vien
    Ordinal | Student ID | Name | Year of birth
     1         2010528     Phuc   2002

    1. Them thong tin sinh vien vao file
    2. Doc thong tin sinh vien tu file
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
        uint32_t id;
        char name[100];
        uint16_t yearOfbirth;
    }Student;

void DeleteDownLine(char x[])
{
    size_t len = strlen(x);
    if(x[len-1]=='\n'){
        x[len-1]='\0';
    }
}

void EnterInfor_Individual(Student *sv){
    
    printf("\nID: "); scanf("%d", &sv->id);

    printf("\nStudent name: ");fflush(stdin);fgets(sv->name,sizeof(sv->name),stdin);DeleteDownLine(sv->name);

    printf("\nYear of birth: "); scanf("%d", &sv->yearOfbirth);
}

void DisplayInfor_Individual(Student sv){
    printf("%10d \t %10s \t %10d",sv.id, sv.name, sv.yearOfbirth);
}

void EnterInfor_list(Student a[], int n)
{
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nInformation of Student %d:", i+1);
        EnterInfor_Individual(&a[i]);
        printf("\n____________________________________\n");
    }

}
void DisplayInfor_list(Student a[], int n)
{
    for(int i = 0;i < n;++i){
        DisplayInfor_Individual(a[i]);
        printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    
    int n =0 ;
    do{
        printf("Enter the number of Student: "); scanf("%d", &n);
    }while (n<=0);

    Student a[n];

    EnterInfor_list(a, n);
    printf("%10s \t %10s \t %10s","ID","Name", "Year of birth"); printf("\n");
    DisplayInfor_list(a, n);
    

    FILE *f;
//WRITE FILE
    f = fopen("student.csv","wt");
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


//READ FILE
    printf("DATA IN FILE: \n");
    f = fopen("student.csv","rt");
    if (f == NULL)
    {
        printf("ERROR OPEN FILE TO READ");
        exit(1);
    }

    char temp[100];
    while(!feof(f))
    {
        fgets(temp,100,f);
        printf("%s",temp);
    }  
    fclose(f);

    return 0;
}
