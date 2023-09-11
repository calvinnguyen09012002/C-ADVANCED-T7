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

void Student::Set_ID(){
    static int ID_Counter = 0;
    this->ID = ID_Counter;
    ID_Counter++;
}

void Student::Set_Name(){
    string name;
	cout << "Nhap ten: ";
	cin >> name;
	this->NAME = name;
}

void Student::Set_Old(){
    double old;
	cout << "Nhap tuoi(10-100): ";
	cin >> old;
	while (!(old > 10 && old < 100))
	{
		cout << "Tuoi khong chinh xac. Vui long nhap lai." << endl;
		cout << "Nhap tuoi: ";
		cin >> old;
	}
	this->OLD = old;
}

void Student::Set_Gender(){
    int gender;
	cout << "Nhap gioi tinh (0:Nam/1:Nu): ";
	cin >> gender;
	while (!(gender == Male|| gender == Female))
	{
		cout << "Gioi tinh khong chinh xac. Vui long nhap lai." << endl;
		cout << "Nhap gioi tinh (Nam/Nu): ";
		cin >> gender;
	}
	this->GENDER = enumGender((Type_of_Gender)gender);

}

void Student::Set_Math_scores(){
    double diemToan;
	cout << "Nhap diem toan: ";
	cin >> diemToan;
	while (!(diemToan >= 0 && diemToan <= 10))
	{
		cout << "Diem toan khong chinh xac. Vui long nhap lai." << endl;
		cout << "Nhap diem toan: ";
		cin >> diemToan;
	}
	this->MATH_SCORES = diemToan;
}

void Student::Set_Physics_scores(){
    double diemLy;
	cout << "Nhap diem ly: ";
	cin >> diemLy;
	while (!(diemLy >= 0 && diemLy <= 10))
	{
		cout << "Diem ly khong chinh xac. Vui long nhap lai." << endl;
		cout << "Nhap diem ly: ";
		cin >> diemLy;
	}
	this->PHYSICS_SCORES = diemLy;
}

void Student::Set_Chemistry_scores(){
    double diemHoa;
	cout << "Nhap diem hoa: ";
	cin >> diemHoa;
	while (!(diemHoa >= 0 && diemHoa <= 10))
	{
		cout << "Diem hoa khong chinh xac. Vui long nhap lai." << endl;
		cout << "Nhap diem hoa: ";
		cin >> diemHoa;
	}
	this->CHEMISTRY_SCORES = diemHoa;
}

void Student::Set_Average_scores(){
    this->AVERAGE_SCORES = (this->MATH_SCORES + this->PHYSICS_SCORES + this->CHEMISTRY_SCORES) / 3;
}

