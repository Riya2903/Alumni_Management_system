/****************************************************************************************************************************************************************************
         FILE NAME                 : validation.cpp

         DESCRIPTION               : This file contains all the validations that can be performed while entering the Alumni
	                              details,Student details etc.

         RETURNS                   :



******************************************************************************************************************************************************************************/


#include<iostream>
#include<iomanip>
#include<cctype>
#include<string>
#include<regex>
using namespace std;

class validations
{

	public:
		//Validations for alumni register number

		int check_alumni_register_number(string register_number)
		{
			if(register_number.length() != 6)
			{
				cout<<endl<<"Register Number length should be 6"<<endl;
				return 0;
			}
			if( register_number[0] != 'U' || register_number[1] != 'A')
			{
				cout<<"First two characters of the university Alumni register number should be UA"<<endl;
				return 0;
			}
			for(int i = 2; i<6; i++)
			{
				if(isdigit(register_number[i]) != 1)
				{
					cout<<"The last four characters should be integers"<<endl;
					return 0;
				}
			}
			return 1;
		}


		//Validations for student register number


		int check_Student_register_number(string register_number)
		{
			if(register_number.length() != 6)
			{
				cout<<endl<<"Register Number length should be 6"<<endl;
				return 0;
			}
			if( register_number[0] != 'U' || register_number[1] != 'S')
			{
				cout<<"First two characters of student register number should be US"<<endl;
				return 0;
			}
			for(int i = 2; i<6; i++)
			{
				if(isdigit(register_number[i]) != 1)
				{
					cout<<"The last four characters should be integers"<<endl;
					return 0;
				}
			}
			return 1;
		}

		//Validation for the field that should have only integers

		int check_number(string number)
		{

			for(int i = 0; i<number.length(); i++)
			{
				if(isdigit(number[i]) != 1)
				{
					cout<<"The field should be only integers"<<endl;
					return 0;
				}
			}
			return 1;
		}


		//Validation for the field that should have only alphabets


		int check_string(string s)
		{

			for(int i = 0; i<s.length(); i++)
			{
				if(isalpha(s[i]) == 0)
				{
					cout<<"The field should be only alphabets"<<endl;
					return 0;
				}
			}
			return 1;
		}

		//Validation for checking the length


		int check_length(string s, int size)
		{
			if (size == 10 && s.length() != 10)
			{
				cout<<"This field should only have "<<size<<" numbers"<<endl;
				return 0;
			}
			if(s.length()>size)
			{
				cout<<"This field should not have length more than "<<size<<endl;
				return 0;
			}
			return 1;
		}

		//Validation for email checking


		bool Email_check(string email)
		{
			const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
			return regex_match(email,pattern);
		}

		//Validation for checking the department


		int check_department(string s)
		{
			if(s == "CSE" || s == "ECE" || s == "EEE" || s == "MECH" || s == "CIVIL")
			{
				return 1;
			}
			cout<<"Invalid department name"<<endl;
			return 0;
		}

};

