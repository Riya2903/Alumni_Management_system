/*******************************************************************************************
 File Name  : header.hpp

Description : This header consists of the header files, class alumni and its member functions
*********************************************************************************************/

#ifndef ALUMNI_CLASS_HPP
#define ALUMNI_CLASS_HPP
#include<list>
#include<string.h>
#include "validation.cpp"
//#define size 10
//#define len 15
using namespace std;

struct temp
{
		char register_number[7];
		char name[15];
		char present_address[20];
		char tel_no[10];
		char email_id[20];
		char designation[20];
		char company[30];
		char technology[30];
		char years_of_experience[2];
		char location[20];
		char department[10];
		char salary[10];
		string posts;
}tmp;
class Admin;
class Alumni
{
	protected:
		char register_number[7];
		char name[15];
		char present_address[20];
		char tel_no[10];
		char email_id[20];
		char designation[20];
		char company[30];
		char technology[30];
		char years_of_experience[2];
		char location[20];
		char department[10];
		char salary[10];
		string posts;
		friend class Admin;
	public:

		// string register_number;
		//string department;
		char *ret_dept_no()
		{
			return this->department;
		}
		char *ret_name_no()
		{
			return this->name;
		}
		char *ret_reg_no()
		{
			return this->register_number;
		}
		char *ret_tel_no()
		{
			return this->tel_no;
		}
		char *ret_add_no()
		{
			return this->present_address;
		}
		char *ret_email_no()
		{
			return this->email_id;
		}

		void initpointers();
		int alumni_get_data();
		int Alumni_Login();
		virtual int Edit_Details(char *);
		void Create_Posts(char *);
		void view_posts(char *);
		virtual int View_Profile(char *);
		void store_data();
		void fetch_data();


};


list<Alumni> alm;
#endif