void Student::Set_Ability(){
    int diem;
	if (this->AVERAGE_SCORES >= 9)
		diem = Excellent;
	else if (this->AVERAGE_SCORES >= 7)
		diem = Good;
	else
		diem = Weak;
	this->ABILITY = enumAbility((Type_of_Ability) diem);
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

string Student::Get_Gender(){
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
    return AVERAGE_SCORES;
}

string Student::Get_Ability(){
    return ABILITY;
}

//--------------FUNCTION------------------------------
void Add_student(vector<Student>& database_Student){
    continue_adding:
    Student student;
    cout<<"-------------------------------------ADD STUDENT--------------------------------------"<<endl;
    student.Set_ID();
    student.Set_Name();
    student.Set_Old();
    student.Set_Gender();
    student.Set_Math_scores();
    student.Set_Physics_scores();
    student.Set_Chemistry_scores();
    student.Set_Average_scores();
    student.Set_Ability();

    
    database_Student.push_back(student);

    cout << endl;
	cout << "Them sinh vien thanh cong." << endl;


    int out;
    enter_again:
    cout <<"-------------------------------------CONTINUE OR END--------------------------------------"<<endl;
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
    cout<<"-------------------------------------UPDATE STUDENT--------------------------------------"<<endl;
    cout<<"Hien nay co "<<database_Student.size()<<" sinh vien, gom co cac ID sau:"<<endl;

    for(int i=0; i < database_Student.size(); i++){
            cout << database_Student[i].Get_ID()<<"  ";     
    }
    cout << endl;

    if(!database_Student.size()) return;

    int ID_temp;

    cout <<"Nhap ID muon cap nhat: ";
    cin >> ID_temp;


    int found = 0;
    for(int i=0; i < database_Student.size(); i++) {
        if (database_Student[i].Get_ID() == ID_temp) {
            found = 1;
            cout << "\n-------------------------------------UPDATE STUDENT--------------------------------------" <<endl;

            thongTinCapNhat:
				cout << "Thong tin sinh vien muon cap nhat" << endl;
				cout << "0. Quay lai" << endl;
				cout << "1. Cap nhat ten" << endl;
				cout << "2. Cap nhat tuoi" << endl;
				cout << "3. Cap nhat gioi tinh" << endl;
				cout << "4. Cap nhat diem" << endl;

			capNhatSV:
				int key;
				cout << "Nhap lua chon: ";
				cin >> key;

				switch (key)
				{
				case 0:
					goto thongTinCapNhat;
				case 1:
					database_Student[i].Set_Name();
					cout << "Nhap ten moi thanh cong." << endl;
					break;
				case 2:
					database_Student[i].Set_Old();
					cout << "Nhap tuoi moi thanh cong." << endl;
					break;
				case 3:
					database_Student[i].Set_Gender();
					cout << "Nhap gioi tinh moi thanh cong." << endl;
					break;
				case 4:
					cout << "Chon diem can cap nhat: " << endl;
					cout << "0. Quay lai" << endl;
					cout << "1. Toan" << endl;
					cout << "2. Ly" << endl;
					cout << "3. Hoa" << endl;
				capNhatDiem:
					int keyDiem;
					cout << "Nhap lua chon: ";
					cin >> keyDiem;
					switch (keyDiem)
					{
					case 0:
						goto thongTinCapNhat;
					case 1:
						database_Student[i].Set_Math_scores();
						cout << "Nhap diem toan moi thanh cong." << endl;
						break;
					case 2:
						database_Student[i].Set_Physics_scores();
						cout << "Nhap diem ly moi thanh cong." << endl;
						break;
					case 3:
						database_Student[i].Set_Chemistry_scores();
						cout << "Nhap diem hoa moi thanh cong." << endl;
						break;
					default:
						cout << "Lua chon khong hop le." << endl;
						goto capNhatDiem;
					}
					break;
				default:
					cout << "Lua chon khong hop le." << endl;
					goto capNhatSV;
            }
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co ID = %d khong ton tai.", ID_temp);
    }

    int out;
    enter_again:
    cout <<"-------------------------------------CONTINUE OR END--------------------------------------"<<endl;
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
    cout<<"-------------------------------------DELETE STUDENT--------------------------------------"<<endl;
    cout<<"Hien nay co "<<database_Student.size()<<" sinh vien, gom co cac ID sau:"<<endl;

    for(int i=0; i < database_Student.size(); i++){
            cout << database_Student[i].Get_ID()<<"  ";     
    }
    cout << endl;

    if(!database_Student.size()) return;
    int ID_temp;
    do
    {
        cout <<"Nhap ID muon xoa: "<<endl;
        cin >> ID_temp;
    } while ((ID_temp < 0)||(ID_temp > database_Student.size()-1));

    database_Student.erase(database_Student.begin()+ID_temp);

    int out;
    enter_again:
    cout <<"-------------------------------------CONTINUE OR END--------------------------------------"<<endl;
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
    cout<<"-------------------------------------SEARCH STUDENT--------------------------------------"<<endl;
    cout<<"Hien nay co "<<database_Student.size()<<" sinh vien, gom co cac ID sau:"<<endl;

    for(int i=0; i < database_Student.size(); i++){
            cout << database_Student[i].Get_ID()<<"  ";     
    }
    cout << endl;

    cout<<"Hien nay co "<<database_Student.size()<<" sinh vien"<<endl;
    if(!database_Student.size()) return;
    int ID_temp;

    cout <<"Nhap ID muon tim kiem: ";
    cin >> ID_temp;


    for(int i=0; i < database_Student.size(); i++){
        if (i == ID_temp)
        {
             printf(" ID\tTen\t\tTuoi\tGioi tinh\tToan\tLy\tHoa\tTB\tHoc luc\n");
	    printf("--------------------------------------------------------------------------------------\n");
            printf(" %d\t%-7s\t\t%d\t%s\t\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n",
                database_Student[i].Get_ID(), database_Student[i].Get_Name().c_str(), database_Student[i].Get_Old(),
                database_Student[i].Get_Gender().c_str(), database_Student[i].Get_Math_scores(),
                database_Student[i].Get_Physics_scores(), database_Student[i].Get_Chemistry_scores(),
                database_Student[i].Get_Average_scores(), database_Student[i].Get_Ability().c_str());
        }
    }

    int out;
    enter_again:
    cout <<"-------------------------------------CONTINUE OR END--------------------------------------"<<endl;
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
    cout<<"-------------------------------------ARRANGE STUDENT BY SCORES--------------------------------------"<<endl;

    if (!database_Student.empty())
	{
        int choice ;
        do
        {
            cout <<"\nNhan phim 1 de sap xep tang dan";
            cout <<"\nNhan phim 2 de sap xep giam dan";
            cout <<"\nMy choice: ";
            cin >>choice;
        } while ((choice!=1)&&(choice!=2));

        if (choice == 1){
            int i, j, minIndex;
            for (i = 0; i < database_Student.size() - 1; i++)
            {
                minIndex = i;
                for (j = i + 1; j < database_Student.size(); j++)
                {
                    if (database_Student[j].Get_Average_scores() < database_Student[minIndex].Get_Average_scores())
                        minIndex = j;
                }
                Student temp = database_Student[minIndex];
                database_Student[minIndex] = database_Student[i];
                database_Student[i] = temp;
            }
            cout << "Sap Xep theo diem TB tang dan thanh cong." << endl;
            cout << endl;
        }
        else if (choice == 2){
            int i, j, maxIndex;
            for (i = 0; i < database_Student.size() - 1; i++)
            {
                maxIndex = i;
                for (j = i + 1; j < database_Student.size(); j++)
                {
                    if (database_Student[j].Get_Average_scores() > database_Student[maxIndex].Get_Average_scores())
                        maxIndex = j;
                }
                Student temp = database_Student[maxIndex];
                database_Student[maxIndex] = database_Student[i];
                database_Student[i] = temp;
            }
            cout << "Sap Xep theo diem TB giam dan thanh cong." << endl;
            cout << endl;
        }
    }
	
	else{
		cout << "Danh sach rong." << endl;
		cout << endl;
	}

    int out = 1;
    do{
        cout <<"\nNhan phim 0 de thoat: ";
        cin >>out;
    } while (out);
}

void Arrange_name(vector<Student>& database_Student){
    cout<<"-------------------------------------ARRANGE STUDENT BY NAME--------------------------------------"<<endl;

    if (!database_Student.empty())
	{
		int i, j, minIndex;
		for (i = 0; i < database_Student.size() - 1; i++)
		{
			minIndex = i;
			for (j = i + 1; j < database_Student.size(); j++)
			{
				if (database_Student[j].Get_Name() < database_Student[minIndex].Get_Name())
					minIndex = j;
			}
			Student temp = database_Student[minIndex];
			database_Student[minIndex] = database_Student[i];
			database_Student[i] = temp;
		}
		cout << "Sap xep theo ten thanh cong." << endl;
		cout << endl;
	}
	else
	{
		cout << "Danh sach rong." << endl;
		cout << endl;
	}
    
    int out = 1;
    do
    {
        cout <<"\nNhan phim 0 de thoat: ";
        cin >>out;
    } while (out);
}

void Print_Infor(vector<Student> database_Student){
    cout<<"-------------------------------------STUDENT LIST--------------------------------------"<<endl;

    if (!database_Student.empty())
	{
	    printf(" ID\tTen\t\tTuoi\tGioi tinh\tToan\tLy\tHoa\tTB\tHoc luc\n");
	    printf("---------------------------------------------------------------------------------------\n");
		for (int i = 0; i < database_Student.size(); i++)
		{
			printf(" %d\t%-7s\t\t%d\t%s\t\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n",
                database_Student[i].Get_ID(), database_Student[i].Get_Name().c_str(), database_Student[i].Get_Old(),
                database_Student[i].Get_Gender().c_str(), database_Student[i].Get_Math_scores(),
                database_Student[i].Get_Physics_scores(), database_Student[i].Get_Chemistry_scores(),
                database_Student[i].Get_Average_scores(), database_Student[i].Get_Ability().c_str());
		}
	}
	else
		cout << "Danh sach rong." << endl;


    int out = 1;
    do
    {
        cout <<"\nNhan phim 0 de thoat: ";
        cin >>out;
    } while (out);
}