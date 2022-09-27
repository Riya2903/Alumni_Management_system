/************************************************************************
 *** FILENAME  : alumni_files.cpp
 *
 * * DESCRIPTION :This file contains file handling functions which transfers the file to Stl list
 *                and stl list into the file
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
 *** FUNCTION :fetch_data 
 *
 * * DESCRIPTION :Read the contents from the File Alumni database to list
 *               
 *   RETURNS     :----------
 *
 *****************************************************************/
int fetch_data()
{
	Alumni a1;
	fstream fl;
	fl.open("Alumni_database", ios::in|ios::binary);
	if(!fl)
	{
		cout<<"Can't open this file"<<endl;
		return 0;
	}
	fl.read((char *)&a1,sizeof(Alumni));
	while(!fl.eof())
	{
		alm.push_back(a1);
		fl.read((char *)&a1,sizeof(Alumni));
	}
	fl.close();
	return 0;
}



/************************************************************************
 *** FUNCTION  :store_data 
 *
 * * DESCRIPTION :write the contents of list to Alumni database file
 *               
 *   RETURNS     :----------
 *
 *****************************************************************/

int store_data() 
{
	//Alumni a2;
	fstream fl;
	fl.open("Alumni_database",ios::out|ios::binary);
	if(!fl)
	{
		cout<<"No such file exists!";
		return 0;
	}
	for(Alumni a2:alm)
	{
		fl.write((char *)&a2,sizeof(Alumni));
	}
	fl.close();
	//	alm.clear();
	return 0;
}
