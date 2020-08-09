BFS Traversal of a graph using adjacency matrix 
Input is given by user

CODE:-
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
void printBFS(vector<vector<int> > &adj, int sv,vector<int> &visited)
{
	int currentvertex=0;
	int n=adj.size();
	queue<int> left;
	visited[sv]=1;
	left.push(sv);
	while(left.size()!=0)
	{
		cout<<left.front()<<" -> ";
		currentvertex=left.front();
		left.pop();
		for(int i=0;i<n;i++)
		{
			if(i==sv)
			continue;
			if(visited[i]==1)
			continue;
			if(adj[currentvertex][i]==1)
			{
				left.push(i);
				visited[i]=1;
			}	
		}	
	}
	cout<<" END ";	
}
int main()
{
	int n;
	int e;
	cout<<"Enter No of Vertices or Nodes = ";
	cin>>n;
	cout<<"Enter No of Edges = ";
	cin>>e;
	vector<vector<int> > adj(n,vector<int> (n,0));
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			adj[i].push_back(0);
//			cout<
//		}
//	}
//  cout<<" Initial Adjancency Matrix "<<endl;
//  printAdj(adj); 
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		adj[f][s]=1;
		adj[s][f]=1;
	}
	printAdj(adj);
	vector<int> visited;
	for(int i=0;i<n;i++)
	visited.push_back(0);
	printBFS(adj,0,visited);
}
