#pragma once
#include<string>
#include<iostream>
//#include<list>
//#include "validation.cpp"
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
//student *ptr2,*new2,*start2,*prev2;
//validations v1;
//list<Admin>adm;


