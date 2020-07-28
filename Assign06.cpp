//============================================================================
// Name        : Assign6.cpp
// Author      : 21411
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

typedef struct Dictionary
{
  char word[20];
  char meaning[20];
}dict;


class Hashing
{
        dict hashtable[26];

       public:

       int hashfun(char w[20])
       {
              int key=0;
              if(w[0]>='A' && w[0]<='Z')
              key=w[0]-65;
              else if(w[0]>='a' && w[0]<='z')
              key=w[0]-97;

              return key;
       }

       Hashing()
       {
              for(int i=0;i<=26;i++)
              {
                     strcpy(hashtable[i].word,"");
                     strcpy(hashtable[i].meaning,"");
              }
       }

  void readData()
  {
       dict temp;



       cout<<"\nEnter word : ";
       cin>>temp.word;
       cout<<"\nEnter meaning : ";
       cin>>temp.meaning;

       int key=hashfun(temp.word);
       assign(temp,key);
       cout<<"\nInserted successfully";

       cout<<"\nkey is : "<<key;

  }


  void assign(dict temp,int hkey)
  {
    int flag=0;

       if(strcmp(hashtable[hkey].word,"")==0)
       {
	       hashtable[hkey]=temp;
	        flag=1;
	       return ;
       }

        for(int i=hkey+1;i<26;i++)
	{
	       if(strcmp(hashtable[i].word,"")==0)
	       {
	              hashtable[i]=temp;
	               flag=1;
	              return;
	       }
	}
      if(flag==0)
      {
	       for(int i=0;i<hkey;i++)
	       {
	              if(strcmp(hashtable[i].word,"")==0)
	              {
	                     hashtable[i]=temp;
	                      return;
	              }
	       }
      }

  }

  void display()
  {
       cout<<"\n\nKey \t\tWord\tMeaning";
       for(int i=0;i<26;i++)
      {
              cout<<"\n"<<i<<"\t\t"<<hashtable[i].word<<"\t"<<hashtable[i].meaning;
      }
  }

  int search(char w[20])
  {
       int k=hashfun(w);
       if(strcmp(hashtable[k].word,w)==0)
      {
	       cout<<"\nMeaning : "<<hashtable[k].meaning;
	       return 1;
      }

    return 0;

  }


};
int main()
{
       int ch,d;
       char w[20];
        Hashing h;
       do
       {
       cout<<"\nMenu";
       cout<<"\n1.Insert";
       cout<<"\n2.Search";
       cout<<"\n3.Display";
       cout<<"\nEnter your choice : ";
       cin>>ch;
       switch(ch)
       {
       case 1:
       h.readData();
       break;

       case 2:
       cout<<"Enter a word to be search : ";
       cin>>w;
       if(!h.search(w))
       cout<<"\nNo such word present";
       break;

       case 3:
       h.display();
       break;

       default:
    	   cout<<"Wrong choice entered!"<<endl;
    	   break;

       }
       cout<<"Do you want to perform another operation(1 for yes and 0 for no)=";
       cin>>d;
       }while(d==1);
       return 0;
}
advanced da
