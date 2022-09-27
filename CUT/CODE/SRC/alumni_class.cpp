/************************************************************************
*** FILENAME    : Alumni_class.cpp
*
* * DESCRIPTION : This file defines the function that would be used by the 
*                 Alumni to Register and login to the Alumni portal and after 
*                 login alumni will get access to the Dashboard.   
*
* Revision History:
*
*      Date                            NAME                       Reason
*       
*    27th Sep 2022                   Riya Malik                -----------   
*
* *************************************************************************/

#include <mutex>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include"alumni_class.hpp"
#include<algorithm>
//#include "validation.cpp"
#include<map>
#include <limits>
mutex accum;
using namespace std;
map<string,string>post;

validations val;

/**********************************************************************
  Function Name: alumni_get_data

Description : This function is used to get alumni details like Alumni
Personal and Professional Details. 

Returns :

 **********************************************************************/



int Alumni::alumni_get_data()
{
	cout<<endl<<"......Enter Alumni Details......"<<endl;
	while(1)
	{
		cout<<"Enter registration  number    : ";
	//	cin.ignore();
		cin>>register_number;
		if(!alm.empty())
		{
			for(auto it = alm.begin();it!=alm.end();it++)
			{
				if(register_number == it->register_number)
				{
					cout<<endl<<"This registeration number already exists!"<<endl;
					return 1;

				}
			}
		}
		if(val.check_alumni_register_number(register_number)==1)
		{
			break;
		}

	}
	while(1)
	{
		cout<<endl<<"Enter Full Name              : "; 
		cin.ignore();
		getline(cin>>ws,name);
		cin.clear();
		if(val.check_string(name)==1)
		{
			if(name.length()>=3)
			{
				if(val.check_length(name,len)==1)
				{
					break;
				}
			}
			else
			{
				cout<<endl<<"The length of name is too small"<<endl;
			}
		}
	}
	while(1)
	{

		cout<<endl<<"Enter telephone number       : "; 
		getline(cin,tel_no);
		cin.clear();
		if(val.check_number(tel_no)==1)
		{
			if(val.check_length(tel_no,size)==1)
			{
				break;
			}

		}
	}
	while(1)
	{
		cout<<endl<<"Enter email id                : ";
		getline(cin,email_id);
		cin.clear();
		if(val.Email_check(email_id))
		{

			break;
		}
		cout<<endl<<"Invalid Email Id!"<<endl;
	}
	while(1)
	{
		cout<<endl<<"Enter current address        : ";
		getline(cin>>ws,present_address);
		cin.clear();
		if(present_address.length()<5)
		{
			cout<<"The length of current address is too small!"<<endl;
			continue;
		}
		break;
	}
	while(1)
	{
		cout<<endl<<"Enter department             : ";
		getline(cin,department);
		cin.clear();
		if(val.check_department(department)==1)
		{
			break;
		}
	}
	cout<<endl;
	cout<<endl<<endl<<"......Enter professional Details......"<<endl;
	while(1)
	{
		cout<<endl<<"Enter company name           : ";
		getline(cin,company);
		cin.clear();
		if(company.length()>2)
		{

			if(val.check_string(company)==1)
			{
				break;
			}
		}
		else
		{
			cout<<"The length of Company name is too small"<<endl;
		}

	}
	while(1)
	{
		cout<<endl<<"Enter designation            : ";
		getline(cin,designation);
		cin.clear();
		if(designation.length()>2)
		{
			if(val.check_string(designation)==1)
			{
				break;
			}
		}
		else
		{
			cout<<"The length of the designation is too small"<<endl;
		}
	}
	while(1)
	{
		cout<<endl<<"Enter technology             : ";
		getline(cin,technology);
		cin.clear();
		if(technology.length()>1)
		{
			if(val.check_string(technology)==1)
			{
				break;
			}
		}
		else
		{
			cout<<"The length of the technology is too small"<<endl;
		}
	}
	while(1)
	{
		cout<<endl<<"Enter location               : "; 
		getline(cin,location);
		cin.clear();
		if(location.length()>2)
		{

			if(val.check_string(location)==1)
			{
				break;
			}
		}
		else
		{
			cout<<"The length of the location is too small"<<endl;
		}
	}
	while(1)
	{
		cout<<endl<<"Enter years of experience    : "; 
		getline(cin,years_of_experience);
		cin.clear();
		if(years_of_experience.length()<2)
		{

			if(val.check_number(years_of_experience)==1) 
			{
				break;
			}
		}
		else
		{
			cout<<"The length of years of experience is too big"<<endl;
		}
	}
	while(1)
	{
		cout<<endl<<"Enter salary                  : "; 
		getline(cin,salary);
		if(salary.length()>2)
		{
			if(val.check_number(salary)==1)
			{
				break;
			}
		}
		else
		{
			cout<<"The length of the salary is too small"<<endl;
		}
	}
	return 0;
}

