/************************************************************************
 *** FILENAME  : student_class.cpp
 *
 * * DESCRIPTION : This file defines the function that would be used by the program for the student to Register 
 *                and login to the Alumni portal and after login student will get access to the Dashboard.   
 *
 * Revision History:
 *
 *      Date                            NAME                       Reason
 *       
 *    27th Sep 2022                   Riya Malik                -----------   
 *
 * *************************************************************************/

#include<mutex>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include"student_class.hpp"
#include<algorithm>
//#include "validation.cpp"
#include<limits>
using namespace std;
validations v1;
mutex accum_mutex;



/*********************************************************
 * FUNCTION NAME  : student_get_data
 *
 * DESCRIPTION   :The student will get Register in the Alumni portal using their Details.
 *
 * RETURNS        :
 *
 * *************************************************************/


int student::student_get_data()
{
	cout<<"\n\nEnter Student Details......\n";
	while(1)
	{
		cout<<endl<<"Enter registration  number    : ";
		cin.ignore();
		cin>>student_register_number;
		cin.clear();
		if(!stl.empty())
		{
			for(auto it = stl.begin();it!=stl.end();it++)
			{
				if(strcmp(student_register_number,it->student_register_number)==0)
				{
					cout<<endl<<"This registeration number already exists!"<<endl;
					return 1;
				}
			}
		}
		if(v1.check_Student_register_number(student_register_number)==1)
		{
			break;
		}

	}
	while(1)
	{
		cout<<endl<<"Enter your first Name         : "; 
		cin.ignore();
		//getline(cin,student_name);
		cin>>student_name;
		cin.clear();
		if(v1.check_string(student_name)==1)
		{
			if(v1.check_length(student_name,len)==1 && strlen(student_name)>2 )
			{
				break;
			}
		}
	}
	while(1)
	{
		cout<<endl<<"Enter email id          : ";
		cin>>student_email_id;
		cin.clear();
		if(v1.Email_check(student_email_id))
		{

			break;
		}
		cout<<endl<<"Invalid Email Id!"<<endl;
	}

	while(1)
	{
		cout<<endl<<"Enter department   : ";
		cin>>student_department;
		cin.clear();
		if(v1.check_department(student_department)==1)
		{
			break;
		}
	}
	while(1)
	{
		cout<<endl<<"Are you placed yes/no   : ";
		cin>>placed;
		if(strcmp(placed,"yes")==0 ||strcmp(placed,"no")==0)
		{
			break;
		}
		cout<<"Enter only yes or no"<<endl;

	}
	return 0;
}

/*********************************************************
 * FUNCTION NAME  : Student_Login 
 *
 * DESCRIPTION   :The student will  login the Alumni portal using their Credentials like Registration number and  password.
 *                and performs various operations by taking the choice from the user.
 *
 *
 * RETURNS        :Edit_Info          -Edit the information of student
 *                 View_Alumni_Details-View the Deatils of Alumni
 *                 Job_Posts          -view the Job post posted by alumni
 *                 ask_for_connect    -student as for connect with alumni
 *                 View_Profile       -View the student profile
 *
 * *************************************************************/

int student:: Student_Login()
{
	int choice5=0;
	char reg_num[10];
	cout<<endl<<"Enter your registration number "<<endl;
	cin>>reg_num;
	cout<<endl<<"Enter the password"<<endl;
	cin.ignore();
	int flag = 0;
	char password[10];
	//strcpy(password,getpass()); //masking the password
	cin>>password;	
	if(strcmp(password,reg_num)==0)
	{

		for(auto it = stl.begin();it!=stl.end();it++)
		{
			if(strcmp(it->student_register_number,reg_num)==0)
			{ 
				flag=1;
				while(choice5!=6)
				{
					cout<<endl<<"---------DASHBOARD--------"<<endl;
					cout<<endl<<"1.Edit details\n2.View your department alumni details\n3.View posts\n4.Ask for a connect\n5.View Profile\n6.Exit"<<endl;
					cout<<endl<<"Enter your choice-"<<endl;
					cin>>choice5;
					while(1)
					{
						if(cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(),'\n');
							cout<<endl<<"You have entered the wrong input type"<<endl;
							cout<<"Enter your choice"<<endl;
							cin>>choice5;
						}
						if(!cin.fail())
						{
							break;
						}
					}
					switch(choice5)
					{
						case 1: Edit_Info(reg_num);
							break;
						case 2:View_Alumni_Details(reg_num);
						       break;
						case 3:Job_Posts(reg_num); 
						       break;
						case 4:ask_for_connect(reg_num);
						       break;
						case 5:view_profile(reg_num);
						       break;
						case 6: break;
						default: cout<<endl<<"Invalid options!"<<endl;

					}

				
				system("read a");
				system("clear");
				}
			}
		}
	}
	else
		cout<<"Wrong credentials"<<endl;
	if(flag==0)
	{
		cout<<endl<<"Wrong values!"<<endl;

	}
	return 0;
}


