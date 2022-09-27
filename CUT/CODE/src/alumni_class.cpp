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
#pragma once
#include <mutex>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include"alumni_class.hpp"
#include<algorithm>
#include<map>
#include <limits>
#include<string.h>
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
		cin>>register_number;
		if(!alm.empty())
		{
		 //auto keyword will automatically detects and assigns a data type to the variable.
			for(auto it = alm.begin();it!=alm.end();it++)
			{
				if(strcmp(register_number,it->register_number)==0)
				{
					cout<<endl<<"This registeration number already exists!"<<endl;
					return 1;

				}
			}
		}
		if(val.check_alumni_register_number(register_number)==1) //If successfully validated
		{
			break;
		}

	}
	while(1)
	{
		cout<<endl<<"Enter First  Name              : "; 
		cin.ignore();
		cin>>name;
		cin.clear();
		if(val.check_string(name)==1)
		{
			if(strlen(name)>=3)
			{
				if(val.check_length(name,15)==1)
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
/*	while(1)
	{

		cout<<endl<<"Enter telephone number       : "; 
		cin.ignore();
		cin>>tel_no;
		cin.clear();
		if(val.check_number(tel_no)==1)
		{
			if(val.check_length(tel_no,10)==1)
			{
				break;
			}

		}
	}*/
	while(1)
	{
		cout<<endl<<"Enter email id                : ";
		cin.ignore();
		cin>>email_id;
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
		cin>>present_address;
		cin.clear();
		if(strlen(present_address)<5)
		{
			cout<<"The length of current address is too small!"<<endl;
			continue;
		}
		break;
	}
	while(1)
	{
		cout<<endl<<"Enter department             : ";
		cin>>department;
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
		cin>>company;
		cin.clear();
		if(strlen(company)>2)
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
		cin>>designation;
		cin.clear();
		if(strlen(designation)>2)
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
		cin>>technology;
		cin.clear();
		if(strlen(technology)>0)
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
		cin>>location;
		cin.clear();
		if(strlen(location)>2)
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
		cin>>years_of_experience;
		cin.clear();
		if(strlen(years_of_experience)<2)
		{

			if(val.check_number(years_of_experience)==1) 
			{
				break;
			}
		}
		else
		{
			cout<<"Invalid years of experience"<<endl;
		}
	}
	while(1)
	{
		cout<<endl<<"Enter salary                  : "; 
		cin>>salary;
		if(strlen(salary)>2)
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



int Alumni::View_Profile(char *reg_num)
{
	for(list<Alumni>::iterator it=alm.begin();it!=alm.end();it++)
	{
		if(strcmp(it->register_number,reg_num)==0)
		{
			cout<<endl<<endl<<"......ALUMNI PERSONAL DETAILS......"<<endl;
			cout<<endl<<"Register number    : " <<it->register_number<<endl;
			cout<<endl<<"Full Name          : " <<it->name<<endl<<endl;
			//cout<<endl<<"Telephone number   : " <<it->tel_no<<endl;
			cout<<endl<<"Email id           : " <<it->email_id<<endl;
			cout<<endl<<"Current address    : " <<it->present_address<<endl;
			cout<<endl<<"Department         : " <<it->department<<endl;
			cout<<endl;
			cout<<"......ALUMNI PROFESSIONAL DETAILS......"<<endl;
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
	char reg_num[10];
	int flag = 0;
	cout<<"Enter your registration number "<<endl;
	cin>>reg_num;
	cout<<"Enter the password"<<endl;
	cin.ignore();
	
	char password[7];
       cin>>password;
	if(strcmp(password,reg_num)==0)
	{
		for(auto it = alm.begin(); it!=alm.end();it++)
		{
		if(strcmp(it->register_number,reg_num)==0)
			{
				flag = 1;
				int choice4=0;
				while(choice4!=5)
				{
					cout<<endl<<endl<<"---------DASHBOARD--------"<<endl<<endl;
					cout<<"1.View Profile\n2.Create Post or update your post\n3.View Post\n4.Edit Details\n5.Exit."<<endl;
					cout<<endl<<"Enter your choice-"<<endl;
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

				
			system("read a");
			system("clear");
				}
			}
		}
	}
	else 
	{
		cout<<"Wrong credentials"<<endl;
	}
	if(flag==0)
	{
		cout<<"Wrong values!"<<endl;

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



void Alumni::Create_Posts(char *number)
{
	cout<<endl<<".....Job Offers/Techical stuffs....."<<endl;
	cout<<endl<<"Create your post in (100 words)"<<endl;
	getline(cin>>ws,posts);
	post[number]=posts; //post is a map with key as register number and value as posts.
}



/**********************************************************************
  Function Name: view_posts

Description : This function is used to view the posts from alumni 
dashboard.

Returns :

 **********************************************************************/



void Alumni:: view_posts(char *number)
{
		string s;
		s = number;
	try
	{
		if(post.find(s)==post.end()) //If register number does not exists.
			throw s;
		else
		{
			cout<<endl<<"-------------Posts from the alumni dashboard--------- "<<endl;
			cout<<"    ALUMNI:  "<<number<<endl;
			cout<<endl<<post[s] <<endl;

		}
	}
	catch(...)
	{
		cout<<"No post from "<<s<<" Alumni exists!"<<endl;
	}

}



/**********************************************************************
  Function Name: Edit_Details

Description : This function is used to edit professinal details of alumni.

Returns :

 **********************************************************************/



int Alumni::Edit_Details(char *reg_num)
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
				if(strcmp(it->register_number,reg_num)==0)
				{
					flag=1;
					cout<<endl<<"------------------------------------------------"<<endl<<endl;
					cout<<endl<<"                          PREVIOUS DETAILS                    "<<endl;
					cout<<"Company name: "<<it->company<<endl<<"Technology: "<<it->technology<<endl<<"Location: "<<it->location<<endl<<"Years of Experiance : "<<it->years_of_experience<<endl<<"Salary :"<<it->salary<<endl<<"Designation: "<<it->designation<<endl;
					char choice[10];
					char option[10];
					cout<<endl<<"Do you want to continue editing - (Yes/No) "<<endl;
					cin>>option;
					if(strcmp(option,"yes")==0)
					{
						for(list<Alumni>::iterator it=alm.begin();it!=alm.end();it++);

						cout<<"Enter yes to edit Company name : "<<endl;
						cin>>choice;
						if(strcmp(choice,"yes")==0)
						{


							while(1)
							{
								cout<<"Enter Updated Company name : ";
								cin>>it->company;
								cin.clear();

								if(val.check_string(it->company)==1)
								{
									break;
								}
							}
						}
						cout<<"Enter yes to edit Technology : "<<endl;
						cin>>choice;
						if(strcmp(choice,"yes")==0)
						{

							while(1)
							{
								cout<<"Enter Updated Technology : ";
								cin>>it->technology;
								cin.clear();
								if(val.check_string(it->technology)==1)
								{
									break;
								}
							}
						}

						cout<<"Enter yes to edit Location : "<<endl;
						cin>>choice;
						if(strcmp(choice,"yes")==0)
						{

							while(1)
							{
								cout<<"Enter Updated Location : ";
								cin>>it->location;
								cin.clear();
								if(val.check_string(it->location)==1)
								{
									break;
								}
							}
						}

						cout<<"Enter yes to edit Years of Experience : "<<endl;
						cin>>choice;
						if(strcmp(choice,"yes")==0)
						{

							while(1)
							{
								cout<<"Enter Updated Years of Experience : ";
								cin>>it->years_of_experience;
								cin.clear();
								if(val.check_number(it->years_of_experience)==1)
								{
									break;
								}
							}
						}

						cout<<"Enter yes to edit Salary : "<<endl;
						cin>>choice;
						if(strcmp(choice,"yes")==0)
						{

							while(1)
							{
								cout<<"Enter Updated Salary : ";
								cin>>it->salary;
								cin.clear();
								if(val.check_number(it->salary)==1)
								{
									break;
								}
							}
						}

						cout<<"Enter yes to edit Designation : "<<endl;
						cin>>choice;
						if(strcmp(choice,"yes")==0)
						{

							while(1)
							{
								cout<<"Enter Updated Designation : ";
								cin>>designation;
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
void Alumni::fetch_data()
{
	Alumni a2;
	fstream fl;
	fl.open("Alumni_database", ios::in|ios::binary);
	if(!fl)
	{
		cout<<"Can't open this file"<<endl;
	}
	fl.read((char *)&tmp,sizeof(temp));
	while(!fl.eof())
	{
		
		strcpy(a2.register_number,tmp.register_number);
		strcpy(a2.name,tmp.name);
		strcpy(a2.email_id,tmp.email_id);
		strcpy(a2.present_address,tmp.present_address);
		strcpy(a2.department,tmp.department);
		strcpy(a2.company,tmp.company);
		strcpy(a2.designation,tmp.designation);
		strcpy(a2.technology,tmp.technology);
		strcpy(a2.location,tmp.location);
		strcpy(a2.years_of_experience,tmp.years_of_experience);
		strcpy(a2.salary,tmp.salary);
		alm.push_back(a2);
		fl.read((char *)&tmp,sizeof(temp));
	}
/*	for(list<Alumni>::iterator a2=alm.begin();a2!=alm.end();a2++)
	{
		cout<<"    "<<a2->register_number;
	}*/
	fl.close();
}
void Alumni::store_data() 
{
	fstream fl;
	fl.open("Alumni_database",ios::out|ios::binary);
	if(!fl)
	{
		cout<<"No such file exists!";
	}
	if(!alm.empty())
			{
				cout<<"Writing into the file"<<endl;
/*	for(list<Alumni>::iterator a2=alm.begin();a2!=alm.end();a2++)
	{
		cout<<"    "<<a2->register_number;
	}*/
	for(list<Alumni>::iterator a2=alm.begin();a2!=alm.end();a2++)
	{
		strcpy(tmp.register_number,a2->register_number);
		strcpy(tmp.name,a2->name);
		strcpy(tmp.email_id,a2->email_id);
		strcpy(tmp.present_address,a2->present_address);
		strcpy(tmp.department,a2->department);
		strcpy(tmp.company,a2->company);
		strcpy(tmp.designation,a2->designation);
		strcpy(tmp.technology,a2->technology);
		strcpy(tmp.location,a2->location);
		strcpy(tmp.years_of_experience,a2->years_of_experience);
		strcpy(tmp.salary,a2->salary);
		fl.write((char *)&tmp,sizeof(temp));
	//	cout<<"Record added"<<endl;
		
	}
			}
	else
		cout<<"List is empty"<<endl;
	//alm.clear();
	fl.close();
}
