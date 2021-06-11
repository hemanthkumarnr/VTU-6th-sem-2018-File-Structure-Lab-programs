#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class student{
public: char name[15],usn[5],age[5],sem[5],branch[15];
}stdrec[20],found[20];
char st_no[5],rt_name[20];
char findex[20][5];

int get_num_records()
{
fstream file;
int i=0;
	file.open("record.txt",ios::in);
	if(!file)
	{
		return 0;	
	}
	while(!file.eof())
	{	
	  	file.getline(findex[i],5,'|');
  		file.getline(stdrec[i].usn,5,'|');
  		file.getline(stdrec[i].name,15,'|');
  		file.getline(stdrec[i].age,5,'|');
  		file.getline(stdrec[i].sem,5,'|');
  		file.getline(stdrec[i].branch,15,'\n'); 
 		i++;
	}
	i--;	
	file.close();
return i;
}

void retrieve_record(char* ind)
{
 int i,no;
 no=get_num_records();	

 for(i=0;i<no;i++)
 {	
  	if(strcmp(ind,findex[i])==0)
	{
   		cout<<"USN   : "<<stdrec[i].usn<<"\nName  : "<<stdrec[i].name<<"\nAge   : "<<stdrec[i].age<<"\nSem   :"<<stdrec[i].sem<<"\nBranch  :"<<stdrec[i].branch<<endl;
	}
 }
 return;
}