int Student_Register()
{
	student st;
	if(st.student_get_data()==0)
	{
		accum_mutex.lock();

		stl.push_back(st);
		accum_mutex.unlock();
	}

	return 0;
}





/*********************************************************
 * FUNCTION NAME  : ask_for_connect
 *
 * DESCRIPTION   :student will ask for the connect with Alumni in the same department. 
 *
 *
 * RETURNS        :----------
 *
 *
 ****************************************************/

int student :: ask_for_connect(char *reg_no)
{
	char dept[10];
	char alm_reg[10];
	for(list<student>::iterator it = stl.begin();it!=stl.end();it++)
	{
		if(strcmp(it->student_register_number,reg_no)==0)
		{
			strcpy(dept,it->student_department);
		}
	}

	try{
		if(alm.empty())
		{
			throw alm.empty();
		}
		else
		{

			int flag=0;
			for(auto iter = alm.begin(); iter!=alm.end();iter++)
			{
				if(strcmp(iter->ret_dept_no(),dept)==0)
				{
					cout<<"Alumni exists:  "<< iter->ret_reg_no()<<endl;

					flag=1;

				}
			}
			if(flag==0)
			{
				cout<<endl<<"Cannot connect! No alumni within your department."<<endl;

			}
			else
			{
				cout<<endl<<"Enter alumni reg_no from the list"<<endl;
				cin>>alm_reg;
				int check1=0;
				for(auto iter = alm.begin(); iter!=alm.end();iter++)
				{
					if(strcmp(alm_reg,iter->ret_reg_no() )==0)
					{
						check1=1;
					}
				}
				if(check1==0)
				{
					cout<<endl<<"It seems you entered the wrong value!"<<endl;
					return 0;

				}
				else
				{
					cout<<endl<<"********Connect Successfully*****"<<endl;
					cout<<endl<<"Please contact admin for this connect report"<<endl;
				}
			}
		}
		string reg, no, d;
		reg = alm_reg;
		no = reg_no;
		d = dept;
		connect1 = make_tuple(reg,no,d);
			
		all_connect.push_front(connect1);
	
	}
	catch(...)
	{
		cout<<"No alumni in the university exists!"<<endl;
	}

	return 0;
}


/*********************************************************
 * FUNCTION NAME  : Edit_Info 
 *
 * DESCRIPTION   : student will Edit the information like email and telephone umber. 
 *
 *
 * RETURNS        :---------
 *
 *
 **********************************************************/


int student::Edit_Info(char *reg_num)
{
	try
	{
		if(stl.empty())
		{
			throw stl.empty();
		}
		else
		{
			int flag=0;
			flag =0;
			for(list<student>::iterator it=stl.begin();it!=stl.end();it++)
			{
				if(strcmp(it->student_register_number,reg_num)==0)
				{
					flag=1;
					cout<<"------------------------------------------------------------------------"<<endl;
					cout<<endl<<"                         Previous Details                                "<<endl;
					cout<<endl<<"Telephone number :  "<<it->student_tel_no<<endl<<"Email Address :  "<<it->student_email_id<<endl;
					char choice[5];
					char option[5];
					cout<<endl<<"Enter yes to continue editing - "<<endl;
					cin>>option;
					if(strcmp(option,"yes")==0)
					{

						while(1)
						{
							cout<<endl<<"Enter yes to edit Email Address"<<endl;
							cin>>choice;
							if(strcmp(choice,"yes")==0)
							{
								cout<<endl<<"Enter Updated Email address: "<<endl;
								cin.ignore();
								//getline(cin>>ws,it->student_email_id);
								cin>>it->student_email_id;
								cin.clear();
								if(v1.Email_check(it->student_email_id))
								{

									break;
								}
								else
								{
									cout<<endl<<endl<<"Invalid Email Address!"<<endl;
									continue;
								}

							}
							break;			
						}
						while(1)
						{
							cout<<endl<<"Are you placed yes/no: "<<endl;
							cin>>it->placed;
							if(strcmp(it->placed,"yes")==0 ||strcmp(it->placed,"no")==0)
							{
								break;
							}
						}	
					}


				}
			}
			if(flag==0)
			{
				cout<<endl<<"Student Registration Number is not Exists."<<endl;
			}
		}
	}
	catch(...)
	{
		cout<<"No record to edit"<<endl;
	}

	return 0;
}

