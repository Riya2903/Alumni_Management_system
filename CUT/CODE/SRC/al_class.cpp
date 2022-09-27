#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include"header.hpp"
#include<algorithm>
//#include "validation.cpp"
#include<map>
using namespace std;
map<string,string>post;

validations val;


int Alumni::alumni_get_data()
{
	cout<<"\n\nEnter Alumni Details......\n";
	while(1)
	{
		cout<<"Enter registeration  number    : ";
		cin>>register_number;
		if(val.check_alumni_register_number(register_number)==1)
		{
			break;
		}

	}
	while(1)
	{
		cout<<"Enter Full Name         : "; 
		cin>>name;
		if(val.check_string(name)==1)
		{
			if(val.check_length(name,15)==1)
			{
				break;
			}
		}
	}
	while(1)
	{

		cout<<"Enter telephone number      : "; 
		cin>>tel_no;
		if(val.check_number(tel_no)==1)
		{
			if(val.check_length(tel_no,10)==1)
			{
				break;
			}
		}
	}
	while(1)
	{
		cout<<"Enter email id          : ";
		cin>>email_id;
		if(val.Email_check(email_id))
		{

			break;
		}
		cout<<endl<<"Invalid Email Id!"<<endl;
	}
	while(1)
	{
		cout<<"Enter current address: ";
		cin>>present_address;
		if(present_address.length()<5)
		{
			cout<<"Too small!"<<endl;
			continue;
		}
		break;
	}
	while(1)
	{
		cout<<"Enter department: ";
		cin>>department;
		if(val.check_department(department)==1)
		{
			break;
		}
	}
	cout<<endl;
	cout<<"\n\nEnter professional Details......\n";
	while(1)
	{
		cout<<"Enter company    : ";
		cin>>company;
		if(val.check_string(company)==1)
		{
			break;
		}

	}
	while(1)
	{
		cout<<"Enter designation         : ";
		cin>>designation;
		if(val.check_string(designation)==1)
		{
			break;
		}
	}
	while(1)
	{
		cout<<"Enter technology      : ";
		cin>>technology;
		if(val.check_string(technology)==1)
		{
			break;
		}
	}
	while(1)
	{
		cout<<"Enter location         : "; 
		cin>>location;
		if(val.check_string(location)==1)
		{
			break;
		}
	}
	while(1)
	{
		cout<<"Enter years of experience    : "; 
		cin>>years_of_experience;
		if(val.check_number(years_of_experience)==1)
		{
			break;
		}
	}
	while(1)
	{
		cout<<"Enter salary: "; 
		cin>>salary;
		if(val.check_number(salary)==1)
		{
			break;
		}
	}
	return 0;
}

int Alumni::View_Profile(string reg_num)
{
	//string reg_num;
	//cout<<"Please Enter your registration number"<<endl;
	//cin>>reg_num;
	for(list<Alumni>::iterator it=alm.begin();it!=alm.end();it++)
	{
	if(it->register_number==reg_num)
		{
	cout<<"\n\nAlumni Details......\n";
	cout<<"register number    : " <<it->register_number;
	cout<<"Full Name         : " <<it->name;
	cout<<" telephone number      : " <<it->tel_no;
	cout<<" email id          : " <<it->email_id;
	cout<<" current address: " <<it->present_address;
	cout<<" department: " <<it->department;
	cout<<endl;
	cout<<"\n\nprofessional Details......\n";
	cout<<" company    : "<<it->company;
	cout<<" deignation         : "<<it->designation;
	cout<<" technology      : "<<it->technology;
	cout<<" location         : "<<it->location;
	cout<<" years of experience    : "<<it->years_of_experience;
	cout<<" salary: "<<it->salary;
	cout<<endl;
		}
	}
	return 0;
}

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
		/*	if(val.check_alumni_register_number(reg_num)==1)
			{
			cout<<"Wrong credentials"<<endl;
			}
			else
			{
			}*/
		for(auto it = alm.begin(); it!=alm.end();it++)
		{
			if(it->register_number==reg_num)
			{
				while(choice4!=5)
				{
					cout<<"---------dashboard--------"<<endl;
					cout<<"1.view profile\n2.create post\n3.view post\n4.Edit Details\n5.Exit."<<endl;
					cin>>choice4;
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
			}
		}
	}
	else
	{
		cout<<"Wrong credentials!"<<endl;

	}
	return 0;
}


