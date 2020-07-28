#include<iostream>
using namespace std;
class edge
{
	int u,v,w;
	edge()
	{

	}
	edge(int a,int b,int weight)
	{
		u=a;
		v=b;
		w=weight;
	}
	friend class edgelist;
	friend class phonegraph;
};
class edgelist
{
	edge data[10];
	int n;
public:
	edgelist()
{
		n=0;
}
	void sort()
	{
		edge temp;
			for(int i=1;i<n;i++)
				for(int j=0;j<n-1;j++)
					if(data[j].w>data[j+1].w)
					{
						temp=data[j];
						data[j]=data[j+1];
						data[j+1]=temp;
					}
	}
	void print()
	{
		int cost=0;
			for(int i=0;i<n;i++)
			{
				cout<<"\n"<<i+1<<" "<<data[i].u<<"->"<<data[i].v<<" = "<<data[i].w;
				cost=cost+data[i].w;
			}
			cout<<"\nMinimum cost of Telephone Graph = "<<cost;
	}
	friend class phonegraph;
};
class phonegraph
{
	int data[10][10];
	int n;
public:
	phonegraph(int num)
{
		n=num;
}
	void input()
	{
		cout<<"Enter the adjacency matrix="<<endl;
		for(int i=0;i<n;i++)
			{
				for(int j=0;j<n; j++)
					cin>>data[i][j];
			}
	}
	void disp()
	{
		cout<<"\nAdjacency matrix= \n";
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					cout<<data[i][j]<<" ";
				}
				cout<<endl;
			}
	}
	int vermin(int cost[],bool visited[])
	{
		int min=9999,min_index;
			for(int i=0;i<n;i++)
			{
				if(visited[i]==0 && cost[i]<min)
				{
					min=cost[i];
					min_index=i;
				}
			}
			return min_index;

	}
	int prims()
	{
		bool visited[10];
			int parents[10];
			int cost[10];
			for(int i=0;i<n;i++)
			{
				cost[i]=9999;
				visited[i]=0;
			}

			cost[0]=0;
			parents[0]=-1;

			for(int i=0;i<n-1;i++)
			{
				int k=vermin(cost,visited);
				visited[k]=1;

				for(int j=0;j<n;j++)
				{
					if(data[k][j] && visited[j]==0 && data[k][j] < cost[j])
					{
						parents[j]=k;
						cost[j]=data[k][j];
					}
				}
			}
			cout<<"Minimum Cost Telephone Map:\n";
			for(int i=1;i<n;i++)
			{
				cout<<i<<" -- "<<parents[i]<<" = "<<cost[i]<<endl;
			}
			int mincost=0;
			for (int i = 1; i < n; i++)
				mincost+=cost[i];
			cout<<"Minimum cost="<<mincost;
			cout<<endl;
	}
};
int main()
{
	edgelist span;
	int n,ch,d;
cout<<"Prims and Kruskal Algorithm Implementation"<<endl;
cout<<"Enter no. of offices=";
cin>>n;
phonegraph p(n);
do
{
cout<<"1)Input adjacency matrix\n2)Display adjacency matrix\n3)Prims algorithm"<<endl;
cout<<"Enter your choice=";
cin>>ch;
cout<<endl;
switch(ch)
{
case 1:
	p.input();
	break;
case 2:
	p.disp();
	break;
case 3:
	p.prims();
	break;
default:
	cout<<"Wrong choice entered!\n";
}
cout<<"Do you want to perform another operation(1 for yes and 0 for no)=";
cin>>d;
}while(d==1);

return 0;
}
