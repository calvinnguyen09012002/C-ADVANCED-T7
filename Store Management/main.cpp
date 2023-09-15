/*
 * File Name: main.cpp
 * Author: Nguyen Gia Phuc
 * Date: 11/09/2023
 * Description: Manage a restaurant's system
 */

#include <iostream>
#include <string>
#include <vector>


using namespace std;

typedef enum{
	EXIT = 0,
	MANAGER = 1,
	STAFF = 2
}Types_of_choices_for_Restaurant;

typedef enum{
	MANAGER_COME_BACK = 0,
	MANAGER_SET_NUMBER_TABLE = 1,
	MANAGER_ADD = 2,
	MANAGER_EDIT = 3,
	MANAGER_REMOVE = 4,
	MANAGER_DISPLAY = 5
}Types_of_choices_for_Manager;

typedef enum{
	TABLE_COME_BACK = 0,
	TABLE_ADD = 1,
	TABLE_EDIT = 2,
	TABLE_REMOVE = 3,
	TABLE_DISPLAY = 4
}Types_of_choices_for_Table;

void Display_Main_Menu(){
	cout << "-----------RESTAURANT----------" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Manager" << endl;
	cout << "2. Staff" << endl;
	cout << "-------------------------" << endl;
	cout << "Enter your choice: ";
}

class Dish{
private:
	static int Counter_for_ID;
	int ID_Dish;
	string Name_Dish;
	int Price_Dish;
	int Number_Of_Dish;

public:
	Dish() : Number_Of_Dish(0){};
	void Set_ID_Dish();
	void Set_Name_Dish();
	void Set_Price_Dish();
	void Set_Number_Of_Dish(int num);

	int Get_ID_Dish();
	string Get_Name_Dish();
	int Get_Price_Dish();
	int Get_Number_Of_Dish();
};

int Dish::Counter_for_ID = 0;

void Dish::Set_ID_Dish(){
	this->ID_Dish = ++Counter_for_ID;
}

void Dish::Set_Name_Dish(){
	cin.ignore();string name_dish;
	cout << "Enter name of dish: ";
	getline(cin, name_dish);
	this->Name_Dish = name_dish;
}

void Dish::Set_Price_Dish(){
	int price_dish;
	cout << "Enter price of dish: ";
	cin >> price_dish;
	this->Price_Dish = price_dish;
}

void Dish::Set_Number_Of_Dish(int num){
	this->Number_Of_Dish = num;
}

int Dish::Get_ID_Dish(){
	return ID_Dish;
}

string Dish::Get_Name_Dish(){
	return Name_Dish;
}

int Dish::Get_Price_Dish(){
	return Price_Dish;
}

int Dish::Get_Number_Of_Dish(){
	return Number_Of_Dish;
}

class Manager{
private:
	vector<Dish> List_for_dish;
	int Table;

public:
	void Display_List_for_Dish();
	void Set_Table();
	int Get_Table();
	void Set_List_for_dish(Dish dish);
	vector<Dish> Get_Dish_List();

	void Display_Menu_for_Manager();
	void Menu_Manager();

	void Menu_Number_of_Table();
	void Number_Of_Table();

	void Menu_Add_Dish();
	void Add_Dish();

	void Menu_Edit_Dish();
	void Edit_Dish_Fist(int id);
	void Edit_Dish_Second();

	void Menu_Remove_Dish();
	void Remove_Dish_First(int id);
	void Remove_Dish_Second();
};

void Dish_Title(){
	cout << "-------FOOD INFORMATION-------" << endl;
	cout << " ID  |   Name   |   Price   " << endl;
	cout << "------------------------------" << endl;
}

void Dish_Information(Dish dish){
	printf(" %-4d| %-9s| %-10d\n", dish.Get_ID_Dish(), dish.Get_Name_Dish().c_str(), dish.Get_Price_Dish());
}