/**********************************************************************
  Function Name: view_profile

Description : This function is used to view the details of alumni.

Returns :

 **********************************************************************/



int Alumni::View_Profile(string reg_num)
{
	for(list<Alumni>::iterator it=alm.begin();it!=alm.end();it++)
	{
		if(it->register_number==reg_num)
		{
			cout<<endl<<endl<<"......ALUMNI PERSONAL DETAILS......"<<endl;
			cout<<endl<<"Register number    : " <<it->register_number<<endl;
			cout<<endl<<"Full Name          : " <<it->name<<endl<<endl;
			cout<<endl<<"Telephone number   : " <<it->tel_no<<endl;
			cout<<endl<<"Email id           : " <<it->email_id<<endl;
			cout<<endl<<"Current address    : " <<it->present_address<<endl;
			cout<<endl<<"Department         : " <<it->department<<endl;
			cout<<endl;
			cout<<endl<<endl<<"......ALUMNI PROFESSIONAL DETAILS......"<<endl;
			cout<<endl<<"Company Name       : "<<it->company<<endl;
			cout<<endl<<"Designation        : "<<it->designation<<endl;
			cout<<endl<<"Technology         : "<<it->technology<<endl;
			cout<<endl<<"Location           : "<<it->location<<endl;
			cout<<endl<<"Years of experience: "<<it->years_of_experience<<endl;
			cout<<endl<<"Salary             : "<<it->salary<<endl;
			cout<<endl;
		}
	}
	return 0;
}

/**********************************************************************
  Function Name: Alumni_Login

Description : This function is used for Alumni to login to portal by 
entering valid credentials.

Returns :

 **********************************************************************/


int Alumni :: Alumni_Login()
{
	string reg_num;
	string pass;
	int choice4=0;
	cout<<"Enter your registration number "<<endl;
	cin>>reg_num;
	cout<<"Enter the password"<<endl;
	cin>>pass;
	if(pass==reg_num)
	{
		for(auto it = alm.begin(); it!=alm.end();it++)
		{
			if(it->register_number==reg_num)
			{
				while(choice4!=5)
				{
					cout<<endl<<endl<<"---------DASHBOARD--------"<<endl<<endl;
					cout<<"1.View Profile\n2.Create Post or update your post\n3.View Post\n4.Edit Details\n5.Exit."<<endl;
					cin>>choice4;
					while(1)
					{
						if(cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(),'\n');
							cout<<endl<<"You have entered the wrong input type"<<endl;
							cout<<"Enter your choice"<<endl;
							cin>>choice4;
						}
						if(!cin.fail())
						{
							break;
						}
					}
					switch(choice4)
					{
						case 1: View_Profile(reg_num);
							break;
						case 2: Create_Posts(reg_num);
							break;
						case 3: view_posts(reg_num);
							break;
						case 4: Edit_Details(reg_num);
							break;
						case 5: break;
						default: cout<<"Invalid choice!"<<endl;
					}

				}
				system("read a");
				system("clear");
			}
		}
	}
	else
	{
		cout<<"Wrong credentials!"<<endl;

	}
	return 0;
}


/**********************************************************************
 Function Name: Alumni_Register

Description : This function is used for the alumni to register into
the portal by giving personal and professional details..

Returns :

 **********************************************************************/


int Alumni_Register()
{
	Alumni al;
	//The access to this code section is mutually exclusive.
	if(al.alumni_get_data()==0)
	{
		accum.lock();
		alm.push_back(al);
		accum.unlock();
	}
	return 0;
}



/**********************************************************************
 Function Name: Create_Posts

Description : This function allows the alumni to create and update post regarding
job posts and technical information considering that one alumni have only one post..

Returns :

 **********************************************************************/



