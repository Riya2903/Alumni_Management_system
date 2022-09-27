#ifndef ADMIN_CLASS_HPP
#define ADMIN_CLASS_HPP
#pragma once
#include<string>
#include<iostream>
using namespace std;
class Admin :virtual Alumni, public student
{
    
        public:
		int Edit_Alumni();
		int delete_alumni_record();
		int list_of_connects();
		int Report_Nonplaced_Students();
		int Completed_Connect_Report();
		int Connect_Delete();
};
#endif

