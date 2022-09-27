/************************************************************************
 *** FILENAME  : admin_class.cpp
 *
 * * DESCRIPTION : This file defines the function that would be used by the program for the Admin directly login to portal using password
 *                 and Modify the Details of Alumni ,generate a Reports for Connect Session with Alumni and Student.
 *
 * Revision History:
 *
 *      Date                            NAME                       Reason
 *       
 *    27th Sep 2022                   Riya Malik                -----------   
 *
 * *************************************************************************/

#include<iostream>
#include<string.h>
#include<vector>
#include<tuple>
#include "admin_class.hpp"
#include <algorithm>
validations v2;

/*********************************************************
 * FUNCTION NAME  : Edit_Alumni
 *
 * DESCRIPTION  : The  Admin will Edit the Details of Alumni like name,email id,telephone number etc...   
 *
 * RETURNS        :-------
 *
 * *************************************************************/


int Admin::Edit_Alumni()
{


	char reg_num[7];
	cout<<endl<<"------------------Editing the alumni details--------"<<endl;
	cout<<endl<<"Enter the alumni registeration number"<<endl;
	cin>>reg_num;
	char ch[5],ch1[5];
	list<Alumni>temp;
	for(auto it = alm.begin();it!=alm.end();it++)
	{
		if(strcmp(it->register_number,reg_num)==0)
		{
			temp.push_back(*it);
		}
		else
		{
			cout<<endl<<"Do You want to edit the personal details? yes/no"<<endl;
			cin>>ch;
			if(strcmp(ch,"yes")==0)
			{
					cout<<endl<<"Enter yes to edit name: "<<endl;
					cin>>ch1;
					if(strcmp(ch1,"yes")==0)
					{
					while(1)
						{
						cout<<"Enter first name: "<<endl;
						cin>>it->name;
						cin.clear();
						if(v2.check_string(it->name)==1)
						{
							if(v2.check_length(it->name,len)==1)
							{
								break;
							}
						}
						}
					}

				/*	cout<<endl<<"Enter yes to edit telephone number: "<<endl;
					cin>>ch1;
					if(strcmp(ch1,"yes")==0)
					{
					while(1)
					{
						cout<<"Enter telephone number: ";
						cin>>it->tel_no;
						cin.clear();
						if(v2.check_number(it->tel_no)==1)
						{
							if(v2.check_length(it->tel_no,size)==1)
							{
								break;
							}
						}
						else
							continue;
					}
					}*/
					cout<<"Enter yes to edit email id: "<<endl;
					cin>>ch1;
					if(strcmp(ch1,"yes")==0)
					{
					while(1)
					{
						cout<<endl<<"Enter email id: ";

						cin>>it->email_id;
						cin.clear();
						if(v2.Email_check(it->email_id))
						{
							break;
						}
						else 
						{
							cout<<endl<<"Please enter a valid email id"<<endl;
							continue;
						}
					}
					}
					cout<<"Enter yes to edit present city: "<<endl;
					cin>>ch1;
					if(strcmp(ch1,"yes")==0)
					{
						cout<<endl<<"Enter present city: ";
						cin.ignore();
						cin>>it->present_address;
						cin.clear();	
					}
					break;

			}
				temp.push_back(*it);
			cout<<endl<<"Updated successfully"<<endl;

		}
	}
	alm.clear();
	for(list<Alumni>::iterator it = temp.begin(); it!=temp.end();it++)
	{
		alm.push_back(*it);
	}
	temp.clear();
	int flag = 0;
	try
	{
		
	for(list<Alumni>::iterator it = alm.begin(); it!=alm.end();it++)
	{
		if(strcmp(it->register_number,reg_num)==0)
		{
		cout<<endl<<"--------------------------------The updated alumni profile---------------------------------"<<endl;
		Alumni::View_Profile(reg_num);
		flag = 1;
		break;

		}
	}
	if(flag==0)
		throw flag;
	}
	catch(int flag)
	{
		cout<<"No profile to view!"<<endl;
	}

	return 0;
}

/*********************************************************
 * FUNCTION NAME  : delete_alumni_record 
 *
 * DESCRIPTION   : Admin can delete the Records of Alumni.
 *
 * RETURNS        :--------
 *
 * *************************************************************/



