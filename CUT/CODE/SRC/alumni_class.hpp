/*******************************************************************************************
 File Name  : header.hpp

Description : This header consists of the header files, class alumni and its member functions
*********************************************************************************************/


#pragma once
#include<list>
#include<string>
#include "validation.cpp"
using namespace std;

class Admin;
class Alumni
{
	protected:
		string register_number;
		string name;
		string present_address;
		string tel_no;
		string email_id;
		string designation;
		string company;
		string technology;
		string years_of_experience;
		string location;
		string department;
		string salary;
		string posts;
		friend class Admin;
	public:

		// string register_number;
		//string department;
		string ret_dept_no()
		{
			return this->department;
		}
		string ret_name_no()
		{
			return this->name;
		}
		string ret_reg_no()
		{
			return this->register_number;
		}
		string ret_tel_no()
		{
			return this->tel_no;
		}
		string ret_add_no()
		{
			return this->present_address;
		}
		string ret_email_no()
		{
			return this->email_id;
		}

		void initpointers();
		int alumni_get_data();
		int Alumni_Login();
		virtual int Edit_Details(string);
		void Create_Posts(string);
		void view_posts(string);
		virtual int View_Profile(string);
		// int fetch_data();
		//int store_data();
};
//Alumni *ptr1,*new1,*start1,*prev1;
//validations val;
list<Alumni> alm;
#define size 10
#define len 15