void Manager::Display_List_for_Dish(){
	cout << "----------MENU-----------" << endl;
	if (!List_for_dish.empty()){
		cout << "------------Menu------------" << endl;
		cout << " NO | ID  |   Name   |   Price   " << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < List_for_dish.size(); i++){
			printf(" %-3d| %-4d| %-9s| %-10d\n", i + 1,
				   List_for_dish[i].Get_ID_Dish(), List_for_dish[i].Get_Name_Dish().c_str(), List_for_dish[i].Get_Price_Dish());
		}
	}
	else{
		cout << "List for dishes is emty!!" << endl;
		cout << endl;
	}
}

void Manager::Set_Table(){
	cout << "Enter number of table: ";
	cin >> this->Table;
}

int Manager::Get_Table(){
	return Table;
}

void Manager::Set_List_for_dish(Dish dish){
	this->List_for_dish.push_back(dish);
}

vector<Dish> Manager::Get_Dish_List(){
	return List_for_dish;
}

void Manager::Display_Menu_for_Manager(){
	cout << "-----------MANAGER-----------" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Set number of table" << endl;
	cout << "2. Add dish" << endl;
	cout << "3. Edit dish" << endl;
	cout << "4. Remove dish" << endl;
	cout << "5. Display dish" << endl;
	cout << "-----------------------------" << endl;
	Menu_Manager();
}

void Manager::Menu_Manager(){
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;
	switch (choice){
	case MANAGER_COME_BACK:
		break;
	case MANAGER_SET_NUMBER_TABLE:
		Menu_Number_of_Table();
		break;
	case MANAGER_ADD:
		Menu_Add_Dish();
		break;
	case MANAGER_EDIT:
		Menu_Edit_Dish();
		break;
	case MANAGER_REMOVE:
		Menu_Remove_Dish();
		break;
	case MANAGER_DISPLAY:
		Display_List_for_Dish();
		break;
	default:
		cout << "Please try again!!!" << endl;
		Menu_Manager();
		break;
	}
}

void Manager::Menu_Number_of_Table(){
	cout << "-----------Manager-----------" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Set number of table" << endl;
	cout << "-----------------------------" << endl;
	Number_Of_Table();
}

void Manager::Number_Of_Table(){
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1){
		Set_Table();
		cout << "Set number of table successfully ." << endl;
		cout << endl;
		Display_Menu_for_Manager();
	}
	else if (choice == 0){
		return;
	}
	else{
		cout << "Please try again!!" << endl;
		Number_Of_Table();
	}
}

void Manager::Menu_Add_Dish(){
	Dish dish;
	cout << "-----------Manager-----------" << endl;
	dish.Set_ID_Dish();
	dish.Set_Name_Dish();
	dish.Set_Price_Dish();
	Set_List_for_dish(dish);
	cout << "-----------------------------" << endl;
	cout << "Added dish successfully." << endl;
	cout << endl;
	cout << "-----------Manager-----------" << endl;
	Dish_Title();
	Dish_Information(dish);
	cout << endl;
	cout << "-----------------------------" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Countinue" << endl;
	cout << "-----------------------------" << endl;
	Add_Dish();
}

void Manager::Add_Dish(){
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	if (choice == 1)
	{
		Menu_Add_Dish();
		cout << endl;
	}
	else if (choice == 0){
		Display_Menu_for_Manager();
		return;
	}
	else{
		cout << "Please try again!!" << endl;
		Add_Dish();
	}
}

