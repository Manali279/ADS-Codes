//============================================================================
// Name        : Assign3.cpp
// Author      : 21411
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include<stdlib.h>
using namespace std;
class TBT;
class node
{
	node *lc,*rc;
	int data;
	bool rbit,lbit;
public:
	node()
{
		lc=NULL;
		rc=NULL;
		rbit=lbit=0;
}
	node(int d)
	{
		lc=NULL;
		rc=NULL;
		rbit=lbit=0;
		data=d;
	}
	friend class TBT;
};

class TBT
{
	node *root;
public:
	TBT()
{
		root=new node(9999);
		root->lc=root;
		root->rbit=1;
		root->lbit=0;
		root->rc=root;
}


	void create()
	{

		int n;
		int ch;
		if(root->lc==root&&root->rc==root)
		{
			do{
			int info;
			cout<<"\nEnter data: ";
			cin>>info;
		this->insert(info);
			cout<<"Do you want to add another data(1 for yes and 0 for no)="<<endl;
			cin>>ch;
		}while(ch==1);
		}
		else
		{
			cout<<"\nTree is Already created.\n";
		}
	}

	void insert(int data)
	{

		if(root->lc==root&&root->rc==root)
		{
			node *p=new node(data);
			p->lc=root->lc;
			p->lbit=root->lbit;
			p->rbit=0;
			p->rc=root->rc;
			root->lc=p;
			root->lbit=1;
			cout<<"\nInserted at start "<<data;
			cout<<endl;
			return;
		}
		node *cur=new node;
		cur=root->lc;
		while(1)
		{
			if(cur->data>data)
						{
							node *p=new node(data);
							if(cur->lbit==0)
							{
								p->lc=cur->lc;
								p->lbit=cur->lbit;
								p->rbit=0;
								p->rc=cur;
								cur->lbit=1;
								cur->lc=p;
								cout<<"\nInserted left "<<data;
								cout<<endl;
								return;
							}
							else
								cur=cur->lc;
						}
			if(cur->data<data)
			{
				node *p=new node(data);
				if(cur->rbit==0)
				{
					p->rc=cur->rc;
					p->rbit=cur->rbit;
					p->lbit=0;
					p->lc=cur;
					cur->rbit=1;
					cur->rc=p;
					cout<<"\nInserted right "<<data;
					cout<<endl;
					return;
				}
				else
					cur=cur->rc;
			}

		}

	}
	void inorder()
				{
					node *t=root;
					while(t->lbit)
					t=t->lc;
					while(t!=root)
					{
						cout<<t->data<<" ";
						if(t->rbit)
						{
							t=t->rc;
							while(t->lbit)
								t=t->lc;
						}
						else
							t=t->rc;
					}
				}
	void inorder_traversal()
		{
			node *c=root->lc;
			while(c->lbit==1)
				c=c->lc;
			while(c!=root)
			{
				cout<<" "<<c->data;
				c=inorder_suc(c);
			}
		}
		node* inorder_suc(node *c)
		{
			if(c->rbit==0)
				return c->rc;
			else
				c=c->rc;
			while(c->lbit==1)
			{
				c=c->lc;
			}
			return c;
		}
 node* inSucc(node* ptr)
		{
		    if (ptr->rbit == 1)
		        return ptr->rc;

		    ptr = ptr->rc;
		    while (ptr->rc)
		        ptr = ptr->lc;

		    return ptr;
		}
 node* inPred(node* ptr)
 {
     if (ptr->lbit == 1)
         return ptr->rc;

     ptr = ptr->lc;
     while (ptr->rbit)
         ;
     ptr = ptr->rc;
     return ptr;
 }
node* caseA(node* root, node* par, node* ptr)
		{
		    if (par == NULL)
		    	root=NULL;
		    else if (ptr == par->lc) {
		        par->lbit = 1;
		        par->lc = ptr->lc;
		    }
		    else {
		        par->rbit =1;
		        par->rc = ptr->rc;
		    }
		    free(ptr);
		    return root;
		}
		node* caseB(node* root, node* par, node* ptr)
		{
		node* child;
		    if (ptr->lbit == 0)
		        child = ptr->lc;
		    else
		        child = ptr->rc;
		    if (par == NULL)
		        root = child;
		    else if (ptr == par->lc)
		        par->lc = child;
		    else
		        par->rc = child;
		    node* s = inSucc(ptr);
		    node* p = inPred(ptr);
		    if (ptr->lbit == 0)
		        p->rc = s;
		    else {
		        if (ptr->rbit ==0)
		            s->lc = p;
		    }

		    free(ptr);
		    return root;
		}
	node* caseC(node* root,node* par,
		                   node* ptr)
		{
		    node* parsucc = ptr;
		    node* succ = ptr->rc;
		    while (succ->lc != NULL) {
		        parsucc = succ;
		        succ = succ->lc;
		    }

		    ptr->data = succ->data;

		    if (succ->lbit == 1 && succ->rbit == 1)
		        root = caseA(root, parsucc, succ);
		    else
		        root = caseB(root, parsucc, succ);

		    return root;
		}
 node* delThreadedBST( node* root, int dkey)
		{
		   node *par = NULL, *ptr = root;
		    int found = 0;
		    while (ptr != NULL) {
		        if (dkey == ptr->data) {
		            found = 1;
		            break;
		        }
		        par = ptr;
		        if (dkey < ptr->data) {
		            if (ptr->lbit == 0)
		                ptr = ptr->lc;
		            else
		                break;
		        }
		        else {
		            if (ptr->rbit == 0)
		                ptr = ptr->rc;
		            else
		                break;
		        }
		    }

		    if (found == 0)
		   cout<<"Key not present in tree"<<endl;

		    // Two Children
		    else if (ptr->lbit == 0 && ptr->rbit == 0)
		        root = caseC(root, par, ptr);

		    // Only Left Child
		    else if (ptr->lbit== 0)
		        root = caseB(root, par, ptr);

		    // Only Right Child
		    else if (ptr->rbit == 0)
		        root = caseB(root, par, ptr);

		    // No child
		    else
		        root = caseA(root, par, ptr);

		    return root;
		}
void calldelete()
{int k;
	cout<<"Enter data to be deleted=";
			cin>>k;
			delThreadedBST(root,k);

}
};

int main() {
	TBT t1;
	node* root=NULL;
	int value;
	int choice,d;
	int k;
	cout<<"Threaded Binary Tree Implementation"<<endl;
	do
	{
		cout<<"\n1.Create Tree\n2.Insert into tree\n3.Inorder traversal\n4.Intraverse\n5.Deletion\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			t1.create();
			break;
		case 2:
			cout<<"\nEnter data: ";
			cin>>value;
			t1.insert(value);
			break;
		case 3:
			cout<<"\nInorder traversal of TBT\n";
			t1.inorder_traversal();
			break;
		case 4:
			cout<<"ABC"<<endl;
			t1.inorder();
			break;
		case 5:
t1.calldelete();
			break;

		default:
			cout<<"\nWrong choice entered";
		}
		cout<<endl;
		cout<<"Do you want to perform more operation(1 for yes and 0 for no)="<<endl;
		cin>>d;

	}while(d==1);


	return 0;
}

