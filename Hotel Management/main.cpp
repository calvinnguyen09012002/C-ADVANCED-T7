/*
 * File Name: main.cpp
 * Author: Nguyen Gia Phuc
 * Date: 12/09/2023
 * Description: Manage a hotel's system
 */

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<time.h>

using namespace std;

typedef enum{
    EXIT                    			= 0,
    BOOK_ROOM               			= 1,
    CUSTOMER_MANAGEMENT    				= 2,
    STAFF_MANAGEMENT        			= 3,
    PAYMENT                 			= 4,
    SECURITY_AND_ACCESS     			= 5,
    REPORT_AND_STATISTIC    			= 6,
    MANAGEMENT_AND_RESPONSE_FEEDBACK    = 7
}Type_Mode_of_Manager;

typedef enum{
    IN,
    OUT
}Type_Status;

typedef enum{
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LAUNGGAGE_STAFF,
    GRADENER
}Type_Job_Name;

typedef struct{
    int Second;
    int Minute;
    int Hour;
}Type_Time;

typedef struct {
    int Day;
    int Month;
    int Year;
}Type_Date;

typedef struct{
    Type_Time time;
    Type_Date date;
    Type_Status status;
}Type_History_Booking;

typedef struct{
    Type_Time time;
    Type_Date date;
    Type_Status status;
}Type_Schedule;

class Room{
    private:
        int Room_Number;
        bool Reserved;
    public:
        Room(int number){
            this->Room_Number = number;
            this->Reserved = false;
        };

        int Get_Room_Number();
        bool Get_Reserved_Room();

        void Set_Status_of_Room();
        void Set_Status_after_Check_out();
};

int Room::Get_Room_Number(){
    return this->Room_Number;
}
bool Room::Get_Reserved_Room(){
    return this->Reserved;
};
void Room::Set_Status_of_Room(){
    this->Reserved = true;
};
void Room::Set_Status_after_Check_out(){
    this->Reserved = false;
};

class Customer{
private:
    int ID_Room;
    string Name;
    string Phone_Number;
    string Address;
    vector<Type_History_Booking> Booking_History;
public:
    Customer(string customerName, string customerPhone, string customerAddress, int customerIdRoom){
        this->Name = customerName;
        this->Phone_Number = customerPhone;
        this->Address = customerAddress;
        this->ID_Room = customerIdRoom;
    };
    string Get_Name();
    string Get_Phone_Number();
    string Get_Address();
    int Get_ID_Room();

    void Set_Name(string name);
    void Set_Phone_Number(string phoneNumber);
    void Set_Address(string address);
};

string Customer::Get_Name(){
    return this->Name;
}
string Customer::Get_Phone_Number(){
    return this->Phone_Number;
}
string Customer::Get_Address(){
    return this->Address;
}
int Customer::Get_ID_Room(){
    return this->ID_Room;
}
void Customer::Set_Name(string name){
    this->Name = name;
}
void Customer::Set_Phone_Number(string phoneNumber){
    this->Phone_Number = phoneNumber;
}
void Customer::Set_Address(string address){
    this->Address = address;
}

class Employee{
    private:
        int ID;
        string Name;
        string Phone_Number;
        Type_Job_Name Position;
        Type_Time Time_Start_Working;
        Type_Time Time_End_Working;
        Type_Status Status;
    public:
        Employee(string nameEmployee, string phoneNumberEmployee, Type_Job_Name positionEmployee, Type_Time timeStartWorking, Type_Time timeEndWorking){
            static int id = 100; id++;
            this->ID = id;
            this->Name = nameEmployee;
            this->Phone_Number = phoneNumberEmployee;
            this->Position = positionEmployee;
            this->Time_Start_Working = timeStartWorking;
            this->Time_End_Working = timeEndWorking;
            this->Status = OUT;
        }

        int Get_ID();
        string Get_Name();
        string Get_Phone_Number();
        Type_Job_Name Get_Position();
        Type_Time Get_Time_Start_Working();
        Type_Time Get_Time_End_Working();