void search_records()
{
 int k=0,i,no;
 char name[15],usn[5],ind[5],chusn[5],resind[5][20];
 fstream file;

 file.open("secindex.txt",ios::in);

 cout<<"Please enter the name of the student whose record is to be displayed\n";
 cin>>rt_name;

 while(!file.eof())
 {
  file.getline(name,15,'|');
  file.getline(usn,5,'|');
  file.getline(ind,5,'\n');
  if(strcmp(name,rt_name)==0)
  {
   strcpy(found[k].name,name);
   strcpy(found[k].usn,usn);
   strcpy(resind[k],ind);
   k++;  
  }
 }
 file.close();
 if(k==1)
 {
  retrieve_record(resind[0]);
  return;
 }
 else
 {
  cout<<"Please choose the candidate's USN : \n";
  for(i=0;i<k;i++)
   cout<<"Name : "<<found[i].name<<"  USN  : "<<found[i].usn<<endl;
 }
 cin>>chusn;
 for(i=0;i<k;i++)
 {
  if(strcmp(chusn,found[i].usn)==0)
  {
   retrieve_record(resind[i]);
   return;
  }
 }
 cout<<"Invalid Entry !\n"; 
 return;   
}
void delete_record(char indx[])
{
 int i,no,flag;
 fstream file1,file2;
	no=get_num_records();
 	flag=-1;
 	for(i=0;i<no;i++)
 	{
  		if(strcmp(findex[i],indx)==0)
   			flag=i;
 	}
 	if(flag==-1)
 	{
  		cout<<"Error !\n";
  		return;
 	}
	if(flag==(no-1))
 	{
  		no--;
  		cout<<"Deleted !\n";
 	} 
	else
	{
 		for(i=flag;i<no;i++)
 		{
  			stdrec[i]=stdrec[i+1];
 		}
 		no--;
 		cout<<"Deleted !\n";
	}
		file1.open("secindex.txt",ios::out);
 		file2.open("record.txt",ios::out);
 		for(i=0;i<no;i++)
 		{
  			file1<<stdrec[i].name<<"|"<<stdrec[i].usn<<"|"<<i<<"\n";
  			file2<<i<<"|"<<stdrec[i].usn<<"|"<<stdrec[i].name<<"|"<<stdrec[i].age<<"|"<<stdrec[i].sem<<"|"<<stdrec[i].branch<<"\n";
 		}
			file2.close();
 			file1.close();
 			
 			return;    
}
void remove_record()
{
 fstream file;
 int i,k=0,no;
 char name[15],usn[5],ind[5],chusn[5],resind[20][5],st_name[15];
 
	cout<<"Please enter the name of the student whose record is to be deleted\n";
   	cin>>st_name;
   	
 file.open("secindex.txt",ios::in);
 while(! file.eof())
 {
  file.getline(name,15,'|');
  file.getline(usn,5,'|');
  file.getline(ind,5,'\n');
  if(strcmp(st_name,name)==0)
  {
   strcpy(found[k].name,name);
   strcpy(found[k].usn,usn);
   strcpy(resind[k],ind);
   k++;  
  }
 }
 file.close();
 if(k==1)
 {
  delete_record(resind[0]);
  return;
 }
 else
 {
  cout<<"Please choose the candidate's USN : \n";
  for(i=0;i<k;i++)
   cout<<"Name : "<<found[i].name<<"  USN  : "<<found[i].usn<<endl;
 }
 cin>>chusn;
 for(i=0;i<k;i++)
 {
  if(strcmp(chusn,found[i].usn)==0)
  {
   delete_record(resind[i]);
   return;
  }
 }
 cout<<"Invalid Entry !\n"; 
 return;   
}
void sort_records(int no)
{
 int i,j;
 student  temp;
	for(i=0;i<no-1;i++)
	{
	  	for(j=0;j<no-i-1;j++)
		{
   			if(strcmp(stdrec[j].name,stdrec[j+1].name)>0)
   			{
    			temp=stdrec[j];
    			stdrec[j]=stdrec[j+1];
    			stdrec[j+1]=temp;
   			}
	 	}
	}	
}
void create_indexfile(int no)
{
 fstream file1,file2;
 int i;
 file1.open("secindex.txt",ios::out);
 file2.open("record.txt",ios::out);
 
	for(i=0;i<no;i++)
	{
		file1<<stdrec[i].name<<"|"<<stdrec[i].usn<<"|"<<i<<"\n";
	  	file2<<i<<"|"<<stdrec[i].usn<<"|"<<stdrec[i].name<<"|"<<stdrec[i].age<<"|"<<stdrec[i].sem<<"|"<<stdrec[i].branch<<"\n";
 	}

	file1.close();
	file2.close();
}
void add_records()
{	
 	int i,cnt,no;
	cout<<"\nEnter the no. of students : ";
	cin>>no;
	cout<<"\nEnter the details :\n"; 
	cnt = get_num_records();
	for(i=cnt;i<(cnt+no);i++)
   	{                  
		cout<<"\nName : ";
		cin>>stdrec[i].name;
		cout<<"\nAge : ";
		cin>>stdrec[i].age;
		cout<<"\nUSN : ";
		cin>>stdrec[i].usn;
		cout<<"\nSemester : ";
		cin>>stdrec[i].sem;
		cout<<"\nBranch : ";
		cin>>stdrec[i].branch;
	}
		sort_records((cnt+no));
  	 	create_indexfile((cnt+no));
}
void display_records()
{
student s;
fstream file;
int i=0;
	file.open("record.txt",ios::in);
	if(!file)
	{	
		cout<<"Error\n";
		return;	
	}
	cout<<"\nUSN\tName\tAge\tSem\tBranch\n";  
	while(!file.eof())
	{	
	  	file.getline(findex[i],5,'|');
  		file.getline(s.usn,5,'|');
  		file.getline(s.name,15,'|');
  		file.getline(s.age,5,'|');
  		file.getline(s.sem,5,'|');
  		file.getline(s.branch,15,'\n'); 
cout<<s.usn<<"\t"<<s.name<<"\t"<<s.age<<"\t"<<s.sem<<"\t"<<s.branch<<"\t"<<endl;
 	}
	file.close();
	return;
}

int main()
{
 int choice;
 for(;;)
 {
  	cout<<"Please choose :\n1:Add Record 			2:Search Record		3:Delete Record 	4:Display Record\n";
  	cin>>choice;
  	switch(choice)
        {
  	 	case 1:  add_records();      break;
  	 	case 2:  search_records();   break;
	 	case 3:  remove_record();    break;
  		case 4:  display_records(); 							break;		
		default:   cout<<"Invalid choice !\n";	exit(0);	 break;
        }   
 }
}

