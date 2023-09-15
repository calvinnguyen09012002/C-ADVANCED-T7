/*
 * File Name: main.cpp
 * Author: Nguyen Gia Phuc
 * Date: 12/09/2023
 * Description: Manage a hotel's system
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Display_Main_Menu(){
	cout << "-----------HOTEL----------" << endl;
	cout << "0. Thoát" << endl;
	cout << "1. Dat phong" << endl;
	cout << "2. Quan li khach hang" << endl;
    cout << "3. Quan li nhan vien" << endl;
    cout << "4. Thanh toan" << endl;
    cout << "5. Bao mat va quyen truy cap" << endl;
    cout << "6. Bao cao va thong ke" << endl;
    cout << "7. Quan li phan hoi va danh gia" << endl;
	cout << "---------------------------" << endl;
	cout << "Nhap lua chon: ";
}

int main(int argc, char const *argv[])
{
    while (1){
        TURN:
		Display_Main_Menu();
		int key;
		cin >> key;
		cout << endl;
		switch (key){
		case 0:
			return 0;
		case 1:
			
			break;
		case 2:
			
			break;
        case 3:
			
			break;
		case 4:
			
			break;
        case 5:
			
			break;
		case 6:
			
			break;
        case 7:
			
			break;
		default:
            cout << "Vui long nhap lai!!" << endl;
            goto TURN;
			break;
		}
	}
    return 0;
}

