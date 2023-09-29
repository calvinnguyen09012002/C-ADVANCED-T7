/*
 * File Name: main.cpp
 * Author: Nguyen Gia Phuc
 * Date: 25/09/2023
 * Description: Electrical car
 */
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>

using namespace std;

typedef enum{
    MAX = 100,
    MIN = 20
}Type_of_Batery_level;

/*-------------------------Class---------------------------*/
class Battery_Management{
    private:
        int Bat_Capacity;
        int Bat_Temperature;
        bool Status_Fan;
    public:
        Battery_Management(int bat_cap, int bat_temp);
        int Get_Bat_Capacity();
        int Get_Bat_Temperature();
        bool Get_Status_Fan();

        void Set_Bat_Capacity(int bat_cap);
        void Set_Bat_Temperature(int bat_temp);
        void Set_Status_Fan(bool status);

};

Battery_Management::Battery_Management(int bat_cap, int bat_temp){
    this->Bat_Capacity = bat_cap;
    this->Bat_Temperature = bat_temp;
    if (this->Bat_Temperature > 50)
    {
        this->Status_Fan = true;
    }else this->Status_Fan = false;  
};

void Battery_Management::Set_Bat_Capacity(int bat_cap){
    this->Bat_Capacity = bat_cap;
};

void Battery_Management::Set_Bat_Temperature(int bat_temp){
    this->Bat_Temperature = bat_temp;
    if (this->Bat_Temperature > 50)
    {
        this->Status_Fan = true;
    }else this->Status_Fan = false; 
};

void Battery_Management::Set_Status_Fan(bool status){
    this->Status_Fan = status;
};

int Battery_Management::Get_Bat_Capacity(){
    return this->Bat_Capacity;
}

int Battery_Management::Get_Bat_Temperature(){
    return this->Bat_Temperature;
}

bool Battery_Management::Get_Status_Fan(){
    return this->Status_Fan;
}

/*-------------------------Function---------------------------*/
//Hiển thị tín hiệu rẽ trái.
void Turn_left_display(bool*turn_left_signal);

//Hiển thị tín hiệu rẽ phải.
void Turn_right_display(bool*turn_right_signal);

//Hiển thị trạng thái quạt.
void Status_Fan_display(bool status_fan);

//Thay đổi tín hiệu báo rẽ trái hoặc phải.
void Changed_turn_signal(bool*status,bool*status_opposite);

//Thay đổi trạng thái hoạt động của xe.
void Changed_status_car(bool*status_car);

//Hiển thị thông tin các tín hiệu báo rẽ trái hoặc phải trên bảng điều khiển.
void Infor_signal_display(bool*left, bool*right, bool*status_car);

//Hiển thị thông tin tốc độ trên bảng điều khiển.
void Infor_speed_display(int*speed, bool*status_car);

//Hiển thị thông tin quạt trên bảng điều khiển.
void Infor_fan_display(Battery_Management*tram, bool*status_car);

//Hiển thị trạng thái xe trên bảng điểu khiển.
void Infor_car_display(bool*status_car);

//Ghi nhận nhiệt độ của pin sau mỗi 5s và điều chỉnh trạng thái quạt cho phù hợp.
void Fan_mode(Battery_Management*tram);

//Điều chỉnh trạng thái của pin khi bth và khi xạc.
void Battery_mode(Battery_Management*tram, bool*charge, bool*status_car);

//Hiển thị trạng thái pin khi bình thường và khi xạc.
void Battery_display(Battery_Management*temp,bool*charge_mode);

//Điều chỉnh các thông số trên xe thông qua yêu cầu từ bàn phím.
void Control_Car(bool*left, bool*right, bool*status_car, bool*charge, int*speed);

//Màn hình hiển thị.
void DISPLAY(Battery_Management*tram, bool*left, bool*right, bool*status_car, bool*charge, int*speed);

/*-------------------------MAIN---------------------------*/
int main(int argc, char const *argv[])
{
    int speed = 40;
    bool Turn_left_signal = false;
    bool Turn_right_signal = false;
    bool Status_car = false;
    bool Charge = false;
    Battery_Management tram(50,(MIN + rand()%(MAX + 1-MIN)));
    
    thread Infor_display(DISPLAY,&tram, &Turn_left_signal, &Turn_right_signal, &Status_car, &Charge, &speed);
    thread Battery(Battery_mode, &tram, &Charge, &Status_car);
    thread Fan(Fan_mode, &tram);
    thread Control(Control_Car, &Turn_left_signal, &Turn_right_signal, &Status_car, &Charge, &speed);

    Infor_display.join();
    Battery.join();
    Fan.join();
    Control.join();

    return 0;
}

//Hiển thị tín hiệu rẽ trái.
void Turn_left_display(bool*turn_left_signal){
    if (*turn_left_signal)
    {
        cout<<"LEFT";
    }else cout<<"----";
}

//Hiển thị tín hiệu rẽ phải.
void Turn_right_display(bool*turn_signal_right){
    if (*turn_signal_right)
    {
        cout<<"RIGHT";
    }else cout<<"-----";
}

