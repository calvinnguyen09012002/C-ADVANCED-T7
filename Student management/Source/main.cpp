/*
*File: main.cpp
*Author: Nguyen Gia Phuc
*Date: 08/09/2023
*Description: 
    1: Thêm sinh viên
    2: Cập nhật thông tin sinh viên
    3: Xoá sinh viên bằng ID
    4: Tìm kiếm sinh viên bằng ID
    5: Sắp xếp sinh viên theo điểm trung bình
    6: Sắp xếp sinh viên theo tên
    7: Hiển thị thông tin sinh viên

    8: Thoát ra
*/

#include "Studentclass.h"

int main(int argc, char const *argv[])
{
    vector<Student> database_Student;
    int key = 0;
    bool exit_program = false;

    while (!exit_program)
    {
        system("clear");
        cout<<"-------------------------------------STUDENT MANAGEMENT--------------------------------------"<<endl;
        //Thong bao ban dau
        cout <<"1: Them sinh vien"<<endl;
        cout <<"2: Cap nhat thong tin sinh vien "<<endl;
        cout <<"3: Xoa sinh vien bang ID "<<endl;
        cout <<"4: Tim kiem sinh vien bang ID "<<endl;
        cout <<"5: Sap xep sinh vien theo diem trung binh "<<endl;
        cout <<"6: Sap xep sinh vien theo ten "<<endl;
        cout <<"7: Hien thi thong tin sinh vien "<<endl;
        cout <<"8: Thoat chuong trinh "<<endl;
        //Nhap yeu cau
        turn: 
        cout <<"Nhap lua chon: ";
        cin >> key;
        switch(key){
        case ADD:
            Add_student(database_Student);
            break;
        case UPDATE:
            Update_student(database_Student);
            break;
        case DELETE:
            Delete_student(database_Student);
            break;
        case SEARCH_ID:
            Search_student(database_Student);
            break;
        case ARRANGE_SCORES:
            Arrange_scores(database_Student);
            break;
        case ARRANGE_NAME:
            Arrange_name(database_Student);
            break;
        case PRINT:
            Print_Infor(database_Student);
            break;
        case EXIT:
            exit_program = true;
            break;
        default:
            cout <<"Vui long nhap lai!!"<<endl;
            goto turn;
            break;
        }
    }
    return 0;
}


