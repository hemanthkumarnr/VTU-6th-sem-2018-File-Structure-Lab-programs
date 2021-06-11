#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>

using namespace std;

class student
{
    public:char name[15],usn[15],age[5],sem[5],branch[15],buffer[100];
};

student s2[100];

void writeRecord()
{
  fstream app;
  student s;
  app.open("student1.txt",ios::out|ios::app);
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

  strcpy(s.buffer,s.name);
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

void search()
{
  fstream in;
  char usn[15],extra[45];
  in.open("student1.txt",ios::in);
  if(!in)
  {
      cout<<"\nUnable to open the file in input mode"; 
      exit(0);
  }
  cout<<"\nEnter the record's usn you want to search = "; cin>>usn;
  
  student s;

  while(!in.eof())
  {
    in.getline(s.name,15,'|');
    in.getline(s.usn,15,'|');
    in.getline(s.age,5,'|');
    in.getline(s.sem,5,'|');
    in.getline(s.branch,15,'\n');

    if(strcmp(s.usn,usn)==0)
    {
        cout<<"\nRecord found";
        cout<<"\nname\tusn\tage\tsem\tbranch";
        cout<<"\n"<<s.name<<"\t"<<s.usn<<"\t"<<s.age<<"\t"<<s.sem<<"\t"<<s.branch; 
        return;
    }
  }

  cout<<"\nRecord not found";
  return;
}

void displayFile()
{
  student s;
  int c,I;

  fstream in;
  in.open("student1.txt",ios::in);
  if(!in)
  {
      cout<<"\ncannot open the file in output mode"; 
      exit(0);
  }

  I=0;
  cout<<"Name"<<"\t\t"<<"Usn"<<"\t\t"<<"Age"<<"\t\t"<<"Sem"<<"\t\t"<<"Branch\n";
  while(!in.eof())
  {
      in.getline(s.name,15,'|');
      in.getline(s.usn,15,'|');
      in.getline(s.age,5,'|');
      in.getline(s.sem,5,'|');
      in.getline(s.branch,15,'\n');
      cout<<"\n"<<s.name<<"\t\t"<<s.usn<<"\t\t"<<s.age<<"\t\t"<<s.sem<<"\t\t"<<s.branch;
      I++;
  }
  in.close();
}

void modify()
{
  fstream in;
  char usn[15];
  int I,j;
  student s1[100];

  in.open("student1.txt",ios::in);
  if(!in)
  {
      cout<<"\nUnable to open the file in input mode"; 
      exit(0);
  }

  cout<<"\nEnter the usn";
  cin>>usn;

  I=0;

  while(!in.eof())//Loop through end of file & extract all records
  {
      in.getline(s1[I].name,15,'|');
      in.getline(s1[I].usn,15,'|');
      in.getline(s1[I].age,5,'|');
      in.getline(s1[I].sem,5,'|');
      in.getline(s1[I].branch,15,'\n');
      I++;
  }

  I--;
  for(j=0;j<I;j++)
  {
      if(strcmp(usn,s1[j].usn)==0)
      {
          cout<<"\nThe old values of the record with usn "<<usn<<" are "; 
          cout<<"\nname   = "<<s1[j].name;
          cout<<"\nusn    = "<<s1[j].usn;
          cout<<"\nage    = "<<s1[j].age;
          cout<<"\nsem    = "<<s1[j].sem;
          cout<<"\nbranch = "<<s1[j].branch;

          cout<<"\nEnter the new values \n";
          cout<<"\nname   = ";  cin>>s1[j].name;
          cout<<"\nusn    = ";  cin>>s1[j].usn;
          cout<<"\nage    = ";  cin>>s1[j].age;
          cout<<"\nsem    = ";  cin>>s1[j].sem;
          cout<<"\nbranch = ";  cin>>s1[j].branch;
          break;
      }//end of if
  }//end of for

    if(j==I)
    {
        cout<<"\nThe record with usn "<<usn<<" is not present"; 
        return;
    }

    in.close();

    fstream out1;
    out1.open("student1.txt",ios::out);
    if(!out1)
    {
          cout<<"\nUnable to open the file in output mode"; 
          return;
    }

    student s;
    for(j=0;j<I;j++)
    {
        out1<<s1[j].name<<'|'<<s1[j].usn<<'|'<<s1[j].age<<'|'<<s1[j].sem<<'|'<<s1[j].branch<<'\n';
    }
    out1.close();
}

int  main()
{
  int choice;

  for(;;)
  {
      cout<<"\n0:exit";
      cout<<"\n1:write to file";
      cout<<"\n2:display the file";
      cout<<"\n3:modify the file";
      cout<<"\n4:search";
      cout<<"\n\nEnter the choice";
      cin>>choice;
      switch(choice)
      {
          case 1:writeRecord();break;
          case 2:displayFile();break;
          case 3:modify();break;
          case 4:search();break;
          case 0:exit(0);
          default:cout<<"\nInvalid input....";break;
      }
  }
}
