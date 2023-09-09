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


#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

typedef enum{
    ADD = 1,
    UPDATE = 2,
    DELETE = 3,
    SEARCH_ID = 4,
    ARRANGE_SCORES = 5,
    ARRANGE_NAME = 6,
    PRINT = 7,
    EXIT = 8
}Demand;

typedef enum{
    Excellent = 1,
    Good = 2,
    Weak = 3
} Type_of_Ability;

typedef enum{
    Male = 1,
    Female = 2
} Type_of_Gender;

class Student{
    private:
        int ID;
        string NAME;
        int OLD;
        Type_of_Gender GENDER;
        double MATH_SCORES; 
        double PHYSICS_SCORES; 
        double CHEMISTRY_SCORES;
        Type_of_Ability ABILITY;  
    public:
        Student(string name, int old, Type_of_Gender gender,double math_scores, double physic_scores, double chemistry_scores);

        void Set_Name(string name);
        void Set_Old(int old);
        void Set_Gender(Type_of_Gender gender);
        void Set_Math_scores(double math_scores);
        void Set_Physics_scores(double math_scores);
        void Set_Chemistry_scores(double math_scores);

        int Get_ID();
        string Get_Name();
        int Get_Old();
        Type_of_Gender Get_Gender();
        double Get_Math_scores();
        double Get_Physics_scores();
        double Get_Chemistry_scores();
        double Get_Average_scores();
        Type_of_Ability Get_Ability();
};

Student::Student(string name, int old, Type_of_Gender gender,double math_scores, double physics_scores, double chemistry_scores){
    static int id = 0;
    this->ID = id;
    id++;

    this->NAME = name;
    this->OLD = old;
    this->GENDER = gender;
    this->MATH_SCORES = math_scores;
    this->PHYSICS_SCORES = physics_scores;
    this->CHEMISTRY_SCORES = chemistry_scores;
}

void Student::Set_Name(string name){
    NAME = name;
}

void Student::Set_Old(int old){
    OLD = old;
}

void Student::Set_Gender(Type_of_Gender gender){
    GENDER = gender;
}

void Student::Set_Math_scores(double math_scores){
    MATH_SCORES = math_scores;
}

void Student::Set_Physics_scores(double physics_scores){
    PHYSICS_SCORES = physics_scores;
}

void Student::Set_Chemistry_scores(double chemistry_scores){
    CHEMISTRY_SCORES = chemistry_scores;
}

int Student::Get_ID(){
    return ID;
}

string Student::Get_Name(){
    return NAME;
}

int Student::Get_Old(){
    return OLD;
}

Type_of_Gender Student::Get_Gender(){
    return GENDER;
}

double Student::Get_Math_scores(){
    return MATH_SCORES;
}

double Student::Get_Physics_scores(){
    return PHYSICS_SCORES;
}

double Student::Get_Chemistry_scores(){
    return CHEMISTRY_SCORES;
}

double Student::Get_Average_scores(){
    return (MATH_SCORES+PHYSICS_SCORES+CHEMISTRY_SCORES)/3;
}

Type_of_Ability Student::Get_Ability(){
    if ((MATH_SCORES+PHYSICS_SCORES+CHEMISTRY_SCORES)/3 >= 9)
    {
        return Excellent;
    }else if ((MATH_SCORES+PHYSICS_SCORES+CHEMISTRY_SCORES)/3 < 5)
    {
        return Weak;
    }else{
        return Good;
    } 
}

//--------------FUNCTION----------------------
void Add_student(vector<Student>& database_Student);
void Update_student(vector<Student>& database_Student);
void Delete_student(vector<Student>& database_Student);
void Arrange_scores(vector<Student>& database_Student);
void Arrange_name(vector<Student>& database_Student);
void Search_student(vector<Student> database_Student);
void Print_Infor(vector<Student> database_Student);

//---------------MAIN FUNTION--------------
int main(int argc, char const *argv[])
{
    vector<Student> database_Student;
    int key = 0;

    while (1)
    {
        system("clear");
        cout<<"------------STUDENT MANAGEMENT---------------"<<endl;
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
turn:   cout <<"My choice: ";
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
            goto exit;
            break;
        default:
            cout <<"Vui long nhap lai!!"<<endl;
            goto turn;
            break;
        }
    }
    exit:
    return 0;
}

