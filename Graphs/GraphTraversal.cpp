Normal Graph Traversal

#include<bits/stdc++.h>
using namespace std;

void printAdj(vector<vector<int> > adj)
{
	int n=adj.size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}

void printGraph(vector<vector<int> > &adj, int sv,vector<int> &visited)
{
	int n=adj.size();
	cout<<sv<<"  ->  ";
	visited[sv]=1;
	for(int i=0;i<n;i++)
	{
		if(i==sv)
		continue;
		else
		{
			if(visited[i]==1)
			continue;
			else
			printGraph(adj,i,visited);
		}
	}
}

int main()
{
	int n;
	int e;
	cout<<"Enter No of Vertices or Nodes = ";
	cin>>n;
	cout<<"Enter No of Edges = ";
	cin>>e;
	vector<vector<int> > adj(n,vector<int> (n,0)); // used this way to intitalize matrix with zeros instead of applying 2 for loops like below
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			adj[i].push_back(0);
//			cout<
//		}
//	}
	printAdj(adj); 
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		adj[f][s]=1;
		adj[s][f]=1;
	}
	vector<int> visited;
	for(int i=0;i<n;i++)
	visited.push_back(0);
	printGraph(adj,0,visited);
}
