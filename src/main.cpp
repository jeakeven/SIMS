#include <iostream>
#include <cstring>
using namespace std;

struct student
{
	long int id;
	char name[20];
	int age;
	char sex[4];
	char addr[30];
	char tel[15];
};

int n = 0;
struct student stu[100];
struct student *p;

void InputStuInfo();
void ChenkStuInfo();
void QueryStuInfo();
void DeleteStuInfo();
void ModifyStuInfo();

int main()
{
	int index;
	cout << endl;
	cout << "+---------------------------------------------+" << endl << endl;;
	cout << "|-- Students' Information Management System --|" << endl << endl;
	cout << "+---------------------------------------------+" << endl;
	cout << endl;
	do {
		cout << endl;
		cout << "   +------------------------------------+" << endl;
		cout << "   +----------------MENU----------------+" << endl;
		cout << "   +------------------------------------+" << endl;
		cout << "   + [1]---Input students' Information  +" << endl;
		cout << "   + [2]---Check students' Information  +" << endl;
		cout << "   + [3]---Query students' Information  +" << endl;
		cout << "   + [4]---Delete students' Information +" << endl;
		cout << "   + [5]---Modify students' Information +" << endl;
		cout << "   + [0]---Exit System                  +" << endl;
		cout << endl << "Please input your choice : ";
		cin >> index;
		switch(index)
		{
		case 0: break;
		case 1: InputStuInfo(); break;
		case 2: ChenkStuInfo(); break;
		case 3: QueryStuInfo(); break;
		case 4: DeleteStuInfo(); break;
		case 5: ModifyStuInfo(); break;
		default: cout << "Invalid Option!!!" << endl << endl << endl << endl << endl;
		}
	}while (index != 0);
	
	return 0;
}

void InputStuInfo()  /*input student information*/
{
	int index;
	if(n == 0)
		p = stu;
	do {
		cout << endl << "+-------------------------+" << endl;
		cout << "Please input ID : "; 
		cin >> p->id;
		cout << "Please input name : ";
		cin >> p->name;
		cout << "Please input age : ";
		cin >> p->age;
		cout << "Please input sex : ";
		cin >> p->sex;
		cout << "Please input addr : ";
		cin >> p->addr;
		cout << "Please input tel : ";
		cin >> p->tel;
		n++; 
		p++;
		cout << "+-------------------------+" << endl;
		cout << "1. Continue input." << endl;
		cout << "2. End input." << endl << endl;
		cout << "Please choice : ";
		cin >> index;
	}while(index == 1);
	
	cout << "Note: Finished input! There is " << n << "students." << endl << endl << endl << endl << endl;
}

void ChenkStuInfo() /*Check student infomation*/
{
	if(n != 0)
	{
		cout << endl;
		cout << "Students Num : " << n << endl;
		cout << "id \t name \t age \t sex \t addr \t \t tel" << endl;
		cout << "------------------------------------------------------" << endl;
		for(int i = 0; i < n ; i++)
		{
			cout << stu[i].id << "\t" << stu[i].name << "\t" << stu[i].age << "\t" <<stu[i].sex 
				<< "\t" <<stu[i].addr << "\t\t" <<stu[i].tel << endl;
		}
	}
	else
	{
		cout << endl <<"Note: No Students information. Please input information!" << endl;
	}
}