        void Set_Name(string name);
        void Set_Phone_Number(string numberphone);
        void Set_Position(Type_Job_Name position);
        void Set_Time_Start_Working(Type_Time timeStartWorking);
        void Set_Time_End_Working(Type_Time timeEndWorking);
        void Set_Status(Type_Status status);
};
int Employee::Get_ID(){
	return this->ID;
}
string Employee::Get_Name(){
	return this->Name; 
}
string Employee::Get_Phone_Number(){
	return this->Phone_Number;
}
Type_Job_Name Employee::Get_Position(){
	return this->Position;
}
Type_Time Employee::Get_Time_Start_Working(){
	return this->Time_Start_Working;
}
Type_Time Employee::Get_Time_End_Working(){
	return this->Time_End_Working;
}
void Employee::Set_Name(string name){
	this->Name = name;
}
void Employee::Set_Phone_Number(string numberphone){
	this->Phone_Number = numberphone;
}
void Employee::Set_Position(Type_Job_Name position){
	this->Position = position;
}
void Employee::Set_Time_Start_Working(Type_Time timeStartWorking){
	this->Time_Start_Working = timeStartWorking;
}
void Employee::Set_Time_End_Working(Type_Time timeEndWorking){
	this->Time_End_Working = timeEndWorking;
}
void Employee::Set_Status(Type_Status status){
	this->Status = status;
}

//---------------------------------FUNCTION------------------------------------
void Customer_Management(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer);

void Print_List_of_Employee(vector<Employee> databaseEmployee);

void Employee_Management(vector<Employee>& databaseEmployee);

string Translate_Position(Type_Job_Name job);

void Edit_Infor_Customer(vector<Room>& databaseRoom, vector<Customer> databaseCustomer);

void Delete_Infor_Customer(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer);

void Update_One_Employee(vector<Employee>& databaseEmployee);

void Delete_One_Employee(vector<Employee>& databaseEmployee);

void Add_One_Employee(vector<Employee>& databaseEmployee);

void Book_Room(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer);

void Employee_Management(vector<Employee>& databaseEmployee);

int main(){
    vector<Room> databaseRoom;
    vector<Customer> databaseCustomer;
    vector<Employee> databaseEmployee;
    int key = 0;
    while(1){
        system("cls");
        cout << "----------------WELCOME---------------------\n";
        cout << "1:Dat phong\n2:Quan li khach hang\n3:Quan li nhan vien\n";
        cout << "4.Thanh toan\n5:Bao mat va quyen truy cap\n6:Bao cao va thong ke\n";
        cout << "7:Quan li va phan hoi danh gia\n0:Thoat\n\n";
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key){
            case BOOK_ROOM:
                Book_Room(databaseRoom, databaseCustomer);
                break;
            case CUSTOMER_MANAGEMENT:
                Customer_Management(databaseRoom, databaseCustomer);
                break;
            case STAFF_MANAGEMENT:
                Employee_Management(databaseEmployee);
                break;
            case PAYMENT:
                break;
            case SECURITY_AND_ACCESS:
                break;
            case REPORT_AND_STATISTIC:
                break;
            case MANAGEMENT_AND_RESPONSE_FEEDBACK:
                break;
            case EXIT:
                return 0;
                break;
            default:
                break;
        }
    }

    return 0;
}

//---------------------------------FUNCTION------------------------------------
string Translate_Position(Type_Job_Name job){
    switch (job)
    {
    case JANITOR:
        /* code */
        return "JANITOR";
        break;
    case RECEPTIONIST:
        /* code */
        return "RECEPTIONIST";
        break;
    case LAUNDRY_STAFF:
        /* code */
        return "LAUNDRY_STAFF";
        break;
    case LAUNGGAGE_STAFF:
        /* code */
        return "LAUNGGAGE_STAFF";
        break;
    case GRADENER:
        /* code */
        return "GRADENER";
        break;
    default:
        break;
    }
    return "";
}

