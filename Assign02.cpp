//============================================================================
// Name        : Assign2-bst.cpp
// Author      :21411
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stack>
using namespace std;

class node
{
 public:
 char key[20];
 char mean[20];
node *left;
node *right;

node()
{
	left=right=NULL;
}

friend class dictionary;
};

class dictionary
{
public:
 node *root;

 dictionary()
 {
	 root=NULL;
 }

 void create()
 {
  class node *temp;
  int ch;

  do
  {
   temp = new node;
   cout<<"\nEnter Keyword:";
   cin>>temp->key;
   cout<<"\nEnter Meaning:";
   cin>>temp->mean;

   temp->left = NULL;
   temp->right = NULL;

   if(root == NULL)
   {
    root = temp;
   }
   else
   {
    insert(root,temp);
   }
   cout<<"\nDo u want to add more keywords (1 for yes and 0 for no):";
   cin>>ch;
  }
  while(ch == 1);

 }

 void insert(node * root,node *temp)
 {
  if(strcmp (temp->key,root->key) < 0 )
  {
   if(root->left == NULL)
    root->left = temp;
   else
    insert(root->left,temp);
  }
  else if(strcmp (temp->key,root->key) > 0)
  { if(root->right == NULL)
    root->right = temp;
   else
    insert(root->right,temp);
  }
  else
	  cout<<"Duplicate entries not allowed!"<<endl;
}

 void descending(node *root)
  {
   if( root != NULL)
   {
    descending(root->right);
    cout<<"\n Key Word :"<<root->key;
    cout<<"\t Meaning :"<<root->mean;
descending(root->left);
   }
  }

 int search(node *root,char k[20])
 {
	 int count;
  while(root != NULL)
  {
	  count++;
   if(strcmp (k,root->key) == 0)
   {
	   cout<<"\nNo. of comparisons="<<count<<endl;
    return 1;
   }
   if(strcmp (k, root->key) < 0)
    root = root->left;
   if(strcmp (k, root->key) > 0)
    root = root->right;
  }
 return -1;
 }

 int update(node *root,char k[20])
 {
  while(root != NULL)
  {
   if(strcmp (k,root->key) == 0)
   {
    cout<<"\nEnter New Meaning of Keyword"<<root->key;
    cin>>root->mean;
    return 1;
   }
   if(strcmp (k, root->key) < 0)
    root = root->left;
   if(strcmp (k, root->key) > 0)
    root = root->right;
  }
  return -1;
 }

 node* minValueNode(node* root)
 {
 node* current =root;
 while(current &&current->left!=NULL)
 current=current->left;
 return current;
 }

 node* deleteNode(node* root,char key[20])
 {
 if(root==NULL)
 return root;
 if(strcmp (key, root->key) < 0)
 root->left=deleteNode(root->left,key);
 else if(strcmp (key, root->key) > 0)
 root->right=deleteNode(root->right,key);
 else
 {
 if(root->left==NULL)
 {
 node* temp=root->right;
 free(root);
 return temp;
 }
 else if(root->right==NULL)
 {
 node* temp=root->left;
 free(root);
 return temp;
 }
 else
	 free(root);
node* temp=minValueNode(root->right);
strcpy(root->key,temp->key);
 root->right=deleteNode(root->right,temp->key);
 }
 return root;
 }

void deleten()
		{
	char k[20];
	 cout<<"\nEnter Keyword which u want to delete:";
	  cin>>k;
	  deleteNode(root,k);
	  cout<<"The keyword "<<k<<" is deleted"<<endl;
		}

void operator =(dictionary &b1)
		{
			root=copy_tree(b1.root);
		}

	node* copy_tree(node *temp)
		{if(temp==NULL)
			return NULL;
		else
		{
			node *t2;
			t2=new node;
			strcpy(t2->key,temp->key);
			strcpy(t2->mean,temp->mean);
			t2->left=copy_tree(temp->left);
			t2->right=copy_tree(temp->right);
			return t2;
		}
		}

	int maxheight(node* node)
	{
		int lh=0;
		int rh=0;
	    if (node == NULL)
	        return 0;
	    else
	    {
	        lh = maxheight(node->left);
	        rh = maxheight(node->right);
	        if (lh >rh)
	     return (lh+1);
	        else
return (rh+1);

	    }
	}

