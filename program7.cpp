#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int n,m,flag;
class variable
{
  public: void writelist();
	  void match();
	  void display();
};

void variable::writelist()
{ 
	fstream out1,out2;
  	int i;
  	char name[20];
  	out1.open("file1.txt",ios::out|ios::trunc);
  	out2.open("file2.txt",ios::out|ios::trunc);
  	cout<<"\nEnter count of names to be entered in file1: ";
  	cin>>m;
  	if(m>0)
  	cout<<"\nPlease enter names is Alphabetical order\n";
  	else
  	{
   	cout<<"\nInvalid no";
   	exit(0);
   }
   for(i=0;i<m;i++)
   { 
		cout<<"\nEnter name: ";
     	cin>>name;
     	out1<<name<<endl;
   }
   cout<<"\nEnter count of names to be entered in file2: ";
   cin>>n;
   if(n<=0)
   {
    cout<<"\nInvalid no";
    exit(0);
   }
   for(i=0;i<n;i++)
   {
     cout<<"\nEnter name: ";  cin>>name;
     out2<<name<<endl;
   }
   out1.close();
   out2.close();
}

void variable::match()
{
   char list1[100][20],list2[100][20];
   int i,j;
   fstream in1,in2;
   in1.open("file1.txt",ios::in);
   i=0;
   in2.open("file2.txt",ios::in);
   j=0;
   fstream out1;
   out1.open("file3.txt",ios::out|ios::trunc);
   while(i<m)
   in1.getline(list1[i++],20,'\n');
   while(j<n)
   in2.getline(list2[j++],20,'\n');
   i=j=0;
   while(i<m && j<n)
   {
     if(strcmp(list1[i],list2[j])==0)
     {
       out1<<list1[i]<<endl;
       flag=1;
       i++;
       j++;
     }
     else
     if(strcmp(list1[i],list2[j])<0)
       i++;
     else
       j++;
  }
     in1.close(); in2.close(); out1.close();
}

void variable::display()
{
  fstream in1;
  char name[20];
  in1.open("file3.txt",ios::in);
  if(flag)
   {
    cout<<"\nMatched list\n";
    while(1)
    {
      in1.getline(name,20,'\n');
      if(in1.eof()) break;
      cout<<name<<endl;
    }
  }
  else cout<<"\nNo matching strings";
}

int main()
{
  variable v;
  v.writelist();
  v.match();
  v.display();
  return 0;
}
