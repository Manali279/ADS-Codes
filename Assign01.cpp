//============================================================================
// Name        : tree.cpp
// Author      : 21411
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
class node
{
	int data;
	node *left, *right;
public:
	node(int x)
{
		data=x;
		left=right=NULL;
}
	friend class tree;
};
class stackn
{
public:

	node *s[20];
	int i;
	int top;
	stackn()
	{
		for(i=0;i<20;i++)
		{
			s[i]=NULL;
			top=-1;
		}
	}


	int isfull()
	{
		if(top==19)
			return 1;
		else
			return 0;
	}
	int isempty()
	{
		if(top==-1)
		return 1;
		else
			return 0;
	}
	void push(node *p)
	{
		s[top++]=p;
	}

	node *pop()
	{
		return s[top--];
	}
};
class tree
{
	node *root;
public:
	tree()
	{
		root=NULL;
	}
	void create(int x)//creating tree
	{
		if(root==NULL)
		{
			root=new node(x);
		}
		else
		{
			cout<<"Tree is created"<<endl;
			root=insert(x,root);
		}
	}
	node *insert(int x,node *T)//insertion in tree
	{
		int ans;
		if(T==NULL)
		{
			T=new node(x);
			return T;
		}
		else
		{
			cout<<"Enter the value to left or right(1 for left and 0 for right)"<<endl;
			cin>>ans;
			if(ans==1)
			{
				T->left=insert(x,T->left);
			}
			else
				T->right=insert(x,T->right);
		}
		return T;
	}
	int inorder(node *T)//recursive inorder
	{
		if(T==NULL)
			return 0;
		else
		{
			inorder( T->left);
			cout<<T->data;
			inorder( T->right);
}
	}
	void recincall()
	{
		cout<<"\nRecursive Inorder=";
			inorder(root);
			cout<<endl;

	}
	int preorder(node *T)//recursive preorder
		{
			if(T==NULL)
				return 0;
			else
			{
				cout<<T->data;
				preorder( T->left);
preorder( T->right);
}
		}