/*********************************************************
 * FUNCTION NAME  : view_profile 
 *
 * DESCRIPTION   : the student can see his/her profile  
 *
 * Returns      :----------
 *
 **********************************************************/




int student :: view_profile(char *reg_num)
{

	for(list<student>::iterator it=stl.begin();it!=stl.end();it++)
	{
		if(strcmp(it->student_register_number,reg_num)==0)
		{
			cout<<endl<<endl<<".........Student Details........"<<endl;
			cout<<endl<<"Register number    : " <<it->student_register_number<<endl;
			cout<<endl<<"Full Name          : " <<it->student_name<<endl;
			cout<<endl<<"Email id           : " <<it->student_email_id<<endl;
			cout<<endl<<"Department         : " <<it->student_department<<endl;
			cout<<endl<<"Placed             : "<<it->placed<<endl;
			cout<<endl;
		}
	}
	return 0;
}


/*********************************************************
 * FUNCTION NAME  : View_Alumni_Details
 *
 * DESCRIPTION    : student can view the details of Alumni.
 *
 * RETURNS        :-------
 *
 ****************************************************/




int student :: View_Alumni_Details(char *reg_no)
{

	char dept[10];
	cout<<endl<<"Enter your department"<<endl;
	cin>>dept;
	if(v1.check_department(dept)==1)
	{
		int flag = 0;
		try
		{
			for(auto iter = stl.begin(); iter!=stl.end();iter++)
			{
				if(strcmp(iter->student_register_number,reg_no)==0 && strcmp(iter->student_department,dept)==0)
				{

					for(auto iter = alm.begin(); iter!=alm.end();iter++)
					{
						if(strcmp(iter->ret_dept_no(),dept)==0)
						{
							Alumni::View_Profile(iter->ret_reg_no());
							flag = 1;

						}
					}
				}
			}
			if(flag==0)
				throw flag;
		}
		catch(int flag)
		{
			cout<<endl<<"No Profile to show ---"<<endl;
		}
	}
	else
	{
		cout<<"Enter correct value!"<<endl;
	}
	return 0;
}

/*********************************************************
 * FUNCTION NAME  : Job_Posts 
 *
 * DESCRIPTION   : the student will see the Job post/materials/Technical stuffs  posted by the Alumni.
 *
 *
 ****************************************************/



void student :: Job_Posts(char *reg_no)
{
	char dept[10];
	char check[10];
	cout<<endl<<"Enter the department name to see posts by your alumni"<<endl;
	cin>>dept;
	if(v1.check_department(dept)==1)
	{
		for(auto iter = alm.begin(); iter!=alm.end();iter++)
		{
			if(strcmp(iter->ret_dept_no(),dept)==0)
			{
				strcpy(check,iter->ret_reg_no());
				Alumni::view_posts(check);

			}
		}
	}
	else
	{
		cout<<endl<<"Enter correct department"<<endl;
	}
}
void student::student_fetch_data()
{
	student s1;
	fstream fl;
	fl.open("student_database", ios::in |ios::binary);
	if(!fl)
	{
		cout<<"Can't open this file"<<endl;
	}
	fl.read((char *)&stt,sizeof(stutemp));
	while(!fl.eof())
	{
		
		strcpy(s1.student_register_number,stt.student_register_number);
		strcpy(s1.student_name,stt.student_name);
		strcpy(s1.student_email_id,stt.student_email_id);
		strcpy(s1.student_department,stt.student_department);
		strcpy(s1.placed,stt.placed);

		stl.push_back(s1);
		fl.read((char *)&stt,sizeof(stutemp));
	}
	/*for(list<student>::iterator s1=stl.begin();s1!=stl.end();s1++)
	{
		cout<<"    "<<s1->register_number;
	}*/

	fl.close();
}
void student::student_store_data() 
{
	fstream fl;
	fl.open("student_database",ios::out|ios::binary);
	if(!fl)
	{
		cout<<"No such file exists!";
	}
	if(!stl.empty())
	{
		cout<<"Writing"<<endl;
	for(list<student>::iterator s2=stl.begin();s2!=stl.end();s2++)
	{
		strcpy(stt.student_register_number,s2->student_register_number);
		strcpy(stt.student_name,s2->student_name);
		strcpy(stt.student_email_id,s2->student_email_id);
		strcpy(stt.student_department,s2->student_department);
		strcpy(stt.placed,s2->placed);
		fl.write((char *)&stt,sizeof(stutemp));
	}
	}
	else
		cout<<"Empty list!"<<endl;
	fl.close();
}
