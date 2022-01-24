//   HOSPITAL MANAGEMENT
//   Made by M. AHSAN RAZA
#include<iostream>
#include<fstream>
using namespace std;

struct patient
{
	int P_ID;
	char P_Name[20];
	int P_Age;
	char P_Gender;
	char P_Department[20];
};

void writeRecord()
{
	patient p1;
	ofstream f1;
	f1.open("Record.dat", ios::out | ios::app); 
	
	cout<<"\nEnter Patient ID: ";
	cin>>p1.P_ID;
	cout<<"\nEnter Patient Name: ";
	cin>>p1.P_Name;
	cout<<"\nEnter Patient Age: ";
	cin>>p1.P_Age;
	cout<<"\nEnter Patient Gender: ";
	cin>>p1.P_Gender;
	cout<<"\nEnter Patient Department: ";
	cin>>p1.P_Department;
	
	f1<<p1.P_ID<<"\t"<<p1.P_Name<<"\t"<<p1.P_Age<<"\t"<<p1.P_Gender<<"\t"<<p1.P_Department<<endl;
	f1.close();
}
void readAllRecord()
{
	patient p2;
	ifstream f2;
	f2.open("Record.dat", ios::in);
	f2>>p2.P_ID>>p2.P_Name>>p2.P_Age>>p2.P_Gender>>p2.P_Department;
	
	while(!f2.eof())
	{
    	{
	       cout<<p2.P_ID<<"\t"<<p2.P_Name<<"\t"<<p2.P_Age<<"\t"<<p2.P_Gender<<"\t"<<p2.P_Department<<endl;
    	}
    		f2>>p2.P_ID>>p2.P_Name>>p2.P_Age>>p2.P_Gender>>p2.P_Department;
	}
    f2.close();
}
void searchRecord()
{
	patient p3;
	ifstream f3;
	f3.open("Record.dat", ios::in);
	f3>>p3.P_ID>>p3.P_Name>>p3.P_Age>>p3.P_Gender>>p3.P_Department;
	
	int MinAge;
	int MaxAge;
	cout<<"\nEnter Minnimum Age: "<<endl;
	cin>>MinAge;
	cout<<"\nEnter Maximum Age: "<<endl;
	cin>>MaxAge;
	
	while(!f3.eof())
	{
		if(p3.P_Age>MinAge&&p3.P_Age<MaxAge)
		{
			cout<<p3.P_ID<<"\t"<<p3.P_Name<<"\t"<<p3.P_Age<<"\t"<<p3.P_Gender<<"\t"<<p3.P_Department<<endl;
		}
		f3>>p3.P_ID>>p3.P_Name>>p3.P_Age>>p3.P_Gender>>p3.P_Department;
	}
	f3.close();
}
/*
void separateRecord()
{
	patient p4;
	ifstream f4;
	f4.open("Record.dat", ios::in);
	f4>>p4.P_ID>>p4.P_Name>>p4.P_Age>>p4.P_Gender>>p4.P_Department;
	
}*/

int main()
{
	int choice;
	cout<<"\n1)WRITE RECORD:"<<endl;
	cout<<"\n2)READ RECORD: "<<endl;
	cout<<"\n3)SEARCH RECORD: "<<endl;
	cout<<"\nEnter Your Choice: "<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			writeRecord();
			break;
		case 2:
			readAllRecord();
			break;
		case 3:
			searchRecord();
			break;
		default:
		    cout<<"\nInvalid Choice"<<endl;	
	}
	cout<<endl;
}