void Edit_Infor_Customer(vector<Room>& databaseRoom, vector<Customer> databaseCustomer){
    system("cls");
    int stt;
    int key, key1;
    bool flag = 0;
    bool continueEdit = 1;
    string temp;
    cout << "Nhap STT khach hang: ";
    cin >> stt;
    cout << "1:Sua ten\n2:Sua sdt\n3:Sua dia chi\n0: Quay lai\n\n";
    while (continueEdit){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            cout << "Nhap ten: ";
            cin.ignore();
            getline(cin, temp);
            databaseCustomer[stt-1].Set_Name(temp);
            flag = 1;
            break;
        case 2:
            system("cls");
            cout << "Nhap sdt: ";
            cin.ignore();
            getline(cin, temp);
            databaseCustomer[stt-1].Set_Phone_Number(temp);
            flag = 1;
            break;
        case 3:
            system("cls");
            cout << "Nhap dia chi: ";
            cin.ignore();
            getline(cin, temp);
            databaseCustomer[stt-1].Set_Address(temp);
            flag = 1;
            break;
        case 0:
            Customer_Management(databaseRoom, databaseCustomer);
            return;
            break;
        default:
            break;
        }
        if (flag){
            cout << "Chinh sua thanh cong\n\n";
            cout << "1: Tiep tuc\n0:Quay lai\n";
            cout << "Nhap lua chon: \n";
            cin >> key1;
            if (key1 == 1){
                Edit_Infor_Customer(databaseRoom, databaseCustomer);
                return;
            }else{
                Customer_Management(databaseRoom, databaseCustomer);
                return;
            }
        }
    }

}

void Delete_Infor_Customer(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer){

    system("cls");
    int stt, i;
    int key;
    string key1;
    bool flag = 0;
    bool continueEdit = 1;
    string temp;
    cout << "Nhap STT khach hang: ";
    cin >> stt;
    cout << "1:Chan chan xoa\n0:Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: \n";
        cin >> key;
        switch (key)
        {
        case 1:
            for (i = 0; i < databaseRoom.size(); i++){
                if (databaseRoom[i].Get_Room_Number() == databaseCustomer[stt].Get_ID_Room()) break;
            }
            databaseRoom[i].Set_Status_after_Check_out();
            databaseCustomer.erase(databaseCustomer.begin() + stt - 1);
            system("cls");
            cout << "Xoa thong tin thanh cong!!!\n";
            cout << "Nhan phim bat ki de quay lai\n";
            cin >> key1;
            return;
            break;
        case 0:
            Delete_Infor_Customer(databaseRoom, databaseCustomer);
            return;
            break;
        default:
            break;
        }
    }

    
}