void Manager::Menu_Edit_Dish(){
	Display_List_for_Dish();
	if (List_for_dish.empty()){
		Display_Menu_for_Manager();
	}
	else{
		cout << "Enter ID of dish to edit: ";
		int id;
		cin >> id;
		if (id < List_for_dish.front().Get_ID_Dish() || id > List_for_dish.back().Get_ID_Dish()){
			cout << "ID does not exist." << endl;
			Display_Menu_for_Manager();
		}
		else{
			bool found = false;
			int i = -1;
			for (auto &d : List_for_dish){
				i++;
				if (d.Get_ID_Dish() == id){
					found = true;
					break;
				}
			}
			if (found){
				cout << "0. Come back" << endl;
				cout << "1. Edit name" << endl;
				cout << "2. Edit price" << endl;
				cout << "------------------------------" << endl;
				Edit_Dish_Fist(i);
			}
			else{
				cout << "ID does not exist." << endl;
				Display_Menu_for_Manager();
			}
		}
	}
}

void Manager::Edit_Dish_Fist(int i){
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	if (choice == 0){
		Display_Menu_for_Manager();
		return;
	}
	else if (choice == 1){
		List_for_dish[i].Set_Name_Dish();
		cout << "Edited name successfully." << endl;
		cout << endl;
	}
	else if (choice == 2){
		List_for_dish[i].Set_Price_Dish();
		cout << "Edited price successfully." << endl;
		cout << endl;
	}
	else{
		cout << "Please try again!!" << endl;
		Edit_Dish_Fist(i);
		return;
	}
	Dish_Title();
	Dish_Information(List_for_dish[i]);
	cout << "-----------------------------" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Countinue to edit" << endl;
	cout << "-----------------------------" << endl;
	Edit_Dish_Second();
}

void Manager::Edit_Dish_Second(){
	int key;
	cout << "Enter your choice: ";
	cin >> key;
	switch (key){
	case 0:
		Display_Menu_for_Manager();
		break;
	case 1:
		Menu_Edit_Dish();
		break;
	default:
		cout << "Please try again!!" << endl;
		Edit_Dish_Second();
		break;
	}
}
void Manager::Menu_Remove_Dish(){
	Display_List_for_Dish();
	if (List_for_dish.empty()){
		Display_Menu_for_Manager();
	}
	else{
		cout << "Enter ID of dish to delete: ";
		int id;
		cin >> id;
		if (id < List_for_dish.front().Get_ID_Dish() || id > List_for_dish.back().Get_ID_Dish()){
			cout << "ID does not exist." << endl;
			Display_Menu_for_Manager();
			return;
		}
		else{
			bool found = false;
			int i = -1;
			for (auto &d : List_for_dish){
				i++;
				if (d.Get_ID_Dish() == id)
				{
					found = true;
					break;
				}
			}
			if (found){
				cout << "-------------Manager------------" << endl;
				cout << "Are you sure that you want to delete ?" << endl;
				cout << "0. Come back" << endl;
				cout << "1. Delete" << endl;
				cout << "--------------------------------" << endl;
				Remove_Dish_First(i);
				return;
			}
			else{
				cout << "ID does not exist." << endl;
				Display_Menu_for_Manager();
				return;
			}
		}
	}
}

void Manager::Remove_Dish_First(int i){
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	if (choice == 0){
		Display_Menu_for_Manager();
	}
	else if (choice == 1){
		Dish dish;
		dish = List_for_dish[i];
		List_for_dish.erase(List_for_dish.begin() + i);
		cout << "Successfully deleted." << endl;
		cout << endl;
		Dish_Title();
		Dish_Information(dish);
	}
	else{
		cout << "Please try again!!" << endl;
		Remove_Dish_First(i);
	}
	cout << "-----------------------------" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Countinue to remove" << endl;
	cout << "-----------------------------" << endl;
	Remove_Dish_Second();
}

void Manager::Remove_Dish_Second(){
	int key;
	cout << "Enter your choice: ";
	cin >> key;
	switch (key){
	case 0:
		Display_Menu_for_Manager();
		break;
	case 1:
		Menu_Remove_Dish();
		break;
	default:
		cout << "Please try again!!" << endl;
		Remove_Dish_Second();
		break;
	}
}

class Table{
private:
	bool Status;
	int Total_Amount;
public:
	vector<Dish> List_for_dishes_on_the_Table;
	Table() : Status(false), Total_Amount(0) {}

