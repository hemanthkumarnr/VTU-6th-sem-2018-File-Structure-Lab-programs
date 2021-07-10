#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class record
{
  public: char name[20];
	  		 char usn[20];
}rec[20];

 int no;
 fstream file[8];

 char fname[8][8]={"1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt"};

 void merge_file(char *file1,char *file2,char *filename)
 {
  int k=0;
  record recrd[50]; //temporary object(buffer) to hold data and size
  fstream f1,f2;    //big enough say more than 50.
  f1.open(file1,ios::in);
  f2.open(file2,ios::in);
  while( !f1.eof() )
  {
   f1.getline(recrd[k].name,20,'|');
   f1.getline(recrd[k++].usn,20,'\n');
  }
  while( !f2.eof() )
  {
   f2.getline(recrd[k].name,20,'|');
   f2.getline(recrd[k++].usn,20,'\n');
  }
  
  record temp;
  int t,y;
  
  for(t=0;t<k-2;t++)
  {
   for(y=0;y<k-t-2;y++)
   { 
     if(strcmp(recrd[y].name,recrd[y+1].name)>0)
     {
      temp=recrd[y];
      recrd[y]=recrd[y+1];
      recrd[y+1]=temp;
     }
   }
  }
  fstream temp1;
  temp1.open(filename,ios::out);

  for(t=1;t<k-1;t++)
  temp1<<recrd[t].name<<"|"<<recrd[t].usn<<endl;

  f1.close();
  f2.close();
  temp1.close();
  return;
 }

 void kwaymerge()
  {
   char filename[7][20]={"11.txt","22.txt","33.txt","44.txt","111.txt","222.txt","1111.txt"};
   int i;
   int k=0;
   for(i=0;i<8;i+=2)
   {
    merge_file(fname[i],fname[i+1],filename[k++]);
   }
   k=4;
   for(i=0;i<4;i+=2)
   {
     merge_file(filename[i],filename[i+1],filename[k++]);
   }

     merge_file(filename[4],filename[5],filename[6]);
  }

  int main()
  {
   int i;
   cout<<"ENter NO. of records:\t";
   cin>>no;
   cout<<"\nEnter details:\n";
   
	for(i=0;i<8;i++)
    file[i].open(fname[i],ios::out);

   for(i=0;i<no;i++)
    {
     cout<<"\nENTER NAME :\t";
     cin>>rec[i].name;
     cout<<"\nEnter USN :\t";
     cin>>rec[i].usn;
     file[i%8]<<rec[i].name<<"|"<<rec[i].usn<<endl;
    }
    for(i=0;i<8;i++)
    file[i].close();

    kwaymerge();

    fstream result;
    result.open("1111.txt",ios::in);
    cout<<"Sorted records\n";
    char name1[20],usn1[20];
    for(i=0;i<no;i++)
     {
      result.getline(name1,20,'|');
      result.getline(usn1,20,'\n');
      cout<<"NAME :"<<name1<<"\nUSN :"<<usn1<<endl;
     }
	  return 0;
   }