void Update_One_Employee(vector<Employee>& databaseEmployee){
    system("cls");
    int i, columnWidth = 20, id, key, key1;
    bool flag = 0;
    string temp;

    cout << "----------------Danh sach nhan vien---------------------\n\n";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Ho va ten";
    cout << setw(columnWidth) << left << "So dien thoai";
    cout << setw(columnWidth) << left << "Vi tri";
    cout << setw(columnWidth) << left << "Thoi gian bat dau";
    cout << setw(columnWidth) << left << "Thoi gian ket thuc";
    cout << endl;
    for (i = 0; i < databaseEmployee.size(); i++){
        cout << setw(columnWidth) << left << databaseEmployee[i].Get_ID();
        cout << setw(columnWidth) << left << databaseEmployee[i].Get_Name();
        cout << setw(columnWidth) << left << databaseEmployee[i].Get_Phone_Number();
        cout << setw(columnWidth) << left << Translate_Position(databaseEmployee[i].Get_Position());
        cout << databaseEmployee[i].Get_Time_Start_Working().Hour << ":" << databaseEmployee[i].Get_Time_Start_Working().Minute << ":" << setw(columnWidth) << left << databaseEmployee[i].Get_Time_Start_Working().Second;
        cout << databaseEmployee[i].Get_Time_End_Working().Hour << ":" << databaseEmployee[i].Get_Time_End_Working().Minute << ":" << databaseEmployee[i].Get_Time_End_Working().Second;
        cout << endl;
    }
    cout << endl;

    cout << "Nhap ID nhan vien can chinh sua: ";
    cin >> id;
    for (i = 0; i < databaseEmployee.size(); i++){
        if (databaseEmployee[i].Get_ID() == id) break;
    }
    if (i == databaseEmployee.size()){
        cout << "Khong tim thay ID\n";
        while (1){
            cout << "Nhan 0 de quay lai: ";
            cin >> key;
            if (key == 0){return;}
        }
    }
    cout << "1:Sua ten\n2:Sua sdt\n3:Sua vi tri\n4:Thoi gian bat dau\n5:Thoi gian ket thuc\n0: Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            cout << "Nhap ten: ";
            cin.ignore();
            getline(cin, temp);
            databaseEmployee[i].Set_Name(temp);
            flag = 1;
            break;
        case 2:
            system("cls");
            cout << "Nhap sdt: ";
            cin.ignore();
            getline(cin, temp);
            databaseEmployee[i].Set_Phone_Number(temp);
            flag = 1;
            break;
        case 3:
            system("cls");
            cout << "Chon vi tri:\n";
            cout << "1.JANITOR\n2.RECEPTIONIST\n3.LAUNDRY_STAFF\n4.LAUNGGAGE_STAFF\n5.GRADENER\n";
            int temp1;
            Type_Job_Name position;
            cin >> temp1;
            switch (temp1)
            {
            case 1:
                position = JANITOR;
                break;
            case 2:
                position = RECEPTIONIST;
                break;
            case 3:
                position = LAUNDRY_STAFF;
                break;
            case 4:
                position = LAUNGGAGE_STAFF;
                break;
            case 5:
                position = GRADENER;
                break;
            default:
                break;
            }
            databaseEmployee[i].Set_Position(position);
            flag = 1;
            break;
        case 4:
            system("cls");
            Type_Time timeStart;
            cout << "Nhap gio: ";
            cin >> timeStart.Hour;
            cout << "Nhap phut: ";
            cin >> timeStart.Minute;
            timeStart.Second = 0;
            databaseEmployee[i].Set_Time_Start_Working(timeStart);
            flag = 1;
            break;
        case 5:
            system("cls");
            Type_Time timeEnd;
            cout << "Nhap gio: ";
            cin >> timeEnd.Hour;
            cout << "Nhap phut: ";
            cin >> timeEnd.Minute;
            timeEnd.Second = 0;
            databaseEmployee[i].Set_Time_End_Working(timeEnd);
            flag = 1;
            break;
        case 0:
            Employee_Management(databaseEmployee);
            return;
            break;
        default:
            break;
        }
        if (flag){
            cout << "Chinh sua thanh cong\n\n";
            cout << "1: Tiep tuc\n0:Quay lai\n";
            cout << "Nhap lua chon: \n";
            cin >> key1;
            if (key1 == 1){
                Employee_Management(databaseEmployee);
                return;
            }else{
                return;
            }
        }
    }
}

