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

string enumAbility(Type_of_Ability a){
    string strHocLuc;
	switch (a)
	{
	case Excellent:
		strHocLuc = "Xuat sac";
		break;
	case Good:
		strHocLuc = "Gioi";
		break;
	case Weak:
		strHocLuc = "Yeu";
		break;
	}
	return strHocLuc;
}

typedef enum{
    Male = 0,
    Female = 1
} Type_of_Gender;

string enumGender(Type_of_Gender g){
    string strGioiTinh;
	switch (g)
	{
	case Male:
		strGioiTinh = "Nam";
		break;
	case Female:
		strGioiTinh = "Nu";
		break;
	}
	return strGioiTinh;
}

class Student{
    private:
        int ID ;
        string NAME;
        int OLD;
        string GENDER;
        double MATH_SCORES; 
        double PHYSICS_SCORES; 
        double CHEMISTRY_SCORES;
        double AVERAGE_SCORES;
	    string ABILITY; 
    public:
        void Set_ID();
        void Set_Name();
        void Set_Old();
        void Set_Gender();
        void Set_Math_scores();
        void Set_Physics_scores();
        void Set_Chemistry_scores();
        void Set_Average_scores();
        void Set_Ability();

        int Get_ID();
        string Get_Name();
        int Get_Old();
        string Get_Gender();
        double Get_Math_scores();
        double Get_Physics_scores();
        double Get_Chemistry_scores();
        double Get_Average_scores();
        string Get_Ability();
};

//--------------FUNCTION----------------------
void Add_student(vector<Student>& database_Student);
void Add_student(vector<Student>& database_Student);
void Update_student(vector<Student>& database_Student);
void Delete_student(vector<Student>& database_Student);
void Arrange_scores(vector<Student>& database_Student);
void Arrange_name(vector<Student>& database_Student);
void Search_student(vector<Student> database_Student);
void Print_Infor(vector<Student> database_Student);
