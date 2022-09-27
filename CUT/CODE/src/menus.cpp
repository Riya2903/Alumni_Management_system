/********************************************************************************************************
*
******* FILENAME  : menus.cpp
*
*** DESCRIPTION   : This file defines the function that consists of various subfunctions 
*		    to perform certain operations.
*
* Revision History:
*
*
* 	Date				Name 				Reason
*
* 	27th Sep 2022		     Riya Malik			      -----------
*
*
*********************************************************************************************************/



#include <iostream>
#include <iomanip>
#include "alumni_class.cpp"
#include "student_class.cpp"
#include "admin_class.cpp"
#include <thread>
#include <limits>
#include <mutex>
using namespace std;
mutex mylock;


/******************************************************************************************
 *
 * FUNCTION NAME  : alumni_menu
 *
 * DESCRIPTION    : An Alumni can register and after successful registration, alumni can 
 * 		    login and access the functions in alumni menu.
 *
 *
 *
 * RETURNS        : Alumni_Register function
 *		    a.Alumni_Login function
 *		    Exit - Back to main menu
 *
 *
 *
 * ***************************************************************************************/


int alumni_menu(void)
{
	Alumni a;
	fstream fl;

	fl.open("Alumni_database",ios::in | ios::binary);
	if(fl)
	{
		fl.close();
		cout<<"Fetching data..."<<endl;
		a.fetch_data();
	}
	int choice1 = 0;
	while(choice1!=3)
	{
		cout<<endl<<"---------Alumini Menu----------"<<endl;
		cout<<"1. Register"<<endl<<"2. Login"<<endl<<"3. Back to Main Menu"<<endl;
		cin>>choice1;
		while(1)
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<endl<<"You have entered the wrong input type"<<endl;
				cout<<"Enter your choice"<<endl;
				cin>>choice1;
			}
			if(!cin.fail())
			{
				break;
			}
		}

		switch(choice1)
		{

			case 1 :
				{	thread t3(Alumni_Register);
					t3.join();
				}
				break;
			case 2 : a.Alumni_Login();
				 break;
			case 3 : break;
			default: cout<<"Invalid Choice"<<endl;
		}
		system("read");
		system("clear");

	}
	a.store_data();
	return (0);
}


/**********************************************************************************
 *
 * FUNCTION NAME : student_menu
 *
 * DESCRIPTION   : A student can register and after successful registration, student 
 * 		   can login and access the functions in login menu.
 *
 * RETURNS       : Student_Register function
 *		   s.Student_Login function
 *		   Exit - Back to main menu
 *
 *
 *
 * ******************************************************************************/



int student_menu()
{
	student s;
	fstream fl;
	fl.open("student_database",ios::in | ios::binary);
	if(fl)
	{
		fl.close();
		cout<<endl<<"Fetching data..."<<endl;
		s.student_fetch_data();
	
	}

	int choice3=0;
	while(choice3!=3){
		cout<<endl<<"---------Student Menu----------"<<endl;
		cout<<"1. Register"<<endl<<"2. Login"<<endl<<"3. Back to Main Menu"<<endl;
		cout<<endl<<"Enter your choice-"<<endl;
		cin>>choice3;
		while(1)
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<endl<<"You have entered the wrong input type"<<endl;
				cout<<"Enter your choice"<<endl;
				cin>>choice3;
			}
			if(!cin.fail())
			{
				break;
			}
		}
		switch(choice3)
		{

			case 1:
				{	thread t2(Student_Register);
					t2.join();
				}
				break;
			case 2: s.Student_Login();
				break;
			case 3: break;
			default: cout<<"Invalid Choice"<<endl;
		}

				 system("read a");
				 system("clear");
		
	}
	s.student_store_data();
	return (0);
}

/**************************************************************************************
 *
 * FUNCTION NAME : Admin_Login
 *
 * DESCRIPTION   : Admin can login, modify, delete, view records of Alumni database, student database and 
 * 		   prepare a report of students who are not placed. Admin can Manages the Report for Connect Session. 
 *
 * RETURNS       : a.Edit_Alumni function
 * 		   a.delete_alumni_record function
 *		   a.list_of_connect function
 *		   a.Report_Nonplaced_Students function
 *		   a.Completed_Connect_Report function
 *		   a.Connect_Delete function
 *		   Exit - Back to main menu
 *
 *
 *
 *
 *
 *  *********************************************************************************/
int Admin_Login(void)

{
	//access to this function is mutually exclusive.
	lock_guard<mutex> lock(mylock);
	Admin a;

	const char *passcode = "UADMIN003";
	cout<<endl<<"Enter the passcode provided to you in order to access admin dashboard"<<endl;
	cin.ignore();
	string password;
	cin>>password;
	//string password = getpass(); //this getpass function will mask the password.
	if(password == passcode)
	{
		int choice6=0;
		while(choice6!=7){
			cout<<endl<<"-------------Admin dashboard-----------"<<endl;
			cout<<"1. Edit Alumni details"<<endl<<"2.Delete the Alumni recodrs" <<endl<<"3. list of connects"<<endl<<"4. Report nonplaced student"<<endl<<"5. completed connect Reports"<<endl<<"6. Delete the Connect"<<endl<<"7. Back to Main Menu"<<endl;
			cout<<endl<<"Enter your choice-"<<endl;
			cin>>choice6;
			while(1)
			{
				if(cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout<<endl<<"You have entered the wrong input type"<<endl;
					cout<<"Enter your choice"<<endl;
					cin>>choice6;
				}
				if(!cin.fail())
				{
					break;
				}
			}
			switch(choice6)
			{ 
				case 1: 

					a.Edit_Alumni();

					break;

				case 2: 
					a.delete_alumni_record();

					break;
				case 3: a.list_of_connects(); 
					break;
				case 4: a.Report_Nonplaced_Students();
					break;
				case 5 :a.Completed_Connect_Report();
					break;
				case 6 :a.Connect_Delete();
					break;
				case 7: break;
				default: cout<<"Invalid Choice"<<endl;
			}

		}
	}
	else
	{
		cout<<endl<<"Wrong credentials!"<<endl;
	}
	return (0);
}




/**************************************************************************************
 *
 * FUNCTION NAME : main
 *
 * DESCRIPTION   : This functin calls the other functions  to perform various operations by taking 
 * 	           choice from the user.
 *
 * RETURNS       : alumni_menu function
 * 		   student_menu function
 *		   Admin_menu  function
 *		   Exit -  exit the main function
 *
 *
 *  **********************************************************************************/



int main(void)
{

	int choice=0;
	while(choice!=4)
	{

		cout<<endl<<"----------Sardar University Alumni Management Portal----------"<<endl<<endl<<endl;
		cout<<"1. Alumni"<<endl<<"2. Student"<<endl<<"3. Admin"<<endl<<"4. Exit"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		while(1)
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<endl<<"You have entered the wrong input type"<<endl;
				cout<<"Enter your choice"<<endl;
				cin>>choice;
			}
			if(!cin.fail())
			{
				break;
			}
		}
		system("clear");
		switch(choice)
		{
			case 1: alumni_menu();
				break;
			case 2: student_menu();
				break;
			case 3: 
				{ thread t1(Admin_Login);
					t1.join();
				}
				break;
			case 4: break;
			default: cout<<"Invalid Choice"<<endl;
		}
		system("read a");
		system("clear");


	}
	return 0;
}