void Add_student(vector<Student>& database_Student){
    continue_adding:
    cout<<"------------ADD STUDENT---------------"<<endl;
    int ID_temp;
    string NAME_temp;
    int OLD_temp;
    Type_of_Gender GENDER_temp; int temp;
    double MATH_SCORES_temp; 
    double PHYSICS_SCORES_temp; 
    double CHEMISTRY_SCORES_temp;

    cin.ignore();
    cout <<"Nhap ten sinh vien: "; 
    getline(cin,NAME_temp);
    cout <<"Nhap ten tuoi: "; cin >> OLD_temp;
    do
    {
        cout <<"Nhap ten gioi tinh(1.NAM   2.NU): ";
        cin >> temp;
    } while ((temp != 1)&&(temp != 2));
    if (temp == 1) 
    {
        GENDER_temp = Male; 
    }else if (temp == 2)
    {
        GENDER_temp = Female;
    }
    do
    {
        cout <<"Nhap ten diem toan (0-10): ";
        cin >> MATH_SCORES_temp;
    } while ((MATH_SCORES_temp < 0)||(MATH_SCORES_temp  > 10));
    do
    {
        cout <<"Nhap ten diem ly (0-10): ";
        cin >> PHYSICS_SCORES_temp;
    } while ((PHYSICS_SCORES_temp < 0)||(PHYSICS_SCORES_temp  > 10));
    do
    {
        cout <<"Nhap ten diem hoa (0-10): ";
        cin >> CHEMISTRY_SCORES_temp;
    } while ((CHEMISTRY_SCORES_temp < 0)||(CHEMISTRY_SCORES_temp  > 10));
    

    Student student_temp= {NAME_temp, OLD_temp, GENDER_temp, MATH_SCORES_temp, PHYSICS_SCORES_temp, CHEMISTRY_SCORES_temp};
    database_Student.push_back(student_temp);

    int out;
    enter_again:
    cout <<"------CONTINUE OR END----------"<<endl;
    cout <<"Nhan phim 1 de tiep tuc them sinh vien"<<endl;
    cout <<"Nhan phim 0 de thoat: "<<endl;
    cout <<"My choice: ";
    cin >>out;
    switch (out)
    {
    case 0:
        break;
    case 1:
        goto continue_adding;
        break;
    default:
        goto enter_again;
        break;
    }
}