int Admin :: delete_alumni_record()
{
	char reg_num[10];
	cout<<endl<<"To delete an alumni record enter his registeration number: "<<endl;
	cin>>reg_num;
	int flag=0;
	list<Alumni>temp;
	if(alm.empty())
	{
		cout<<"No data in the file"<<endl;
		return 1;
	}
	
	for(list<Alumni>::iterator it = alm.begin(); it!=alm.end();it++)
	{
		if(strcmp(it->register_number,reg_num)!=0)
		{
		
			temp.push_back(*it);
		}
		else
		flag=1;

	}
	alm.clear();

	for(list<Alumni>::iterator it = temp.begin(); it!=temp.end();it++)
	{
		alm.push_back(*it);
	}
	temp.clear();
	if(flag==1)
	cout<<"Record deleted"<<endl;
	else
		cout<<"No Alumni present"<<endl;
	
	


	return 0;
}

/*********************************************************
 * FUNCTION NAME  : list_of_connect 
 *
 * DESCRIPTION   : Admin can generate the list of scheduled connect and completed connect
 *                 with student and Alumni. 
 *
 * RETURNS        :----------
 *
 * *************************************************************/



int Admin :: list_of_connects()
{
	cout<<endl<<"******************************************"<<endl;
	cout<<endl<<"----List of all scheduled connected sessions----"<<endl;//The sessions will be maintained till the system is active.

	char al[10],st[10],dept[10];
	int flag = 0;

	if(all_connect.empty())
		cout<<"No student has scheduled a connect till now! "<<endl;
	for(auto current_tuple : all_connect)
	{
		tuple<string, string, string>current = current_tuple;
		cout<<"Alumni Regsitration number: "<<get<0>(current)<<"  Student Registration number: "<<get<1>(current)<<endl;

	}
	return 0;
}

/*********************************************************
 * FUNCTION NAME  :Completed_Connect_Report 
 *
 * DESCRIPTION   :Admin can generate the Report for the connect session that is completed.
 *
 * RETURNS        :----------------
 *
 * *************************************************************/


int Admin ::Completed_Connect_Report()
{
	try
	{
		if(all_connect.empty())
		{
			throw "except";
		}
		else
		{
			cout<<"*******************************************Recent Connect Session Report********************************"<<endl;
			all_connect.sort();
			auto current_tuple =  all_connect.front();
			tuple<string, string, string>current = current_tuple;
			if(get<0>(connect1).length()==6)
			{
				cout<<"Student registration number:  "<<get<1>(current)<<"     "<<" Alumni regisration number:   "<<get<0>(current)<<endl;
				cout<<"The connected session belongs to: "<<get<2>(current)<<endl;
			}
			else
			{
				cout<<"No reports to show"<<endl;
			}
		}
	}
	catch(...)
	{
		cout<<"Empty list!"<<endl;
	}

	return 0;
}

/*********************************************************
 * FUNCTION NAME  :Report_Nonplaced_Students 
 *
 * DESCRIPTION    :The Admin can generate there Report for the students who are not placed in any company.
 *
 * RETURNS        :----------
 *
 * *************************************************************/




int Admin ::Report_Nonplaced_Students()
{
	char dept[10];
	cout<<endl<<"Enter your department"<<endl;
	cin>>dept;
	try
	{
	if(v2.check_department(dept)!=1)
	{
		throw dept;
	}
	else
	{

	int flag=0;
	system("read a");
	system("clear");
	for(auto iter = stl.begin(); iter!=stl.end();iter++)
	{
		if(strcmp(iter->ret_placed(),"no")==0)
		{
			if(strcmp(iter->ret_dept(),dept)==0)
			{

				student::view_profile(iter->ret_reg());
				flag=1;

			}
		}
	}
	if(flag==0)
		cout<<endl<<"All students are placed in this department"<<endl;
	}
	}
	catch(...)
	{
		cout<<"Error! there is no such department"<<endl;
	}
		return 0;


}



/*********************************************************
* FUNCTION NAME  :Connect_Delete
*
* DESCRIPTION   :Admin can delete the connect records from the file after the connect is carried out. 
*
* RETURNS        :--------
*
* *************************************************************/



int Admin ::Connect_Delete()
{
	cout<<endl<<"The connect record is now being deleted-----"<<endl;
	try
	{
		if(!all_connect.empty())
		{
			all_connect.sort();
		all_connect.pop_front();
		}
		else
			throw all_connect.empty();
	}
	catch(...)
	{
		cout<<"Can't delete the connect anymore!"<<endl;
	}
	return 0;
}