	void recprecall()
		{
			cout<<"\nRecursive Preorder=";
				preorder(root);
				cout<<endl;

		}
	int postorder(node *T)//recursive postorder
			{
				if(T==NULL)
					return 0;
				else
				{
		postorder( T->left);
	postorder( T->right);
	cout<<T->data;
				}
			}
	void recpostcall()
			{
				cout<<"\nRecursive Postorder=";
					postorder(root);
					cout<<endl;

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
					cout<<root->data;
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
	void preordernr(node* root)//non-recursive prorder
	{
		stack<node*> s;
		if(root != NULL){
			while(1){
				if(root != NULL){
					s.push(root);
					cout<<root->data;
					root = root->left;
				}
				else if(!s.empty()){
					root = s.top();
					s.pop();
					root = root->right;
				}
				else{
					break;
				}
			}
		}
	}
	void nrprecall()
			{
				cout<<"\nNonRecursive preorder=";
					preordernr(root);
					cout<<endl;

			}
	void postordernr(node* root){
		stack<node*> s1, s2;
		node* p = root;
		s1.push(p);

		while(!s1.empty()){
			p = s1.top();
			s1.pop();
			s2.push(p);

			if(p->left)
				s1.push(p->left);
			if(p->right)
				s1.push(p->right);
		}

		while(!s2.empty()){
			p = s2.top();
			s2.pop();
			cout<<p->data<<"\t";
		}
	}
	void nrpostcall()
				{
					cout<<"\nNonRecursive postorder=";
						postordernr(root);
						cout<<endl;

				}

	int mi(node *T)//mirror in same tree
		{
			if(T==NULL)
				return 0;
			else
			{
			mi( T->right);
				cout<<T->data;
				mi( T->left);

			}
		}
	void nmcall()
	{
		cout<<"Mirror of given tree as a new tree="<<endl;
			inorder(mirrora(root));
			cout<<endl;
	}
node* mirrora(node *T)//mirror in different tree
{
if(T==NULL)
	return 0;
node *newNode=new node(T->data);
newNode->right=mirrora(T->left);
newNode->left=mirrora(T->right);
return newNode;
}
void omcall()
{
	cout<<"Mirror by making changes in the tree itself=";
			mi(root);
			cout<<endl;
}
void ilevel(node *T,int level)//nodes at particular level
	{
		if(T==NULL) return;
		if(level==0)  cout<< T->data<<" ";
		else {
			ilevel(T->left,level-1);
			ilevel(T->right,level-1);
		}
	}
void ilevelcall()
{
	int c;
	cout<<"Enter the level of node to be displayed="<<endl;
	cin>>c;
	ilevel(root,c);
	cout<<endl;
}

node* leaf(node* T)//leaf nodes
{
	if(T==NULL)
		return 0;
	 if(T->left==NULL&&T->right==NULL)
		cout<<T->data<<" "<<endl;
 leaf(T->left);
 leaf(T->right);
	return T;
}
void leafcall()
{
	cout<<"The leaf nodes are="<<endl;
		leaf(root);
		cout<<endl;

}
node* internal(node* T)//internal nodes
{
	if(T==NULL)
		return 0;
	 if(T->left!=NULL||T->right!=NULL)
		cout<<T->data<<" "<<endl;
 internal(T->left);
 internal(T->right);
	return T;
}
void internalcall()
{
	cout<<"The internal nodes are="<<endl;
			internal(root->left);
			internal(root->right);
			cout<<endl;
}
void check_rec(node *p,node *q)//checking whether equal or not
{


	if(p!=NULL && q!=NULL)
	{
		if(p->data==q->data)
		{
			if(p->left!=NULL&&q->left!=NULL)
			{
				check_rec(p->left,q->left);
				cout<<"Equal"<<endl;
}
		}
		else
		{
			cout<<"not equal"<<endl;
		}
	}
}
void check(tree &t3,tree &t4)//calling check
{
	check_rec(t3.root,t4.root);
}
void erase(node *T)//erasing tree
{
	if(T!=NULL)
	{
		erase(T->right);
		erase(T->left);
		free(T);
	}
}
void erasecall()//erase call
{
	erase(root);
	cout<<"First tree deleted"<<endl;
}
/*void operator =(tree &b1)
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
	t2->data=temp->data;
			t2->left=copy_tree(temp->left);
			t2->right=copy_tree(temp->right);
			return t2;
		}
		}*/


void dispcall()
{
	cout<<"Copying using + operator->"<<endl;
	inorder(root);
	cout<<endl;

}
void call()
{
	int c;
	cout<<"Enter the level of node to be displayed="<<endl;
	cin>>c;
	ilevel(root,c);
	cout<<endl;
	cout<<"Mirror of given tree as a new tree="<<endl;
	inorder(mirrora(root));
	cout<<endl;
	cout<<"The leaf nodes are="<<endl;
	leaf(root);
	cout<<"The internal nodes are="<<endl;
		internal(root->left);
		internal(root->right);
}
void disp(){
	cout<<"\nInorder=";
	inorder(root);
	cout<<endl;
	cout<<"Preorder=";
	preorder(root);
	cout<<endl;
	cout<<"Postorder=";
		postorder(root);
		cout<<endl;
		cout<<"Mirror by making changes in the tree itself=";
		mi(root);
		cout<<endl;
		cout<<"Non recursive inorder=";
		inordernr(root);
		cout<<endl;
		cout<<"Non recursive preorder=";
			preordernr(root);
			cout<<endl;
				cout<<"Non recursive postorder=";
						cout<<endl;
}
/*node* &operator=(tree t){
		root=copy(t.root);
		inorder(t.root);
	}
	node* copy(node *root){
		node *q=new node(q->data);
		if(root){
		q->data=root->data;
			q->left=copy(root->left);
			q->right=copy(root->right);
			return q;
		}
		return NULL;
	}*/

};

int main() {
	tree t,m,s;
int i;
int c,e;
int b,x;
int a[50],d[50];
cout<<"Tree implementation"<<endl;
cout<<"How many elements to be added to tree="<<endl;
cin>>b;

for(i=0;i<b;i++)
{
	cout<<"Enter the element="<<endl;
	cin>>a[i];
	t.create(a[i]);
}
do{
cout<<"Enter the operation you want to perform=\n1)Display inorder\n2)Display preorder\n3)Display Postorder\n4)Display non-recursive inorder\n5)Display non-recursive preorder\n6)Display non-recursive postorder"<<endl;
cout<<"7)Mirror of tree as a new tree\n8)Mirror of tree as tree itself\n9)Nodes at particular level\n10)Leaf nodes\n11)Internal nodes\n12)Delete tree"<<endl;
cin>>e;
switch(e)
{
case 1:
	t.recincall();
	break;
case 2:
	t.recprecall();
	break;
case 3:
	t.recpostcall();
	break;
case 4:
	t.nrincall();
	break;
case 5:
	t.nrprecall();
	break;
case 6:
	t.nrpostcall();
	break;
case 7:
	t.nmcall();
	break;
case 8:
	t.omcall();
	break;
case 9:
	t.ilevelcall();
	break;
case 10:
	t.leafcall();
	break;
case 11:
	t.internalcall();
	break;
case 12:
	t.erasecall();
	break;
default:
	cout<<"Wrong choice entered!"<<endl;
}
cout<<"Do you want to perform other operation=(1 for yes and 0 for no)="<<endl;
cin>>c;
}while(c==1);
cout<<"\nHow many elements to be added to second tree="<<endl;
cin>>x;

for(i=0;i<x;i++)
{
	cout<<"Enter the element="<<endl;
	cin>>d[i];
	m.create(d[i]);

}
cout<<"The result of whether both trees are equal or not="<<endl;
t.check(t,m);
s=t;
s.dispcall();
	return 0;
}