void Update_student(vector<Student>& database_Student){
    continue_updating:
    cout<<"------------UPDATE INFORMATION OF STUDENT---------------"<<endl;
    cout<<"Hien nay co "<<database_Student.size()<<" sinh vien, gom co cac ID sau:"<<endl;

    for(int i=0; i < database_Student.size(); i++){
            cout << database_Student[i].Get_ID()<<", ";     
    }
    cout << endl;


    if(!database_Student.size()) return;
    int ID_temp;
    do
    {
        cout <<"Nhap ID muon cap nhat: ";
        cin >> ID_temp;
    } while ((ID_temp < 0)||(ID_temp > database_Student.size()-1));

    int found = 0;
    for(int i=0; i < database_Student.size(); i++) {
        if (database_Student[i].Get_ID() == ID_temp) {
            found = 1;
            cout << "\n------------Cap nhat sinh vien co ID---------------" <<endl;

            int ID_temp;
            string NAME_temp;
            int OLD_temp;
            Type_of_Gender GENDER_temp; int temp;
            double MATH_SCORES_temp; 
            double PHYSICS_SCORES_temp; 
            double CHEMISTRY_SCORES_temp;

            cin.ignore(); cout <<"Nhap ten sinh vien: "; getline(cin,NAME_temp);
            database_Student[i].Set_Name(NAME_temp);

            cout <<"Nhap ten tuoi: "; cin >> OLD_temp;
            do
            {
                cout <<"Nhap ten gioi tinh(1.NAM   2.NU): ";
                cin >> temp;
            } while ((temp != 1)&&(temp != 2));
            database_Student[i].Set_Old(OLD_temp);

            if (temp == 1) 
            {
                GENDER_temp = Male; 
            }else if (temp == 2)
            {
                GENDER_temp = Female;
            }
            database_Student[i].Set_Gender(GENDER_temp);

            do
            {
                cout <<"Nhap ten diem toan (0-10): ";
                cin >> MATH_SCORES_temp;
            } while ((MATH_SCORES_temp < 0)||(MATH_SCORES_temp  > 10));
            database_Student[i].Set_Math_scores(MATH_SCORES_temp);

            do
            {
                cout <<"Nhap ten diem ly (0-10): ";
                cin >> PHYSICS_SCORES_temp;
            } while ((PHYSICS_SCORES_temp < 0)||(PHYSICS_SCORES_temp  > 10));
            database_Student[i].Set_Physics_scores(PHYSICS_SCORES_temp);

            do
            {
                cout <<"Nhap ten diem hoa (0-10): ";
                cin >> CHEMISTRY_SCORES_temp;
            } while ((CHEMISTRY_SCORES_temp < 0)||(CHEMISTRY_SCORES_temp  > 10));
            database_Student[i].Set_Chemistry_scores(CHEMISTRY_SCORES_temp);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co ID = %d khong ton tai.", ID_temp);
    }

    int out;
    enter_again:
    cout <<"------CONTINUE OR END----------"<<endl;
    cout <<"Nhan phim 1 de tiep tuc them sinh vien"<<endl;
    cout <<"Nhan phim 0 de thoat: "<<endl;
    cout <<"My choice: ";
    cin >>out;
    switch (out)
    {
    case 0:
        break;
    case 1:
        goto continue_updating;
        break;
    default:
        goto enter_again;
        break;
    }
}

void Delete_student(vector<Student>& database_Student){
    continue_deleting:
    cout<<"------------DELETE STUDENT---------------"<<endl;
    cout<<"Hien nay co "<<database_Student.size()<<" sinh vien"<<endl;
    if(!database_Student.size()) return;
    int ID_temp;
    do
    {
        cout <<"Nhap ID muon xoa (0-"<<database_Student.size()-1<<")"<<endl;
        cin >> ID_temp;
    } while ((ID_temp < 0)||(ID_temp > database_Student.size()-1));

    database_Student.erase(database_Student.begin()+ID_temp);

    int out;
    enter_again:
    cout <<"------CONTINUE OR END----------"<<endl;
    cout <<"Nhan phim 1 de tiep tuc xoa sinh vien"<<endl;
    cout <<"Nhan phim 0 de thoat: "<<endl;
    cout <<"My choice: ";
    cin >>out;
    switch (out)
    {
    case 0:
        break;
    case 1:
        goto continue_deleting;
        break;
    default:
        goto enter_again;
        break;
    }
}

void Search_student(vector<Student> database_Student){
    continue_searching:
    cout<<"------------SEARCH STUDENT---------------"<<endl;
    cout<<"Hien nay co "<<database_Student.size()<<" sinh vien"<<endl;
    if(!database_Student.size()) return;
    int ID_temp;
    do
    {
        cout <<"Nhap ID muon tim kiem (0-"<<database_Student.size()-1<<"): ";
        cin >> ID_temp;
    } while ((ID_temp < 0)||(ID_temp > database_Student.size()-1));

    for(int i=0; i < database_Student.size(); i++){
        if (i == ID_temp)
        {
            cout <<"\nSTT\tID\tHo va ten\tTuoi\tGioi tinh\tToan\tLy\tHoa\tDiem TB\tXep loai";
            cout<<"\n " << i + 1;
            cout<<"\t"<< database_Student[i].Get_ID();
            cout<<"\t"<<database_Student[i].Get_Name();
            cout<<"\t\t"<<database_Student[i].Get_Old();
            if (database_Student[i].Get_Gender() == Male) cout<<"\tNAM";
            else if(database_Student[i].Get_Gender() == Female) cout<<"\tNU";
            printf("\t\t%.2f\t%.2f\t%.2f\t%.2f", database_Student[i].Get_Math_scores(), database_Student[i].Get_Physics_scores(), database_Student[i].Get_Chemistry_scores(),database_Student[i].Get_Average_scores());
            if (database_Student[i].Get_Ability() == Excellent) cout<<"\tXUAT SAC";
            else if(database_Student[i].Get_Ability() == Good) cout<<"\tTOT";
            else if(database_Student[i].Get_Ability() == Weak) cout<<"\tYEU";
        }
    }

    int out;
    enter_again:
    cout <<"------CONTINUE OR END----------"<<endl;
    cout <<"Nhan phim 1 de tiep tuc tim kiem sinh vien"<<endl;
    cout <<"Nhan phim 0 de thoat: "<<endl;
    cout <<"My choice: ";
    cin >>out;
    switch (out)
    {
    case 0:
        break;
    case 1:
        goto continue_searching;
        break;
    default:
        goto enter_again;
        break;
    }
}

void Arrange_scores(vector<Student>& database_Student){
    cout<<"------------ARRANGE STUDENT BY SCORES---------------"<<endl;

    int choice ;
    do
    {
        cout <<"\nNhan phim 1 de sap xep tang dan";
        cout <<"\nNhan phim 2 de sap xep giam dan";
        cout <<"\nMy choice: ";
        cin >>choice;
    } while ((choice!=1)&&(choice!=2));

    if (choice == 1)
    {
        Student TEMP_database_Student = {"TAM", 0, Male, 0, 0, 0};
        int temp;
        for(int i=0; i < database_Student.size(); i++){
            for(int j = i+1; j < database_Student.size();j++){
                if(database_Student[i].Get_Average_scores() < database_Student[j].Get_Average_scores()){
                    TEMP_database_Student = database_Student[i];
                    database_Student[i] = database_Student[j];
                    database_Student[j] = TEMP_database_Student;
                }
            }
        }
    }else if (choice == 2)
    {
        Student TEMP_database_Student = {"TAM", 0, Male, 0, 0, 0};
        int temp;
        for(int i=0; i < database_Student.size(); i++){
            for(int j = i+1; j < database_Student.size();j++){
                if(database_Student[i].Get_Average_scores() > database_Student[j].Get_Average_scores()){
                    TEMP_database_Student = database_Student[i];
                    database_Student[i] = database_Student[j];
                    database_Student[j] = TEMP_database_Student;
                }
            }
        }
    }
    
    int out = 1;
    do
    {
        cout <<"\nNhan phim 0 de thoat: ";
        cin >>out;
    } while (out);
}

void Arrange_name(vector<Student>& database_Student){
    cout<<"------------ARRANGE STUDENT BY SCORES---------------"<<endl;

    Student TEMP_database_Student = {"TAM", 0, Male, 0, 0, 0};
    char TEMP_name_student1[10];
    char TEMP_name_student2[10];

    for(int i=0; i < database_Student.size(); i++) {
        database_Student[i].Get_Name().copy(TEMP_name_student1,1);
    
        for(int j = i+1; j < database_Student.size(); j++) {
            database_Student[j].Get_Name().copy(TEMP_name_student2,1);
            
            if(TEMP_name_student1[0] > TEMP_name_student2[0]) {
                TEMP_database_Student = database_Student[i];
                database_Student[i] = database_Student[j];
                database_Student[j] = TEMP_database_Student;
            }
        }
    }
    int out = 1;
    do
    {
        cout <<"\nNhan phim 0 de thoat: ";
        cin >>out;
    } while (out);
}

void Print_Infor(vector<Student> database_Student){
    cout<<"------------STUDENT LIST---------------"<<endl;
    cout <<"\nSTT\tID\tHo va ten\tTuoi\tGioi tinh\tToan\tLy\tHoa\tDiem TB\tXep loai";
    
    for(int i=0; i < database_Student.size(); i++){
        cout<<"\n " << i + 1;
        cout<<"\t"<< database_Student[i].Get_ID();
        cout<<"\t"<<database_Student[i].Get_Name();
        cout<<"\t\t"<<database_Student[i].Get_Old();
        if (database_Student[i].Get_Gender() == Male) cout<<"\tNAM";
        else if(database_Student[i].Get_Gender() == Female) cout<<"\tNU";
        printf("\t\t%.2f\t%.2f\t%.2f\t%.2f", database_Student[i].Get_Math_scores(), database_Student[i].Get_Physics_scores(), database_Student[i].Get_Chemistry_scores(),database_Student[i].Get_Average_scores());
        if (database_Student[i].Get_Ability() == Excellent) cout<<"\tXUAT SAC";
        else if(database_Student[i].Get_Ability() == Good) cout<<"\tTOT";
        else if(database_Student[i].Get_Ability() == Weak) cout<<"\tYEU";
    }
    int out = 1;
    do
    {
        cout <<"\nNhan phim 0 de thoat: ";
        cin >>out;
    } while (out);
}
