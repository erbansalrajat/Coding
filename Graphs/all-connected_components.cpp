Code : All connected components

Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :
Different components in new line

Constraints :
2 <= V <= 1000
1 <= E <= 1000

Sample Input 1:
4 2
0 1
2 3

Sample Output 1:
0 1 
2 3 

Sample Input 2:
4 3
0 1
1 3 
0 3

Sample Output 2:
0 1 3 
2

CODE:- 

include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print_connected(vector<vector<int> > &adj, vector<int> &visited, int sv)
{
    queue<int> current;
    vector<int> print;
    current.push(sv);
    visited[sv]=1;
    while(current.size()!=0)
    {
        print.push_back(current.front());
        sv=current.front();
        current.pop();
         for(int i=0;i<adj.size();i++)
        {
            if(i==sv || visited[i]==1)
                continue;
            else if( adj[sv][i] ==1 )
            {
                current.push(i);
                visited[i]=1;
            }
        }
    }
    sort(print.begin(),print.end());
    for(int i=0;i<print.size();i++)
    {
        cout<<print[i]<<" ";
    }
}
int main()
{
  int V, E;
  cin >> V >> E;
     vector<vector<int> > adj(V, vector<int>(V,0));
    vector<int> visited(V,0);
    for(int i=0;i<E;i++)
    {
        int first,second;
        cin>>first>>second;
        adj[first][second]=1;
        adj[second][first]=1;
    }
  for(int i=0;i<visited.size();i++)
  {
     if(visited[i]==0)
     {
         print_connected(adj,visited,i);
         cout<<endl;
     }
  }
  return 0;
}
