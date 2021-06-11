#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<fstream>

using namespace std;

class student
{
	public:char rrn[5],name[15],usn[15],age[5],sem[5],branch[15],buffer[100];
};

student s[100];


int getNumRecords()
{
	fstream in;
	int  cnt=0;

	in.open("student.txt",ios::in);
	if(!in)
 	{
		cout<<"\ncannot open the file in input mode";
		return 0;
 	}

	while(!in.eof())
 	{		
		in.getline(s[cnt].rrn,5,'|');
		in.getline(s[cnt].name,15,'|');
		in.getline(s[cnt].usn,15,'|');
		in.getline(s[cnt].age,5,'|');
		in.getline(s[cnt].sem,5,'|');
		in.getline(s[cnt].branch,15,'\n');
		cnt++;
 	}
        cnt--;
	//returning number of records
	return cnt;
}

void search()
{
	char rrn[5];
	int cnt=0;

	cout<<"\nEnter the RRN to be searched ";
	cin>>rrn;
	cnt=getNumRecords();
	cout<<"Name\t"<<"Usn\t"<<"Age\t"<<"Sem\t"<<"Branch\n"<<endl;
	
	for(int j=0; j < cnt; j++)
 	{
		if(strcmp(rrn,s[j].rrn)==0)
   		{
			cout<<"Record found";
			cout<<"\n"<<s[j].name<<"\t"<<s[j].usn<<"\t"<<s[j].age<<"\t"<<s[j].sem<<"\t"<<s[j].branch;
			return;
   		}
 	}
	cout<<"\nRecord not found";
	return;
}

void writeRecord()
{
	fstream app;
	student s;
	char rcnt[5];
	int cnt;

	app.open("student.txt",ios::out|ios::app);
	if(!app)
 	{
		cout<<"cannot open the file in output mode"; 
		exit(0);
 	}

	cout<<"\nEnter the student name       = ";
	cin>>s.name;
	cout<<"\nEnter the usn                = ";
	cin>>s.usn;
	cout<<"\nEnter the age                = ";
	cin>>s.age;
	cout<<"\nEnter the sem                = ";
	cin>>s.sem;
	cout<<"\nEnter the branch             = ";
	cin>>s.branch;

	cnt = getNumRecords();
	cnt++;   

	sprintf(rcnt,"%d",cnt);
	strcpy(s.buffer,rcnt);
	strcat(s.buffer,"|");
	strcat(s.buffer,s.name);
	strcat(s.buffer,"|");
	strcat(s.buffer,s.usn);
	strcat(s.buffer,"|");
	strcat(s.buffer,s.age);
	strcat(s.buffer,"|");
	strcat(s.buffer,s.sem);
	strcat(s.buffer,"|");
	strcat(s.buffer,s.branch);
	strcat(s.buffer,"\n");

	app<<s.buffer;
	app.close();

}

int main()
{
	int choice;

	for(;;)
	{
		cout<<"\n0:exit";
		cout<<"\n1:Insert";
		cout<<"\n2:Search";

		cout<<"\nEnter the choice = ";
		cin>>choice;

		switch(choice)
		{
			case 1:writeRecord();break;
			case 2:search();break;
			case 0:exit(0);
			default:cout<<"\nInvalid option";
		} 
	}

}