	void Set_Status(bool status);
	bool Get_Status();

	void Set_Total_Amount(int total_amount);
	int Get_Total_Amount();
};

void Table::Set_Status(bool status){
	this->Status = status;
}

bool Table::Get_Status(){
	return Status;
}

void Table::Set_Total_Amount(int total_amount){
	this->Total_Amount = total_amount;
}

int Table::Get_Total_Amount(){
	return Total_Amount;
}

class Staff{
private:
	vector<Dish> List_for_dishes;
	int Number_of_Table;
	vector<Table> Table_List;

public:
	void Set_List_for_dishes_on_the_Table(Dish dish, int table);
	void Set_List_for_dishes(vector<Dish> list_for_dishes);

	void Set_Number_of_Table(int number_of_table);
	int Get_Number_of_Table();

	void Set_Size_of_Table_List(int number_of_table);
	void Select_Table();

	void Display_Menu_Staff();
	void Menu_Staff();

	void Display_Menu_Table(int table);
	void Menu_Table(int table);

	void Menu_Add_Dish(int table);
	void Add_Dish(int table);

	void Menu_Edit_Dish(int table);
	void Edit_Dish(int table);

	void Menu_Remove_Dish(int table);
	void Remove_Dish_first(int table, int id);
	void Remove_Dish_second(int table);

	void Menu_Pay_Bill(int table);
	void Pay_Bill(int table);

	void Display_List_for_Dishes(int table);
	void Display_One_Dish(int table, int i);
	void Display_List_of_Dishes_on_the_Table(int table);
};

void Staff::Set_List_for_dishes_on_the_Table(Dish dish, int table){
	Table_List[table - 1].List_for_dishes_on_the_Table.push_back(dish);
}

void Staff::Set_List_for_dishes(vector<Dish> list_for_dishes){
	this->List_for_dishes = list_for_dishes;
}

void Staff::Set_Number_of_Table(int number_of_table){
	this->Number_of_Table = number_of_table;
}

int Staff::Get_Number_of_Table(){
	return this->Number_of_Table;
}

void Staff::Set_Size_of_Table_List(int number_of_table){
	this->Table_List.resize(number_of_table);
}

void Staff::Display_List_for_Dishes(int table){
	cout << "-----------Table " << table << " ------------" << endl;
	if (!List_for_dishes.empty()){
		cout << "------------Menu------------" << endl;
		cout << " NO | ID  |   Name   |   Price   " << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < List_for_dishes.size(); i++){
			printf(" %-3d| %-4d| %-9s| %-10d\n", i + 1,
				   List_for_dishes[i].Get_ID_Dish(), List_for_dishes[i].Get_Name_Dish().c_str(), List_for_dishes[i].Get_Price_Dish());
		}
		cout << endl;
	}
	else{
		cout << "There are not any dish on the menu!!" << endl;
		cout << endl;
	}
}

void Staff::Display_One_Dish(int table, int i){
	cout << "-----------Table " << table << " -------------" << endl;
	cout << " ID  |   Name   |   Price   | Amount " << endl;
	cout << "------------------------------" << endl;

	printf(" %-4d| %-9s| %-10d | %-7d\n",
		   Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_ID_Dish(), Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_Name_Dish().c_str(),
		   Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_Price_Dish(), Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_Number_Of_Dish());
	cout << "------------------------------" << endl;
}

void Staff::Display_List_of_Dishes_on_the_Table(int table)
{
	cout << "-------------Staff------------" << endl;
	cout << "----------List of dishes at table " << table << " ---------" << endl;
	if (!Table_List[table - 1].List_for_dishes_on_the_Table.empty())
	{
		cout << " NO | ID  |   Name   |   Price   | Amount" << endl;
		cout << "------------------------------------------" << endl;
		for (int i = 0; i < Table_List[table - 1].List_for_dishes_on_the_Table.size(); i++)
		{
			printf(" %-3d| %-4d| %-9s| %-10d| %-7d\n", i + 1,
				   Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_ID_Dish(),
				   Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_Name_Dish().c_str(),
				   Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_Price_Dish(),
				   Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_Number_Of_Dish());
		}
		cout << endl;
	}
	else
	{
		cout << "There are not any dish on this table!!" << endl;
		cout << endl;
		Display_Menu_Table(table);
	}
}

