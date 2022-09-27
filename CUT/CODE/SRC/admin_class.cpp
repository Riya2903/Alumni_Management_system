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
#include<string>
#include<vector>
#include<tuple>
#include "admin_class.hpp"
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


	string reg_num;
	cout<<endl<<"------------------Editing the alumni details--------"<<endl;
	cout<<endl<<"Enter the alumni registeration number"<<endl;
	cin>>reg_num;
	string ch,ch1;
	list<Alumni>temp;
	for(auto it = alm.begin();it!=alm.end();it++)
	{
		if(it->register_number !=reg_num)
		{
			temp.push_back(*it);
		}
		else
		{
			cout<<endl<<"Do You want to edit the personal details? yes/no"<<endl;
			cin>>ch;
			if(ch=="yes")
			{
					cout<<endl<<"Enter yes to edit name: "<<endl;
					cin>>ch1;
					if(ch1=="yes")
					{
					while(1)
						{
						cout<<"Enter first name: "<<endl;
						getline(cin>>ws,it->name);
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

					cout<<endl<<"Enter yes to edit telephone number: "<<endl;
					cin>>ch1;
					if(ch1=="yes")
					{
					while(1)
					{
						cout<<"Enter telephone number: ";
						getline(cin,it->tel_no);
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
					}
					cout<<"Enter yes to edit email id: "<<endl;
					cin>>ch1;
					if(ch1=="yes")
					{
					while(1)
					{
						cout<<endl<<"Enter email id: ";

						getline(cin,it->email_id);
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
					if(ch1=="yes")
					{
					while(1)
						{
						cout<<endl<<"Enter present city: ";
						cin.ignore();
						getline(cin>>ws,it->present_address);
						cin.clear();
						if(it->present_address.length()>5)
						{
							break;
						}
						else
						{
							cout<<endl<<"Address should have minimum 5 characters"<<endl;
							continue;
						}


						}
				
					}


			}
				temp.push_back(*it);
		/*	cout<<endl<<"Do you want to edit professional details? yes/no"<<endl;
			cin>>ch;
			if(ch=="yes")
			{
				Alumni :: Edit_Details(reg_num);		

			}*/
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
		if(it->register_number == reg_num)
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
	string reg_num;
	cout<<endl<<"To delete an alumni record enter his registeration number: "<<endl;
	cin>>reg_num;
	list<Alumni>temp;
	for(list<Alumni>::iterator it = alm.begin(); it!=alm.end();it++)
	{
		if(it->register_number != reg_num)
		{
			
			temp.push_back(*it);
		}
	}
	alm.clear();

	for(list<Alumni>::iterator it = temp.begin(); it!=temp.end();it++)
	{
		alm.push_back(*it);
	}
	temp.clear();
	
	


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
	cout<<endl<<"----List of all scheduled connected sessions----"<<endl;

	string al,st,dept;
	int flag = 0;

	for(auto current_tuple : all_connect)
	{
		tuple<string,string,string>current = current_tuple;
		tie(al,st,dept) = current;
		if(al.length()==6)
		{
		cout<<"Alumni Regsitration number: "<<al<<"  Student Registration number: "<<st<<endl<<"Department "<<dept<<endl;
		flag=1;
		}

	}
	if(flag == 0)
		cout<<"No student has scheduled a connect till now! "<<endl;
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
	cout<<"*******************************************Recent Connect Seesion Report********************************"<<endl;
	auto current_tuple =  all_connect.front();
	tuple<string,string,string>current = current_tuple;
	if(get<0>(current).length()==6)
	{
		cout<<"Student registration number:  "<<get<1>(current)<<"     "<<" Alumni regisration number:   "<<get<0>(current)<<endl;
		cout<<"The connected session belongs to: "<<get<2>(current)<<endl;
	}
	else
	{
		cout<<"No reports to show"<<endl;
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
	string dept;
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
		if(iter->ret_placed()=="no")
		{
			if(iter->ret_dept()==dept)
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
	catch(string s)
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
	cout<<endl<<"The connect record is get deleted-----"<<endl;
	try
	{
		all_connect.pop_front();
	}
	catch(...)
	{
		cout<<"Can't delete the connect anymore!"<<endl;
	}
	return 0;
}
