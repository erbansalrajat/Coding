Code : BFS Traversal
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.

Note : 
1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000

Sample Input 1:
4 4
0 1
0 3
1 2
2 3

Sample Output 1:
0 1 3 2

CODE:-

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printBFS(vector<vector<int> > &adj, vector<int> &visited, int sv)
{
    queue<int> current;
    current.push(sv);
    visited[sv]=1;
    while(current.size()!=0)
    {
        cout<<current.front()<<" ";
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
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int> > adj(V,vector<int>(V,0));
    vector<int> visited(V,0);
    for(int i=0;i<E;i++)
    {
        int first;
        int second;
        cin>>first>>second;
        adj[first][second]=1;
        adj[second][first]=1;
    }
    for(int i=0;i<visited.size();i++)
    {
     if(visited[i]==0)
     {
         printBFS(adj,visited,i);
     }
    }
  return 0;
}