void Delete_One_Employee(vector<Employee>& databaseEmployee){
    system("cls");
    int id, i;
    int columnWidth = 20;
    int key;
    
    cout << "----------------Danh sach nhan vien---------------------\n\n";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Ho va ten";
    cout << setw(columnWidth) << left << "So dien thoai";
    cout << setw(columnWidth) << left << "Vi tri";
    cout << setw(columnWidth) << left << "Thoi gian bat dau";
    cout << setw(columnWidth) << left << "Thoi gian ket thuc";
    cout << endl;
    for (i = 0; i < databaseEmployee.size(); i++){
        cout << setw(columnWidth) << left << databaseEmployee[i].Get_ID();
        cout << setw(columnWidth) << left << databaseEmployee[i].Get_Name();
        cout << setw(columnWidth) << left << databaseEmployee[i].Get_Phone_Number();
        cout << setw(columnWidth) << left << Translate_Position(databaseEmployee[i].Get_Position());
        cout << databaseEmployee[i].Get_Time_Start_Working().Hour << ":" << databaseEmployee[i].Get_Time_Start_Working().Minute << ":" << setw(columnWidth) << left << databaseEmployee[i].Get_Time_Start_Working().Second;
        cout << databaseEmployee[i].Get_Time_End_Working().Hour << ":" << databaseEmployee[i].Get_Time_End_Working().Minute << ":" << databaseEmployee[i].Get_Time_End_Working().Second;
        cout << endl;
    }
    cout << endl;

    cout << "Nhap ID nhan vien can xoa: ";
    cin >> id;
    for (i = 0; i < databaseEmployee.size(); i++){
        if (databaseEmployee[i].Get_ID() == id) break;
    }
    if (i == databaseEmployee.size()){
        cout << "Khong tim thay ID\n";
        while (1){
            cout << "Nhan 0 de quay lai: ";
            cin >> key;
            if (key == 0){return;}
        }
    }

    while (1){
        system("cls");
        cout << "          Ban co chac chan khong?\n";
        cout << "          ________________________\n";
        cout << "          1: Co\n          2: Khong\n";
        cout << "          ________________________\n";
        cout << "          Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            databaseEmployee.erase(databaseEmployee.begin() + i);
            system("cls");
            cout << "          __________Xoa thanh cong___________\n";
            while (1){
                cout << "          ________________________\n";
                cout << "          1: Tiep tuc xoa\n";
                cout << "          0: Quay lai\n\n";
                cout << "          ________________________\n";
                cout << "          Nhap lua chon: ";
                cin >> key;
                switch (key)
                {
                case 1:
                    Delete_One_Employee(databaseEmployee);
                    return;
                    break;
                case 0:
                    return;
                    break;
                default:
                    cout << "Phim nay khong hop le\n";
                    break;
                }
            }
            return;
            break;
        case 2:
            Delete_One_Employee(databaseEmployee);
            return;
            break;
        default:
            cout << "Phim nay khong hop le\n";
            break;
        }
    }
}

void Add_One_Employee(vector<Employee>& databaseEmployee){
    system("cls");
    cout << "----------------Them nhan vien---------------------\n\n";
    cout << "Nhap ten: ";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << "Nhap sdt: ";
    string sdt;
    //cin.ignore();
    getline(cin, sdt);
    cout << "Chon vi tri:\n";
    cout << "1.JANITOR\n2.RECEPTIONIST\n3.LAUNDRY_STAFF\n4.LAUNGGAGE_STAFF\n5.GRADENER\n";
    int temp;
    Type_Job_Name position;
    cin >> temp;
    switch (temp)
    {
    case 1:
        position = JANITOR;
        break;
    case 2:
        position = RECEPTIONIST;
        break;
    case 3:
        position = LAUNDRY_STAFF;
        break;
    case 4:
        position = LAUNGGAGE_STAFF;
        break;
    case 5:
        position = GRADENER;
        break;
    default:
        break;
    }
    Type_Time timeStart;
    cout << "Gio bat dau: ";
    cin >> timeStart.Hour;
    cout << "Phut bat dau: ";
    cin >> timeStart.Minute;
    timeStart.Second = 0;

    Type_Time timeEnd;
    cout << "Gio ket thuc: ";
    cin >> timeEnd.Hour;
    cout << "Phut ket thuc: ";
    cin >> timeEnd.Minute;
    timeEnd.Second = 0;

    Employee tempEmployee = {name, sdt, position, timeStart, timeEnd};
    databaseEmployee.push_back(tempEmployee);

    cout << "Them thanh cong!!!\n";
    cout << "Nhap phim bat ky de quay lai: ";
    string temp4;
    cin >> temp4;
    return;
}

