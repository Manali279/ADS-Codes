//============================================================================
// Name        : Assign4.cpp
// Author      : 21411
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<queue>
#include<string>
using namespace std;

class node
{

	string dest;
	int time;
	node *next;
public:
	node()
{
		dest="";
		time=0;
		next=NULL;
}
	node(string s,int c)
	{
		this->dest=s;
		this->time=c;
		this->next=NULL;
	}
	friend class graph;
};


class graph
{
	int ver,edge,n,e;
	node *g[20];
	string city[20];

public:
	graph()
{
		ver=edge=n=0;
		for(int i=0;i<20;i++)
			g[i]=NULL,city[i]="";
}
	void create()
	{
		int c=0;
string source,destination;
int t=0;
		cout<<"Enter the no. of cities in graph=";
		cin>>n;
		cout<<endl;
		for(int i=0;i<n;i++)
		{
			string s;
			cout<<"Enter city name=";
			cin>>s;
			cout<<endl;
			city[ver++]=s;
		}
		cout<<"Enter no. of edges=";
		cin>>c;
		cout<<endl;
		e=((n*(n-1))/2);
		if(c<=e)
		{
		for(int i=0;i<c;i++)
		{
			cout<<"Enter source city=";
			cin>>source;
			cout<<endl;
			cout<<"Enter destination city=";
						cin>>destination;
						cout<<endl;
						cout<<"Enter time required for flight=";
									cin>>t;
cout<<endl;
			insert(pass(source),destination,t);

		}
		}
		else
			cout<<"Graph not possible!"<<endl;
	}

	int pass(string s)
	{
		for(int i=0;i<ver;i++)
			if(city[i]==s)
				return i;
		return 0;
	}
	void insert(int i,string d,int cost)
	{
		node *des=new node(d,cost);
		if(g[i]==NULL)
		{
			g[i]=des;
		}
		else
		{
			node *t=g[i];
			while(t->next!=NULL)
			{
				t=t->next;
			}
			t->next=des;
		}
	}
	void disp()
		{
		cout<<"The adjacency list for graph="<<endl;
			for(int i=0;i<=ver;i++)
			{
				cout<<city[i]<<":";
				node *t=g[i];
				while(t->next!=NULL)
				{
					cout<<"->"<<t->dest<<"("<<t->time<<")";
					t=t->next;
				}
				cout<<"->"<<t->dest<<"("<<t->time<<")";

				cout<<endl;
			}
		}
	void bfs(string c)
	{
	bool visit[ver];
		int i;
		for(i=0;i<ver;i++)
		{
			visit[i]=0;
		}
		queue<string>Q;
		Q.push(c);
		visit[0]=1;

		int v1=0;
		int v2=0;
		string temp=" ";
		node *a=NULL;
		while(!Q.empty())
		{
			temp=Q.front();
			Q.pop();
			cout<<temp<<" ";
			v1=pass(temp);

			if(v1!=(-1))
			{
				a=g[v1];
				while(a)
				{
					v2=pass(a->dest);
					if(visit[v2]==0)
					{
						Q.push(a->dest);
						visit[v2]=1;
					}
					a=a->next;
				}
			}
		}
}
	int outdegree(string cit)
	{
		int i,count=0;
		for(i=0;i<ver;i++)
		{
			if(city[i]==cit)
			{
				node *t=g[i];
				while(t)
				{
					count++;
					t=t->next;
				}

			}
		}
		return count;
	}
	bool check_V(node *cursor,string city)
	{
		while(cursor)
		{
			if(cursor->dest==city)
				return true;
			cursor=cursor->next;
		}
		return false;
	}
	int indegree(string cit)
	{
		int cnt=0;
		int i;
		for(i=0;i<ver;i++)
		{
			if((check_V(g[i],cit)&&(city[i]!=cit)))
			{
				cnt++;
			}
		}
		return cnt;

	}
};
int main()
{
	int ch,d;
	string c,cit,a;
	graph g;
	cout<<"Graph Implementation"<<endl;
	cout<<endl;
	do
	{
	cout<<"1)Create a graph\n2)Display the graph\n3)BFS traversal\n4)Outdegree of city\n5)Indegree of city"<<endl;
	cout<<"Enter your choice=";
	cin>>ch;
	switch(ch)
	{
	case 1:
		g.create();
		break;
	case 2:
		g.disp();
		break;
	case 3:
		cout<<"BFS Traversal="<<endl;
		cout<<"Enter the city from which you have to start the BFS traversal=";
		cin>>cit;
		g.bfs(cit);
		break;
	case 4:
		cout<<"Enter the city whose outdegree you have to calculate="<<endl;
		cin>>c;
		cout<<"Outdegree=";
		cout<<g.outdegree(c);
		break;
	case 5:
		cout<<"Enter the city whose indegree you have to calculate="<<endl;
				cin>>a;
				cout<<"Indegree=";
			cout<<	g.indegree(a);
				break;

	default:
		cout<<"Wrong choice entered!"<<endl;
	}
	cout<<"Do you want to perform another operation(1 for yes and 0 for no)";
	cin>>d;
	cout<<endl;
	}while(d==1);

	return 0;
}

