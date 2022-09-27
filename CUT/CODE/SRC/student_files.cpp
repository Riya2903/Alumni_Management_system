
/************************************************************************
*** FILENAME  : student_files.cpp
*
* * DESCRIPTION :This file contains file handling functions which transfers the file to Stl list
*                and stl list into the file`
*
*
* Revision History:
*
*      Date                            NAME                       Reason
*      27 sep 2022                   --------                    ---------
*
*************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;


/************************************************************************
*** FILENAME  :student_fetch_data 
*
* * DESCRIPTION :Read the contents from the file Student database in to the list
*               
*   RETURNS     :----------
*
*****************************************************************/

int student_fetch_data()
{
	student s1;
	string details;
	ifstream fl;
	fl.open("student_database", ios::in);
	if(!fl)
	{
		cout<<"Can't open this file"<<endl;
		return 0;
	}
	fl.read((char *)&s1,sizeof(s1));
	while(!fl.eof())
	{
		stl.push_back(s1);
		fl.read((char *)&s1,sizeof(s1));
	}
	/*list<Alumni>temp
	while(!fl.is_open())
	{
	

		
			temp.push_back(details);
			
	}*/

	fl.close();
	return 0;
}


/************************************************************************
*** FILENAME  :student_store_data 
*
* * DESCRIPTION :write the contents of list to student database file
*               
*   RETURNS     :----------
*
*****************************************************************/

int student_store_data() 
{
	student s2;
	fstream fl;
	fl.open("student_database",ios::out|ios::binary);
	if(!fl)
	{
		cout<<"No such file exists!";
		return 0;
	}
	if(!stl.empty())
	/*for(auto it:stl)

	{
		it.show_data();
	}*/
	for(auto it:stl)

	{
		fl.write((char *) &it,sizeof(it));
	}
	fl.close();
//	stl.clear();
	return 0;
}