void Staff::Display_Menu_Staff()
{
	cout << "-------------Staff-------------" << endl;
	cout << "-----------Table list----------" << endl;
	cout << "Table No ";
	for (int i = 0; i < Number_of_Table; i++){
		cout << "| " << i + 1 << " ";
	}
	cout << endl;
	cout << "---------";
	for (int i = 0; i < Number_of_Table; i++){
		if (i < 10)
			cout << "----";
		else
			cout << "-----";
	}
	cout << endl;
	cout << "Status   ";
	for (int i = 0; i < Number_of_Table; i++){
		string sign;
		if (Table_List[i].Get_Status() == 1)
			sign = "X";
		else
			sign = "0";
		cout << "| " << sign << " ";
		if (i > 9)
			cout << " ";
	}
	cout << endl;
	cout << "---------";
	for (int i = 0; i < Number_of_Table; i++){
		if (i < 10)
			cout << "-----";
		else
			cout << "-----";
	}
	cout << endl;
	cout << "0. Come back" << endl;
	cout << "1. Select table" << endl;
	cout << "-------------------------------" << endl;
	Menu_Staff();
}

void Staff::Menu_Staff(){
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;
	switch (choice){
	case 0:
		break;
	case 1:
		Select_Table();
		break;
	default:
		cout << "Please try again!!" << endl;
		Menu_Staff();
		break;
	}
}

void Staff::Select_Table(){
	cout << "Enter table number: ";
	int table;
	cin >> table;
	if (table < 1 || table > Number_of_Table){
		cout << "The selected table is invalid." << endl;
		return;
	}
	else{
		Table_List[table - 1].Set_Status(true);
		Display_Menu_Table(table);
	}
}

void Staff::Display_Menu_Table(int table){
	cout << "-------------Staff---------------" << endl;
	cout << "-------------Table " << table << " --------------" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Add dish" << endl;
	cout << "2. Edit dish" << endl;
	cout << "3. Remove dish" << endl;
	cout << "4. Display dish" << endl;
	cout << "-------------------------------" << endl;
	Menu_Table(table);
}

void Staff::Menu_Table(int table){
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;
	switch (choice){
	case TABLE_COME_BACK:
		break;
	case TABLE_ADD:
		Menu_Add_Dish(table);
		break;
	case TABLE_EDIT:
		Menu_Edit_Dish(table);
		break;
	case TABLE_REMOVE:
		Menu_Remove_Dish(table);
		break;
	case TABLE_DISPLAY:
		Display_List_of_Dishes_on_the_Table(table);
		break;
	default:
		cout << "Please try again!!" << endl;
		Menu_Table(table);
		break;
	}
}

void Staff::Menu_Add_Dish(int table){
	Display_List_for_Dishes(table);
	if (List_for_dishes.empty()){
		Display_Menu_Table(table);
		return;
	}
	else{
		cout << "Enter ID of dish to add: ";
		int id;
		cin >> id;
		if (id < List_for_dishes.front().Get_ID_Dish() || id > List_for_dishes.back().Get_ID_Dish()){
			cout << "ID does not exist." << endl;
			cout << endl;
			Display_Menu_Table(table);
			return;
		}
		else{
			bool found = false;
			int i = -1;
			for (auto &d : List_for_dishes){
				i++;
				if (d.Get_ID_Dish() == id){
					cout << "Enter number of dish: ";
					int number;
					cin >> number;
					cout << endl;
					d.Set_Number_Of_Dish(number);
					Set_List_for_dishes_on_the_Table(d, table);
					Table_List[table - 1].Set_Status(true);
					cout << "Added successfully." << endl;
					found = true;
					break;
				}
			}
			if (found){
				Display_One_Dish(table, i);
				cout << "0. Come back" << endl;
				cout << "1. Countinue to add" << endl;
				cout << "---------------------------" << endl;
				Add_Dish(table);
				return;
			}
			else{
				cout << "ID does not exist!!" << endl;
				cout << endl;
				Display_Menu_Table(table);
				return;
			}
		}
	}
}