void Alumni::Create_Posts(string number)
{
	cout<<endl<<".....Job Offers/Techical stuffs....."<<endl;
	cout<<endl<<"Create your post in (100 words)"<<endl;
	getline(cin>>ws,posts);
	post[number] = posts;
}



/**********************************************************************
 Function Name: view_posts

Description : This function is used to view the posts from alumni 
dashboard.

Returns :

 **********************************************************************/



void Alumni:: view_posts(string number)
{
	try
	{
		if(post.find(number)==post.end())
			throw number;
		else
		{
		cout<<endl<<"-------------Posts from the alumni dashboard--------- "<<endl;
		cout<<"          ALUMNI:  "<<number<<endl;
		cout<<endl<<post[number] <<endl;

		}
	}
	catch(string number)
	{
		cout<<"No post from this Alumni exists!"<<endl;
	}

}



/**********************************************************************
  Function Name: Edit_Details

Description : This function is used to edit professinal details of alumni.

Returns :

 **********************************************************************/



int Alumni::Edit_Details(string reg_num)
{
	try
	{
	if(alm.empty())
	{
		throw alm.empty();
	}
	else
	{
	int flag =0;
	flag=0;
	for(list<Alumni>::iterator it=alm.begin();it!=alm.end();it++)
	{
		if(it->register_number==reg_num)
		{
			flag=1;
			cout<<endl<<"------------------------------------------------"<<endl<<endl;
			cout<<endl<<"                          PREVIOUS DETAILS                    "<<endl;
			cout<<"Company name: "<<it->company<<endl<<"Technology: "<<it->technology<<endl<<"Location: "<<it->location<<endl<<"Years of Experiance : "<<it->years_of_experience<<endl<<"Salary :"<<it->salary<<endl<<"Designation: "<<it->designation<<endl;
			string choice;
			string option;
			cout<<endl<<"Do you want to continue editing - (Yes/No) "<<endl;
			cin>>option;
			if(option=="yes")
			{
				for(list<Alumni>::iterator it=alm.begin();it!=alm.end();it++);

				cout<<"Enter yes to edit Company name : "<<endl;
				cin>>choice;
				if(choice=="yes")
				{


					while(1)
					{
						cout<<"Enter Updated Company name: ";
						getline(cin>>ws,it->company);
						cin.clear();

						if(val.check_string(it->company)==1)
						{
							break;
						}
					}
				}
				cout<<"Enter yes to edit Technology : "<<endl;
				cin>>choice;
				if(choice=="yes")
				{

					while(1)
					{
						cout<<"Enter Updated Technology: ";
						getline(cin>>ws,it->technology);
						cin.clear();
						if(val.check_string(it->technology)==1)
						{
							break;
						}
					}
				}

				cout<<"Enter yes to edit Location : "<<endl;
				cin>>choice;
				if(choice=="yes")
				{

					while(1)
					{
						cout<<"Enter Updated Location: ";
						getline(cin>>ws,it->location);
						cin.clear();
						if(val.check_string(it->location)==1)
						{
							break;
						}
					}
				}

				cout<<"Enter yes to edit Years of Experience : "<<endl;
				cin>>choice;
				if(choice=="yes")
				{

					while(1)
					{
						cout<<"Enter Updated Years of Experience: ";
						getline(cin>>ws,it->years_of_experience);
						cin.clear();
						if(val.check_number(it->years_of_experience)==1)
						{
							break;
						}
					}
				}

				cout<<"Enter yes to edit Salary : "<<endl;
				cin>>choice;
				if(choice=="yes")
				{

					while(1)
					{
						cout<<"Enter Updated Salary: ";
						getline(cin>>ws,it->salary);
						cin.clear();
						if(val.check_number(it->salary)==1)
						{
							break;
						}
					}
				}

				cout<<"Enter yes to edit Designation : "<<endl;
				cin>>choice;
				if(choice=="yes")
				{

					while(1)
					{
						cout<<"Enter Updated Designation: ";
						getline(cin>>ws,it->designation);
						cin.clear();
						if(val.check_string(it->designation)==1)
						{
							break;
						}
					}
				}
			}
		}
	}
	if(flag==0)
	{
		cout<<endl<<"Register number doesn't exist.";
	}
	}
	}
	catch(...)
	{
		cout<<"No Alumni Exists!"<<endl;
	}
	return 0;
}