int Alumni_Register()
{
	Alumni al;
	if(al.alumni_get_data()==0)
	{
		alm.push_back(al);
	}
	return 0;
}


void Alumni::Create_Posts(string number)
{
//	string number;
	cout<<"____Job Offers/Techical stuffs____"<<endl;
	//cout<<"Enter your registeration number:"<<endl;
	//cin>>number;
		cout<<"Create your post in (100 words)"<<endl;
		cin>>posts;
		post[number] = posts;
}
void Alumni:: view_posts(string number)
{
	//string number;
	cout<<"-------------Posts from the alumni dashboard-------- "<<endl;
	//cout<<"Enter the alumni registration number"<<endl;
	///cin>>number;
	cout<<post[number] <<endl;

}


int Alumni::Edit_Details(string reg_num)
{
	if(alm.empty())
	{
		cout<<endl<<"Alumni list is empty."<<endl;
		return 1;
	}
	int flag =0;
//	string reg_num;
/*	while(1)
	{
		cout<<endl<<"Enter Register number of Alumni-";
		cin>>reg_num;
		if(val.check_alumni_register_number(reg_num)==1)
		{
			break;
		}
	}*/
	flag=0;
	for(list<Alumni>::iterator it=alm.begin();it!=alm.end();it++)
	{
		if(it->register_number==reg_num)
		{
			flag=1;
			cout<<"------------------------------------------------"<<endl<<endl;
			cout<<"                             Previous Details                    "<<endl;
			cout<<"Company name: "<<it->company<<endl<<"Technology: "<<it->technology<<endl<<"Location: "<<it->location<<endl<<"Years of Experiance : "<<it->years_of_experience<<endl<<"Salary :"<<it->salary<<endl<<"Designation: "<<it->designation<<endl;
			int choice;
			int option;
			cout<<"Do you want to continue editing - (0-Yes/1-No) "<<endl;
			cin>>option;
			if(option==0)
			{
				for(list<Alumni>::iterator it=alm.begin();it!=alm.end();it++);

				cout<<"Enter 1 to edit Company name : "<<endl;
				cin>>choice;
				if(choice==1)
				{

				
					while(1)
					{
						cout<<"Enter Updated Company name: ";
						getline(cin>>ws,it->company);
		
						if(val.check_string(it->company)==1)
						{
							break;
						}
					}
				}
				cout<<"Enter 1 to edit Technology : "<<endl;
				cin>>choice;
				if(choice==1)
				{

					while(1)
					{
						cout<<"Enter Updated Technology: ";
						getline(cin>>ws,it->technology);

						if(val.check_string(it->technology)==1)
						{
							break;
						}
					}
				}

				cout<<"Enter 1 to edit Location : "<<endl;
				cin>>choice;
				if(choice==1)
				{

					while(1)
					{
						cout<<"Enter Updated Location: ";
						getline(cin>>ws,it->location);

						if(val.check_string(it->location)==1)
						{
							break;
						}
					}
				}

				cout<<"Enter 1 to edit Years of Experience : "<<endl;
				cin>>choice;
				if(choice==1)
				{

					while(1)
					{
						cout<<"Enter Updated Years of Experience: ";
						getline(cin>>ws,it->years_of_experience);

						if(val.check_number(it->years_of_experience)==1)
						{
							break;
						}
					}
				}

				cout<<"Enter 1 to edit Salary : "<<endl;
				cin>>choice;
				if(choice==1)
				{

					while(1)
					{
						cout<<"Enter Updated Salary: ";
						getline(cin>>ws,it->salary);

						if(val.check_number(it->salary)==1)
						{
							break;
						}
					}
				}

				cout<<"Enter 1 to edit Designation : "<<endl;
				cin>>choice;
				if(choice==1)
				{

					while(1)
					{
						cout<<"Enter Updated Designation: ";
						getline(cin>>ws,it->designation);

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
	return 0;
}