void Staff::Add_Dish(int table){
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 0:
		Display_Menu_Table(table);
		break;
	case 1:
		Menu_Add_Dish(table);
		break;
	default:
		cout << "Please try again!!" << endl;
		Add_Dish(table);
		break;
	}
}

void Staff::Menu_Edit_Dish(int table){
	Display_List_of_Dishes_on_the_Table(table);
	if (Table_List[table - 1].List_for_dishes_on_the_Table.empty()){
		Display_Menu_Table(table);
		return;
	}
	else{
		cout << "Enter ID of dish to edit: ";
		int id;
		cin >> id;
		if (id < Table_List[table - 1].List_for_dishes_on_the_Table.front().Get_ID_Dish() || id > Table_List[table - 1].List_for_dishes_on_the_Table.back().Get_ID_Dish()){
			cout << "ID does not exist." << endl;
			cout << endl;
			Display_Menu_Table(table);
			return;
		}
		else{
			bool found = false;
			int i = -1;
			for (auto &d : Table_List[table - 1].List_for_dishes_on_the_Table){
				i++;
				if (d.Get_ID_Dish() == id){
					cout << "Enter number of dish: ";
					int number;
					cin >> number;
					d.Set_Number_Of_Dish(number);
					Set_List_for_dishes_on_the_Table(d, table);
					cout << "Edited successfully ." << endl;
					found = true;
					break;
				}
			}
			if (found){
				Display_One_Dish(table, i);
				cout << "0. Come back" << endl;
				cout << "1. Countinue edit" << endl;
				cout << "------------------------------" << endl;
				Edit_Dish(table);
				return;
			}
			else{
				cout << "ID does not exist." << endl;
				cout << endl;
				Display_Menu_Table(table);
				return;
			}
		}
	}
}

void Staff::Edit_Dish(int table){
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;
	switch (choice){
	case 0:
		Display_Menu_Table(table);
		break;
	case 1:
		Menu_Edit_Dish(table);
		break;
	default:
		cout << "Please try again!!" << endl;
		Edit_Dish(table);
		break;
	}
}

void Staff::Menu_Remove_Dish(int table){
	Display_List_of_Dishes_on_the_Table(table);
	if (Table_List[table - 1].List_for_dishes_on_the_Table.empty()){
		Display_Menu_Table(table);
		return;
	}
	else{
		cout << "Enter ID of dish to remove: ";
		int id;
		cin >> id;
		if (id < Table_List[table - 1].List_for_dishes_on_the_Table.front().Get_ID_Dish() || id > Table_List[table - 1].List_for_dishes_on_the_Table.back().Get_ID_Dish()){
			cout << "ID does not exist!!" << endl;
			cout << endl;
			Display_Menu_Table(table);
			return;
		}
		else{
			bool found = false;
			int i = -1;
			for (auto &d : Table_List[table - 1].List_for_dishes_on_the_Table){
				i++;
				if (d.Get_ID_Dish() == id){
					Table_List[table - 1].List_for_dishes_on_the_Table.erase(Table_List[table - 1].List_for_dishes_on_the_Table.begin() + i);
					cout << "Successfully removed." << endl;
					found = true;
					break;
				}
			}
			if (found){
				cout << "--------------Manager--------------" << endl;
				cout << "Are you sure that you want to delete?" << endl;
				cout << "0. Come back" << endl;
				cout << "1. Delete" << endl;
				cout << "-----------------------------------" << endl;
				Remove_Dish_first(table, i);
				return;
			}
			else{
				cout << "ID does not exist!!" << endl;
				cout << endl;
				Display_Menu_Table(table);
				return;
			}
		}
	}
}