void Print_List_of_Employee(vector<Employee> databaseEmployee){
    system("cls");
    int i;
    int columnWidth = 20;
    int key = -1;
    cout << "----------------Danh sach nhan vien---------------------\n\n";
    cout << setw(columnWidth) << left << "ID";
    cout << setw(columnWidth) << left << "Ho va ten";
    cout << setw(columnWidth) << left << "So dien thoai";
    cout << setw(columnWidth) << left << "Vi tri";
    cout << setw(columnWidth) << left << "Thoi gian bat dau";
    cout << setw(columnWidth) << left << "Thoi gian ket thuc";
    cout << endl;
    for (i = 0; i < databaseEmployee.size(); i++){
        cout << setw(columnWidth) << left << databaseEmployee[i].Get_ID();
        cout << setw(columnWidth) << left << databaseEmployee[i].Get_Name();
        cout << setw(columnWidth) << left << databaseEmployee[i].Get_Phone_Number();
        cout << setw(columnWidth) << left << Translate_Position(databaseEmployee[i].Get_Position());
        cout << databaseEmployee[i].Get_Time_Start_Working().Hour << ":" << databaseEmployee[i].Get_Time_Start_Working().Minute << ":" << setw(columnWidth) << left << databaseEmployee[i].Get_Time_Start_Working().Second;
        cout << databaseEmployee[i].Get_Time_End_Working().Hour << ":" << databaseEmployee[i].Get_Time_End_Working().Minute << ":" << databaseEmployee[i].Get_Time_End_Working().Second;
        cout << endl;
    }
    cout << endl;
    cout << "Nhap phim bat ky de quay lai: ";
    string temp;
    cin >> temp;
    return;
}

