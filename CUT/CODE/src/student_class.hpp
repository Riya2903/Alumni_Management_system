#ifndef STUDENT_CLASS_HPP
#define STUDENT_CLASS_HPP
#include<string.h>
#include<iostream>
#include<list>
#pragma once
#include <tuple>
#include <forward_list>
#define size 10
#define len 15
using namespace std;

struct stutemp
{
                char student_register_number[7];
                char student_name[len];
                char student_tel_no[size];
                char student_email_id[20];
                char student_department[10];
		char placed[5];
}stt;
class student : virtual Alumni
{
        protected:
                char student_register_number[7];
                char student_name[len];
                char student_tel_no[size];
                char student_email_id[20];
                char student_department[10];
		char placed[5];
        public:
		char *ret_placed()
		{
			return this->placed;
		}

		char *ret_dept()
		{
			return this->student_department;
		}
		char *ret_reg()
		{
			return this->student_register_number;
		}
		int student_get_data();
                int Student_Login();
		int view_profile(char *);
		int Edit_Info(char *);
                int View_Alumni_Details(char *);
                void Job_Posts(char *);
		int ask_for_connect(char *);
		void student_fetch_data();
		void student_store_data();
};
list<student> stl;
tuple<string, string, string>connect1;
forward_list<tuple<string, string, string>> all_connect;
#endif