//Hiển thị trạng thái quạt.
void Status_Fan_display(bool status_fan){
    if (status_fan)
    {
        cout<<"ON.";
    }else cout<<"OFF.";
}

//Thay đổi tín hiệu báo rẽ trái hoặc phải.
void Changed_turn_signal(bool*status,bool*status_opposite){
    if (*status_opposite)
    {
        *status_opposite = false;
        *status = true;
    }else{
        if (*status)
        {
            *status = false;
        }else *status = true; 
    }
}

//Thay đổi trạng thái hoạt động của xe.
void Changed_status_car(bool*status_car){
    if (*status_car)
    {
        *status_car = false;
    }else *status_car = true;  
}

//Hiển thị thông tin các tín hiệu báo rẽ trên bảng điều khiển.
void Infor_signal_display(bool*left, bool*right, bool*status_car){
    cout<<"TURN SIGNAL: ";
    if (*status_car)
    {
        Turn_left_display(left);
        cout<<"|";
        Turn_right_display(right);
        cout<<endl;
    }else cout<<"----------"<<endl;  
}

//Hiển thị thông tin tốc độ trên bảng điều khiển.
void Infor_speed_display(int*speed, bool*status_car){
    cout<<"SPEED: ";
    if (*status_car)
    {
        cout<<*speed<<" Km/h"<<endl;
    }else cout<<"----------------"<<endl;
}

//Hiển thị thông tin quạt trên bảng điều khiển.
void Infor_fan_display(Battery_Management*tram, bool*status_car){
    cout<<"COOLING FAN: ";
    if (*status_car)
    {
        Status_Fan_display((tram->Get_Status_Fan()));
        cout<<endl;
    }else cout<<"----------"<<endl;
}

//Hiển thị trạng thái xe trên bảng điểu khiển.
void Infor_car_display(bool*status_car){
    cout<<"START: ";
    Status_Fan_display(*status_car);
    cout<<endl;
}

//Ghi nhận nhiệt độ của pin sau mỗi 5s và điều chỉnh trạng thái quạt cho phù hợp.
void Fan_mode(Battery_Management*tram){
    while (1)
    {
        int temp = MIN + rand()%(MAX + 1 - MIN);
        tram->Set_Bat_Temperature(temp);
        this_thread::sleep_for(chrono::seconds(5));
    }
}

//Điều chỉnh trạng thái của pin khi bình thường và khi xạc.
void Battery_mode(Battery_Management*tram, bool*charge, bool*status_car){
    while (1)
    {
        if (tram->Get_Bat_Capacity() == MAX)
        {
            *charge = false;
        }
        if (tram->Get_Bat_Capacity() == 0)
        {
            *status_car = false;
        }
        
        if (*status_car)
        {
            int temp = tram->Get_Bat_Capacity();
            temp--;
            this_thread::sleep_for(chrono::seconds(2));
            tram->Set_Bat_Capacity(temp);
        }else{
            if (*charge)
            {
                int temp = tram->Get_Bat_Capacity();
                temp++;
                this_thread::sleep_for(chrono::seconds(2));
                tram->Set_Bat_Capacity(temp);
            }
        }
    }
    if (tram->Get_Bat_Capacity() == 0)
    {
        *status_car = false;
    }
}

//Hiển thị trạng thái pin khi bình thường và khi xạc.
void Battery_display(Battery_Management*temp,bool*charge_mode){
    if (*charge_mode)
    {
        cout<<"CHARGING:"<<temp->Get_Bat_Capacity()<<" %"<<endl;
    }else cout<<"BAT:"<<temp->Get_Bat_Capacity()<<" %"<<endl;  
}

//Điều chỉnh các thông số trên xe thông qua yêu cầu từ bàn phím.
void Control_Car(bool*left, bool*right, bool*status_car, bool*charge, int*speed){
    while (1)
    {
        int key;
        key = _getch();
        switch (key)
        {
        case 72:
            if (*status_car)
            {
                (*speed)++;
            }
            break;
        case 80:
            if (*status_car)
            {
                if ((*speed) > 0)
                {
                    (*speed)--;
                }
            }
            break;
        case 75:
            Changed_turn_signal(left, right);
            break;
        case 77:
            Changed_turn_signal(right, left);
            break;
        case 13:
            if (*status_car == false)
            {
                *charge = false;
            }
            Changed_status_car(status_car);
            break;
        case 32:
            if (*status_car)
            {
                break;
            }else if (*charge)
            {
                *charge = false;
                break;
            }else *charge = true;
            break;
        case 27:
            exit(0);
        default:
            break;
        }
    }
}

//Màn hình hiển thị.
void DISPLAY(Battery_Management*tram, bool*left, bool*right, bool*status_car, bool*charge, int*speed){
    while (1)
    {
        system("cls");
        Battery_display(tram, charge);
        Infor_signal_display(left, right, status_car);
        Infor_fan_display(tram, status_car);
        Infor_speed_display(speed, status_car);
        cout<<"-----------------------"<<endl;
        Infor_car_display(status_car);
        this_thread::sleep_for(chrono::seconds(1));
    }
}