void Book_Room(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer){
    system("cls");
    int i;
    int columnWidth = 20;
    string out_prog;
    while (1){
        int key = -1;
        cout << "----------------Dat phong---------------------\n\n";
        cout << "1:Thiet lap so phong\n";
        cout << "2:Tien hanh dat phong\n";
        cout << "0:Quay lai\n\n";
        cout << "Nhap lua chon: ";

        cin >> key;
        switch (key)
        {
        case 1:
            system("cls");
            cout << "Nhap so phong: ";
            int numberRoomTemp;
            cin >> numberRoomTemp;
            {
                Room roomTemp = {numberRoomTemp};
                databaseRoom.push_back(roomTemp);
            }
            cout << "Thiet lap so phong thanh cong!!!\n";
            while (1){
                cout << "Nhan so bat ky de quay lai: ";
                int key1;
                cin >> key1;
                break;
            }
            break;
        case 2:
            system("cls");
            cout << "----------------Tien hanh dat phong---------------------\n\n";
            if (databaseRoom.size() == 0){
                cout << "Hien tai khong co phong\n";
                while (1){
                    cout << "Nhan so bat ky de quay lai: ";
                    int key1;
                    cin >> key1;
                    break;
                }
            }else{
                cout << setw(columnWidth) << left << "So phong";
                cout << setw(columnWidth) << left << "Trang thai";
                cout << endl;
                for (i = 0; i < databaseRoom.size(); i++){
                    cout << setw(columnWidth) << left << databaseRoom[i].Get_Room_Number();
                    cout << setw(columnWidth) << left << databaseRoom[i].Get_Reserved_Room();
                    cout << endl;
                }

                cout << endl;
                cout << "1:Nhap so phong\n";
                cout << "0:Quay lai\n\n";
                int key3;
                while (1){
                    cout << "Nhap lua chon: ";
                    cin >> key3;
                    switch (key3)
                    {
                    case 1:
                        system("cls");
                        cout << "Nhap so phong: ";
                        int numberRoomTemp;
                        cin >> numberRoomTemp;
                        for (i = 0; i , databaseRoom.size(); i++){
                            if (numberRoomTemp == databaseRoom[i].Get_Room_Number()){break;}
                        }
                        if (databaseRoom[i].Get_Reserved_Room()){
                            system("cls");
                            cout << "Phong nay da duoc dat!!!\n";
                            cout << "Nhan phim bat ky de quay lai: ";
                            cin >> out_prog;

                        }else{
                            system("cls");
                            cout << "----------------Tien hanh dat phong---------------------\n\n";
                            cout << "Nhap ten: ";
                            string name;
                            cin.ignore();
                            getline(cin, name);
                            cout << "Nhap sdt: ";
                            string sdt;
                            //cin.ignore();
                            getline(cin, sdt);
                            cout << "Nhap dia chi: ";
                            string address;
                            //cin.ignore();
                            getline(cin, address);
                            Customer customerTemp(name, sdt, address, numberRoomTemp);
                            databaseCustomer.push_back(customerTemp);
                            databaseRoom[i].Set_Status_of_Room();
                            system("cls");
                            cout << "----------------Dat phong thanh cong---------------------\n\n";
                            cout << "1:Tiep tuc dat phong\n";
                            cout << "0:Quay lai\n\n";
                            while (1)
                            {
                                cout << "Nhap lua chon: ";
                                int key4;
                                cin >> key4;
                                switch (key4)
                                {
                                case 1:
                                    Book_Room(databaseRoom, databaseCustomer);
                                    return;
                                    break;
                                case 0:
                                    return;
                                    break;
                                default:
                                    break;
                                }
                            }
                        }
                        break;
                    case 0:
                        return;
                        break;
                    default:
                        break;
                    }
                }
            }
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    }
}

void Customer_Management(vector<Room>& databaseRoom, vector<Customer>& databaseCustomer){
    system("cls");
    int i;
    int columnWidth = 20;
    int key = -1;
    cout << "----------------Quan li khach hang---------------------\n\n";
    cout << setw(columnWidth) << left << "STT";
    cout << setw(columnWidth) << left << "ID Phong";
    cout << setw(columnWidth) << left << "Ho va ten";
    cout << setw(columnWidth) << left << "So dien thoai";
    cout << setw(columnWidth) << left << "Dia chi";
    cout << endl;
    for (i = 0; i < databaseCustomer.size(); i++){
        cout << setw(columnWidth) << left << i + 1;
        cout << setw(columnWidth) << left << databaseCustomer[i].Get_ID_Room();
        cout << setw(columnWidth) << left << databaseCustomer[i].Get_Name();
        cout << setw(columnWidth) << left << databaseCustomer[i].Get_Phone_Number();
        cout << setw(columnWidth) << left << databaseCustomer[i].Get_Address();
        cout << endl;
    }

    cout << endl;
    cout << "1:Chinh sua thong tin\n";
    cout << "2:Xoa thong tin\n";
    cout << "0:Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            Edit_Infor_Customer(databaseRoom, databaseCustomer);
            return;
            break;
        case 2:
            Delete_Infor_Customer(databaseRoom, databaseCustomer);
            return;
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    }
}

void Employee_Management(vector<Employee>& databaseEmployee){
    system("cls");
    int i;
    int columnWidth = 20;
    int key = -1;
    cout << "----------------Quan li nhan vien---------------------\n\n";

    cout << "1:Chinh sua nhan vien\n";
    cout << "2:Xoa nhan vien\n";
    cout << "3:Them nhan vien\n";
    cout << "4:In danh sach nhan vien\n";
    cout << "0:Quay lai\n\n";
    while (1){
        cout << "Nhap lua chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            Update_One_Employee(databaseEmployee);
            return;
            break;
        case 2:
            Delete_One_Employee(databaseEmployee);
            return;
            break;
        case 3:
            Add_One_Employee(databaseEmployee);
            return;
            break;
        case 4:
            Print_List_of_Employee(databaseEmployee);
            return;
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    }
}