void QueryStuInfo() /*Query student infomation*/
{
	int index, nId;
	bool bFlag = false;
	char chName[20];
	if(n != 0)
	{
		do {
			cout << endl;
			cout << "+----------------------------------------+" << endl;
			cout << "| By ID to Query :    input 1 |" << endl;
			cout << "| By name to Query :  input 2 |" << endl;
			cout << "| Cancel :            input 0 |" << endl;
			cout << "+----------------------------------------+" << endl;
			cout << endl <<"Please input your choice : ";
			cin >> index;
			switch(index)
			{
			case 0:
				break;
			case 1:
				cout << "Please input student id : ";
				cin >> nId;
				for(int i = 0; i < n; i++)
				{
					if(stu[i].id == nId)
					{
						cout << endl << "id \t name \t age \t sex \t addr \t \t tel" << endl;
						cout << stu[i].id << "\t" << stu[i].name << "\t" << stu[i].age << "\t" <<stu[i].sex 
							<< "\t" <<stu[i].addr << "\t\t" <<stu[i].tel << endl;
						bFlag = true;
					}
				}
				if(bFlag == false)
				{
					cout << endl << "Note: No Students information. Please Check!!!" << endl;
				}
				break;
			case 2:
				cout << "Please input student name : ";
				cin >> chName;
				for(int i = 0; i < n; i++)
				{
					if(strcmp(stu[i].name, chName) == 0)
					{
						cout << "id \t name \t age \t sex \t addr \t \t tel" << endl;
						cout << stu[i].id << "\t" << stu[i].name << "\t" << stu[i].age << "\t" <<stu[i].sex 
							<< "\t" <<stu[i].addr << "\t\t" <<stu[i].tel << endl;
						bFlag = true;
					}
				}
				if(bFlag == false)
				{
					cout << endl <<"Note: No Students information. Please Check!!!" << endl;
				}
				break;
			default : cout << endl << "Note: Invalid option!!!" << endl;
				break;
			}
		}while(index != 0);
	}
	else
	{
		cout << endl << "Note: No Students information. Please input information!" << endl;
	}
}

void ModifyStuInfo() /*Modify student information*/
{
	int j, index;
	long int nId;
	if(n != 0)
	{
		cout << "Please input id: ";
		cin >> nId;
		cout << endl;
		for(int i = 0; i < n; i++)
		{
			if(stu[i].id == nId)
				j = i;
		}
		do {
			cout << "Please choice the option need to modify:" << endl;
			cout << "+-------------------------------------+" << endl;
			cout << "|    name               input 1 |" << endl;
			cout << "|    age                input 2 |" << endl;
			cout << "|    sex                input 3 |" << endl;
			cout << "|    id                 input 4 |" << endl;
			cout << "|    addr               input 5 |" << endl;
			cout << "|    tel                input 6 |" << endl;
			cout << "|    cancel             input 0 |" << endl;
			cout << "+-------------------------------------+" << endl;
			cout << "Input your choice : ";
			cin >> index;
			switch(index)
			{
			case 0 : break;
			case 1 : 
				cout << "Input new name :";
				cin >> stu[j].name;
				break;
			case 2 : 
				cout << "Input new age :";
				cin >> stu[j].age;
				break;
			case 3 : 
				cout << "Input new sex :";
				cin >> stu[j].sex;
				break;
			case 4 : 
				cout << "Input new id :";
				cin >> stu[j].id;
				break;
			case 5 : 
				cout << "Input new addr :";
				cin >> stu[j].addr;
				break;
			case 6 : 
				cout << "Input new tel :";
				cin >> stu[j].tel;
				break;
			default : 
				cout << endl << "Invalid option!!!" << endl;
				break;
			}
		}while(index != 0);
	}
	else
	{
		cout << endl << "Note: No Students information. Please input information!" << endl;
	}
}

void DeleteStuInfo() /*Delete student information*/
{
	int i, j;
	long int nId;
	if(n != 0)
	{
		cout << "id \t name \t age \t sex \t addr \t \t tel" << endl;
		cout << "+----------------------------------------------+" << endl;
		for(int i = 0; i < n; i++)
		{
			cout << stu[i].id << "\t" << stu[i].name << "\t" << stu[i].age << "\t" <<stu[i].sex 
				<< "\t" <<stu[i].addr << "\t\t" <<stu[i].tel << endl;		
		}
		cout << "Input delete id : ";
		cin >> nId;
		cout << endl << endl;
		for(i = 0; i < n; i++)
		{
			if(stu[i].id == nId)
				j = i;
		}
		if(j != n - 1)
		{
			for(int k = i - 1; k < n; k++, j++)
			{
				stu[j].id = stu[j + 1].id;
				stu[j].age = stu[j + 1].age;
				strcpy(stu[j].name, stu[j + 1].name);
				strcpy(stu[j].sex, stu[j + 1].sex);
				strcpy(stu[j].addr, stu[j + 1].addr);
				strcpy(stu[j].tel, stu[j + 1].tel);
				n--; p--;
			}
		}
		else
		{
			n--; p--;
		}
		cout << endl << "Node: Finished Delete." << endl;
	}
	else
	{
		cout << endl << "Note: No Students information. Please input information!" << endl;
	}
}
