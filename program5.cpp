#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

//Record specification
class student{
public:
char ind[5],usn[5],name[15],age[5],sem[5],branch[15];
}stdrec[20];
int no;
int get_num_records()
{
int I=0;
fstream file2;

	
	file2.open("record.txt",ios::in);
	if(!file2)
	{
		return 0;
	}
	while(!file2.fail()) //Unpacking record data
 	{
		file2.getline(stdrec[I].ind,5,'|');
		file2.getline(stdrec[I].usn,5,'|');
		file2.getline(stdrec[I].name,15,'|');
		file2.getline(stdrec[I].age,5,'|');
		file2.getline(stdrec[I].sem,5,'|');
		file2.getline(stdrec[I].branch,15,'\n');
		I++; 	
 	}
	I--;
	file2.close();
	return I;
}
void retrieve_details(char st_no[])
{

	no = get_num_records();
	for(int i=0;i<no;i++)
 	{
		if(strcmp(stdrec[i].ind,st_no)==0) 
	 	{
		cout<<"\n\n"<<"Student details : ";
		cout<<"\nUSN    :"<<stdrec[i].usn<<"\nName   :"<<stdrec[i].name<<"\nAge  :" <<stdrec[i].age<<"\nSem    :"<<stdrec[i].sem<<"\nBranch :"<<stdrec[i].branch<<"\n";
		break;
	 	}
 	}
}


void add_record()
{
char buf1[100],buf2[20];
fstream file1,file2;
int I,cnt;
student s;

	cnt=get_num_records();

	file1.open("index.txt",ios::out|ios::app);
	if(!file1)
	{
		cout<<"\nError !\n";
		exit(0);
	}

	file2.open("record.txt",ios::out|ios::app);
	if(!file2)
	{
		cout<<"\nError !\n";
		exit(0);
	}

	cout<<"\nEnter the no. of students : ";
	cin>>no;
	cout<<"\nEnter the details :\n"; 

	for(I=cnt; I<(cnt+no); I++)
   {                  
		cout<<"\nName : ";
		cin>>s.name;
		cout<<"\nAge : ";
		cin>>s.age;
		cout<<"\nUSN : ";
		cin>>s.usn;
		cout<<"\nSemester : ";
		cin>>s.sem;
		cout<<"\nBranch : ";
		cin>>s.branch;

		sprintf(buf2,"%s|%d\n",s.usn,I);
		file1<<buf2;

		sprintf(buf1,"%d|%s|%s|%s|%s|%s\n",I,s.usn,s.name,s.age,s.sem,s.branch);
		file2<<buf1;
	}
		file1.close();
		file2.close();
}

void search_record()
{
int I,flag1;
char st_no[5],st_usn[5],rt_usn[5];
fstream file1;

	cout<<"\nPlease enter the USN of the student";
	cout<<" whose record is to be displayed\n";
	cin>>st_usn;
	file1.open("index.txt",ios::in); 
	if(!file1)
	{
		cout<<"\nError !\n";
		exit(0);
	}
	flag1=0;
	while(!file1.eof())
	{
		file1.getline(rt_usn,5,'|');
		file1.getline(st_no,5,'\n');    
		if(strcmp(st_usn,rt_usn)==0)
		{
			retrieve_details(st_no);         
			flag1=1;                  
			break;
		}
	}
	if(!flag1)
	cout<<"\nRecord search failed !!\n"; 
	file1.close();
}

void delete_stdrecord(char usno[])
{
int I=0;
fstream file1,file2;

	no = get_num_records();	
	int flag=-1;
	for(I=0;I<no;I++)       //Check for the record's existence
	{
		if(strcmp(stdrec[I].ind,usno)==0)
		{
			flag=I;
			break;
		}	

	}
	if(flag==-1)                //Record not found
	{
		cout<<"\nError !\n";
		return;
	}
	if(flag==(no-1))            //Delete found last record
	{
		no--;
		cout<<"\nDeleted !\n";
		
	}
	else
	{
		for(I=flag;I<no;I++)
		{
			stdrec[I] = stdrec[I+1];
		}
		no--;
		cout<<"\nDeleted !\n";
	}

	file1.open("index.txt",ios::out);  
	file2.open("record.txt",ios::out);  
	for(I=0;I<no;I++)                   
	{                                   
		file1<<stdrec[I].usn<<"|"<<I<<"\n";
		file2<<I<<"|"<<stdrec[I].usn<<"|"<<stdrec[I].name <<"|"<<stdrec[I].age<<"|"<<stdrec[I].sem<<"|"<<stdrec[I].branch<<"\n";
	}
	file1.close();
	file2.close();
	return;
}



void delete_record()
{
int I,flag;
char st_no[5],st_usn[5],rt_usn[5];
fstream file1;

	cout<<"\nPlease enter the USN of the student ";
	cout<<" whose record is to be deleted\n";
	cin>>st_usn;
	file1.open("index.txt",ios::in);
	if(!file1)
	{
		cout<<"\nError !\n";
		exit(0);
	}
	flag=0;

	while(!file1.eof())
	{
		file1.getline(rt_usn,5,'|');      //Search index file and
		file1.getline(st_no,5,'\n');       //call deletion
		//if index found
		if(strcmp(st_usn,rt_usn)==0)
		{
			delete_stdrecord(st_no); 
			flag=1;
			break;
		}
	}
	if(!flag)
	cout<<"\nDeletion failed !\n"; 
	file1.close();
	
	
}

void display_records()
{
fstream file2;
student s;
	
	file2.open("record.txt",ios::in);
cout<<"\n\n"<<"Student details : \n";
cout<<"Index"<<"\t"<<"USN"<<"\t"<<"Name"<<"\t"<<"Age"<<"\t"<<"Sem"<<"\t"<<"Branch"<<"\t"<<endl; 
	while(!file2.fail()) //Unpacking record data
 	{
		file2.getline(s.ind,5,'|');
		file2.getline(s.usn,5,'|');
		file2.getline(s.name,15,'|');
		file2.getline(s.age,5,'|');
		file2.getline(s.sem,5,'|');
		file2.getline(s.branch,15,'\n');
cout<<s.ind<<"\t"<<s.usn<<"\t"<<s.name<<"\t"<<s.age<<"\t"<<s.sem<<"\t"<<s.branch<<"\n";
	 	
 	}
	file2.close();

}


int main()
{
int choice;

	for(;;)
	{
		cout<<"\nPlease choose :\n 1:Add Record\n";
		cout<<"2:Search Record\n 3:Delete Record\n";
		cout<<"4:Display Record\n";
		cin>>choice;
		switch(choice)
		{
			case 1: add_record(); break;
			case 2: search_record(); break;
			case 3: delete_record(); break;
			case 4: display_records();break;
			default:
			cout<<"\nInvalid choice !\n"; exit(0);	
		}
	}
}
