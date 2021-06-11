#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

int main()
{
   char s1[25];
   fstream file1,file2;
   int i=0,j=0,x=0,c=0,kb=0;
   char filename1[25],filename2[25];
   cout<<endl<<"1 for standard i/o:"<<endl<<"2 for file i/o:"<<endl<<"enter your choice:" ;
   cin>>kb;
   switch(kb)
    {
       case 1:cout<<"enter name count:" ;
	      cin>>c;
	      for(j=1;j<=c;j++)
	      {
			cout<<endl<<"enter name"<<j<<":" ;
			cin>>s1;
			x=strlen(s1);
			cout<<"reversed name"<<j<<":" ;
			for(i=x-1;i>=0;i--)
			 cout<<s1[i];
			 cout<<endl;
	       }
	       break;
       case 2:cout<<"enter data filename:";
	      cin>>filename1;
	      cout<<"enter reversed data filename:";
	      cin>>filename2;
	      file1.open(filename1,ios::in); //reads the input file
	      file2.open(filename2,ios::out); //writes to the output file 
	      while(1)
	      {
		 file1.getline(s1,25,'\n');
		 if(file1.fail())
		 break;
		 x=strlen(s1);
		 for(i=x-1;i>=0;i--)
		   file2<<s1[i];
		   file2<<endl;
	       }
	       file1.close();// close input file
	       file2.close();// close output file 
	       break;
    }

}


