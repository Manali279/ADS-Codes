//============================================================================
// Name        : Assignment7.cpp
// Author      : 21411
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Node
{
	string name,attribute;
	int chain, key;

public:
	Node()
{
		attribute= " ";
		name=" ";
		key=-1;
		chain = -1;
}


	friend class symbol_table;
};

class symbol_table
{
	Node a[26];

public:

	symbol_table()
{
		for(int i=0; i<26; i++)
		{
			a[i].key ='a'+i;
		}
}
//	int hash_func(string key)
//	{
//		int key1=0;
//		if(key[0]>='a' && key[0]<='z')
//			key1=key[0]-97;
//		if(key[0]>='A' && key[0]<='Z')
//			key1=key[0]-65;
//
//		return key1;
//	}

	int hash(string);
	void insert_noreplacement(string , string, int);
	void insert_replacement(string , string, int);
	void find(string, int);
	void remove(string, int);
	void display();
};

int symbol_table::hash(string n)
{
	int index=0;
	while(index!=26)
	{
		if(a[index].key==n[0])
			break;
		index++;
	}

	return index;
}

void symbol_table::insert_noreplacement(string n, string attr, int index)
{
	int ind;
	if(a[index].name==" ")
	{
		cout << index << endl;
		a[index].name=n;
		a[index].attribute=attr;
	}

	else
	{
		cout << index << endl;
		ind = index;
		while(a[index].name !=" ")
		{
			if(a[index].name[0]==n[0])
				ind = index;
			if(index==26)
				index=0;
			else
				index++;

		}

		if(a[ind].name[0]==n[0] && a[ind].chain==-1)
			a[ind].chain=index;
		a[index].name=n;
		a[index].attribute=attr;
	}



}

void symbol_table::insert_replacement(string n, string attr, int index)
{
	int ind,num,num1;
	string sval,val;
		if(a[index].name==" ")
		{
			cout << index << endl;
			a[index].name=n;
			a[index].attribute=attr;
		}

		else
		{
			ind = index;

			while(a[index].name !=" ")
			{
				val=a[index].name;
				sval = a[index].attribute;
				num=a[index].name[0];
				num1=n[0];
				if(num!=a[index].key )
				{
					if((num1==a[index].key))
					{
						a[index].name=n;
						a[index].attribute=attr;
						insert_replacement(val, sval, hash(val));
						break;
					}
					else
					{
						if(a[index].name[0]==n[0])
							ind = index;
						if(index==26)
							index=0;
						else
							index++;
					}
				}

				else
				{
//					if(a[index].name[0]==n[0])
//						ind = index;
					if(index==26)
						index=0;
					else
						index++;
				}



			}


			if(a[index].name ==" ")
			{
				if(a[ind].name[0]==n[0])
				{
					a[ind].chain=index;
				}
				a[index].name=n;
				a[index].attribute=attr;
			}


		}

}

void symbol_table::find(string k, int index)
{

	if(a[index].name==" ")
	{
		cout << "It is empty" << endl;
		cout << "This name does not exist" << endl;
	}

	else
	{

		while(a[index].name!=" " && a[index].chain!=-1 && a[index].name!=k )
		{

			index = a[index].chain;
		}

		if(a[index].name==k)
		{
			cout << "\nThe name exist" << endl;
			cout << "Name: " << a[index].name << " Attribute: " << a[index].attribute << " Chain: "<< a[index].chain <<endl;
		}
		else
			cout << "This name does not exist" << endl;

	}

}

void symbol_table::remove(string k, int index)
{
	int ind,prevind=-1;
	if(a[index].name==" ")
	{
		cout << "This name does not exist" << endl;
	}

	else
	{
		while(index!=26)
		{
			if(a[index].name==k)
			{

				while(a[index].name!=" " && a[index].chain!=-1)
				{
					ind = a[index].chain;
					a[index].name=a[ind].name;
					a[index].attribute=a[ind].attribute;
					prevind = index;
					index=ind;
				}

				if(a[index].name==" " && a[index].chain!=-1)
					a[index].chain=-1;
				else if(a[index].name!=" " && a[index].chain==-1)
				{
					a[index].name=" ";
					a[index].attribute=" ";
					if(prevind!=-1)
						a[prevind].chain=-1;

				}

				break;
			}

			else if(a[index].chain==-1)
			{
				cout << "The name does not exist" << endl;
				break;
			}
			else
			{
				prevind = index;
				index = a[index].chain;
			}



		}
	}

}

void symbol_table::display()
{
	cout << "Name	Attribute   Chain" << endl;
	int i=0;
	while(i!=26)
	{
		if(a[i].name!=" ")
		{
			cout <<  a[i].name << "	  " << a[i].attribute << "	  " << a[i].chain <<endl;
		}
		i++;

	}

}
int main() {

	symbol_table st;
	int choice,lp,index;
	string n,attr;
	char y;
	int j,num=0;
	do
	{
		cout << "1. Insert\n2. Find\n3. Delete\n4. Display" << endl;
		cin >> choice;

		switch(choice)
		{
		case 1:
			cout << "1. Without replacement\n2. With replacement" << endl;
			cin>>lp;
			cout << "How many entries you want to make" << endl;
			cin >> j;
			while(num!=j)
			{
				cout << "Enter the name and the attribute " << endl;
				cin >> n>>attr;
				index=st.hash(n);
				if(lp==1)
					st.insert_noreplacement(n, attr, index);
				else
					st.insert_replacement(n, attr, index);
				num++;
			}

			break;

		case 2:
			cout << "Enter the name to be search" << endl;
			cin >> n;
			index=st.hash(n);
			st.find(n, index);
			break;

		case 3:
			cout << "Enter the name to be deleted" << endl;
			cin >> n;
			index=st.hash(n);
			st.remove(n, index);

			break;

		case 4:
			st.display();
			break;

		default:
			cout << "Invalid choice" << endl;
		}
		cout << "Do you want to repeat(y/n): " << endl;
		cin >> y;
	}while(y=='y');



	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
