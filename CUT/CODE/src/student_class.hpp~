#ifndef STUDENT_CLASS_HPP
#define STUDENT_CLASS_HPP
#pragma once
#include<string>
#include<iostream>
#include<list>
//#include "validation.cpp"
#include <tuple>
#include<forward_list>
using namespace std;
class student : virtual Alumni
{
        protected:
                string student_register_number;
                string student_name;
                string student_tel_no;
                string student_email_id;
                string student_department;
		string placed;
        public:
		string ret_placed()
		{
			return this->placed;
		}

		string ret_dept()
		{
			return this->student_department;
		}
		string ret_reg()
		{
			return this->student_register_number;
		}
		int student_get_data();
                int Student_Login();
		int view_profile(string);
		int Edit_Info(string);
                int View_Alumni_Details(string);
                void Job_Posts(string);
		int ask_for_connect(string);
};
list<student> stl;
tuple<string,string,string>connect1;
forward_list<tuple<string,string,string>> all_connect;
#define size 10
#define len 15
#endif
