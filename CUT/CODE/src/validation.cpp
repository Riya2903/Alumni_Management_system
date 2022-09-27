/****************************************************************************************************************************************************************************
         FILE NAME                 : validation.cpp

         DESCRIPTION               : This file contains all the validations that can be performed while entering the Alumni
	                              details,Student details etc.

         RETURNS                   :



******************************************************************************************************************************************************************************/


#include<iostream>
#include<iomanip>
#include<cctype>
#include<string.h>
#include<regex>
using namespace std;

class validations
{

	public:
		//Validations for alumni register number

		int check_alumni_register_number(char *register_number)
		{
			if(strlen(register_number) != 6)
			{
				cout<<endl<<"Register Number length should be 6"<<endl;
				return 0;
			}
			char c = 'A';
			if( register_number[0]!=c)
			{
				cout<<"First  character of the university Alumni register number should be A"<<endl;
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


		int check_Student_register_number(char *register_number)
		{
			if(strlen(register_number) != 6)
			{
				cout<<endl<<"Register Number length should be 6"<<endl;
				return 0;
			}
			char c = 'S';
			if( register_number[0]!=c )
			{
				cout<<"First characters of student register number should be S"<<endl;
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

		int check_number(char *number)
		{

			for(int i = 0; i<strlen(number); i++)
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


		int check_string(char *s)
		{

			for(int i = 0; i<strlen(s); i++)
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


		int check_length(char *s, int size)
		{
			if (size == 10 && strlen(s) != 10)
			{
				cout<<"This field should only have "<<size<<" numbers"<<endl;
				return 0;
			}
			if(strlen(s)>size)
			{
				cout<<"This field should not have length more than "<<size<<endl;
				return 0;
			}
			return 1;
		}

		//Validation for email checking


		bool Email_check(char *email)
		{
			const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
			return regex_match(email,pattern);
		}

		//Validation for checking the department


		int check_department(char *s)
		{
			if(strcmp(s,"CSE")==0 || strcmp(s, "ECE")==0 || strcmp(s,"EEE")==0 || strcmp(s, "MECH")==0 || strcmp(s,"CIVIL")==0)
			{
				return 1;
			}
			cout<<"Invalid department name"<<endl;
			return 0;
		}

};