void Staff::Remove_Dish_first(int table, int i){
	while (true){
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
		cout << endl;
		if (choice == 0){
			Display_Menu_Table(table);
			break;
		}
		else if (choice == 1){
			Table_List[table - 1].List_for_dishes_on_the_Table.erase(Table_List[table - 1].List_for_dishes_on_the_Table.begin() + i);
			cout << "Removed successfully ." << endl;
			cout << endl;
			Display_One_Dish(table, i);
			cout << "-----------------------------" << endl;
			cout << "0. Come back" << endl;
			cout << "1. Countinue to edit" << endl;
			cout << "-----------------------------" << endl;
			Remove_Dish_second(table);
			break;
		}
		else{
			cout << "Please try again!!" << endl;
			break;
		}
	}
}

void Staff::Remove_Dish_second(int table){
	int key;
	cout << "Enter your choice: ";
	cin >> key;
	cout << endl;
	switch (key){
	case 0:
		Display_Menu_Table(table);
		break;
	case 1:
		Menu_Remove_Dish(table);
		break;
	default:
		cout << "Please try again!!" << endl;
		Remove_Dish_second(table);
		break;
	}
}

void Staff::Menu_Pay_Bill(int table){
	cout << "-------------Staff--------------" << endl;
	cout << "------Receipt for this table " << table << " ------" << endl;
	if (!Table_List[table - 1].List_for_dishes_on_the_Table.empty()){
		cout << " NO | ID  |   Name   |   Price   | Amount" << endl;
		cout << "------------------------------" << endl;
		int total = 0;
		for (int i = 0; i < Table_List[table - 1].List_for_dishes_on_the_Table.size(); i++){
			printf(" %-3d| %-4d| %-9s| %-10d| %-7d\n", i + 1,
				   Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_ID_Dish(),
				   Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_Name_Dish().c_str(),
				   Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_Price_Dish(),
				   Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_Number_Of_Dish());
			total += Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_Price_Dish() * Table_List[table - 1].List_for_dishes_on_the_Table[i].Get_Number_Of_Dish();
		}
		Table_List[table - 1].Set_Total_Amount(total);
		cout << "Total: " << Table_List[table - 1].Get_Total_Amount() << "VND" << endl;
		cout << "-----------------------------" << endl;
		cout << "0. Come back" << endl;
		cout << "1. Pay" << endl;
		cout << "-----------------------------" << endl;
		Pay_Bill(table);
	}
	else
	{
		cout << "There are not any dish on this table." << endl;
		cout << endl;
		Display_Menu_Table(table);
	}
}

void Staff::Pay_Bill(int table){
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;
	switch (choice){
	case 0:
		Display_Menu_Table(table);
		break;
	case 1:
		cout << "Paid successfully." << endl;
		Table_List[table - 1].Set_Status(false);
		Display_Menu_Staff();
		break;
	default:
		cout << "Please try again!!" << endl;
		Pay_Bill(table);
		break;
	}
}

int main(int argc, char const *argv[])
{
	Manager manager;
	Staff staff;
	while (1){
		Display_Main_Menu();
		int key;
		cin >> key;
		cout << endl;
		switch (key){
		case EXIT:
			return 0;
		case MANAGER:
			manager.Display_Menu_for_Manager();
			break;
		case STAFF:
			staff.Set_List_for_dishes(manager.Get_Dish_List());
			staff.Set_Number_of_Table(manager.Get_Table());
			staff.Set_Size_of_Table_List(manager.Get_Table());
			staff.Display_Menu_Staff();
			break;
		default:
			break;
		}
	}
}