	 void dispinorder(node *root)
	 {
	  if( root != NULL)
	  {
	   dispinorder(root->left);
	   cout<<"\n Key Word :"<<root->key;
	   cout<<"\t Meaning :"<<root->mean;
	   dispinorder(root->right);
	  }
	 }
	 void disppreorder(node *root)
	  {
	   if( root != NULL)
	   {
		   cout<<"\n Key Word :"<<root->key;
		      cout<<"\t Meaning :"<<root->mean;
	    disppreorder(root->left);
	    disppreorder(root->right);
	   }
	  }

	 void disppostorder(node *root)
	  {
	   if( root != NULL)
	   {
	    disppostorder(root->left);
	    disppostorder(root->right);
	    cout<<"\n Key Word :"<<root->key;
	       cout<<"\t Meaning :"<<root->mean;
	   }
	  }

	 void inordernr(node* root)//non-recursive inorder
	 	{
	 		stack<node*> s;
	 		if(root != NULL){
	 			while(1){
	 				if(root != NULL){
	 					s.push(root);
	 					root = root->left;
	 				}
	 				else if(!s.empty()){
	 					root = s.top();
	 					s.pop();
	 					 cout<<"\n Key Word :"<<root->key;
	 					       cout<<"\t Meaning :"<<root->mean;
	 					root = root->right;
	 				}
	 				else{
	 					break;
	 				}
	 			}
	 		}
	 	}

	 void nrincall()
	 			{
	 				cout<<"\nNonRecursive Inorder=";
	 					inordernr(root);
	 					cout<<endl;

	 			}

		};

int main()
{
 int ch,x,b;
 char k[20];
 dictionary d,d1;
 d.root = NULL;
 d1.root=NULL;
cout<<"Binary Search Tree Implementation"<<endl;
 do
 {
	 cout<<"Enter your choice=";
  cout<<"\n1.Create BST\n2.Display Inorder\n3.Search in BST\n4.Update keyword in BST\n5.Delete a keyword in BST\n6.Display non-recursive inorder\n7.Display Postorder\n8.Descending tree\n9.Copying using assignment operator\n10.Maximum Height of BST";
  cin>>ch;

  switch(ch)
  {
case 1: d.create();
  break;
case 2:
	if(d.root == NULL)
  cout<<"\nNo Keyword";
	else
  d.dispinorder(d.root);
  break;
case 3: if(d.root == NULL)
  cout<<"\nDictionary is Empty.";
  else
 {
cout<<"\nEnter Keyword want to search:";
cin>>k;
if( d.search(d.root,k) == 1)
  cout<<"\nKeyword Found";
  else
  cout<<"\nKeyword Not Found";
 }
  break;
case 4:
  if(d.root == NULL)
  cout<<"\nDictionary is Empty.";
  else
  {
  cout<<"\nEnter Keyword which meaning  want to update:";
  cin>>k;
  if(d.update(d.root,k) == 1)
  cout<<"\nMeaning Updated";
  else
  cout<<"\nMeaning Not Found";
  }
  break;
case 5:
  if(d.root == NULL)
  cout<<"\nDictionary is Empty. ";
  else
  {
d.deleten();

  }
  break;
case 6:
	if(d.root == NULL)
	  cout<<"\nNo Keyword";
		else
d.nrincall();
	  break;
case 7:
	if(d.root == NULL)
	  cout<<"\nNo Keyword";
		else
	  d.disppostorder(d.root);
	  break;
case 8:
	if(d.root == NULL)
		  cout<<"\nNo Keyword";
			else
		  d.descending(d.root);
		  break;
case 9:
	cout<<"The new tree="<<endl;
	d1=d;
	d1.dispinorder(d1.root);
	break;
case 10:
b=d.maxheight(d.root);
cout<<"Maximum height of tree="<<b<<endl;
	break;
default:
	cout<<"Wrong choice entered!"<<endl;
  }
  cout<<"\nDo you want to perform another operation(1 for yes and 0 for no)="<<endl;
  cin>>x;
 }
 while(x==1);
 return 0;

}
