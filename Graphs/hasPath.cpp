Code : Has Path

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.

Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)

Output Format :
true or false

Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :
true

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3

Sample Output 2 :
false

CODE:-

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool hasPath(vector<vector<int> > &adj,vector<int> &visited,int sv,int ev)
{
    if(sv==ev || adj[sv][ev]==1)
        return true;
    for(int i=0;i<adj.size();i++)
    {
        if( i==sv )
            continue;
        else if(adj[sv][i]==1 && visited[i]==0)
        {
            visited[i]=1;
            if(hasPath(adj,visited,i,ev)==true)
            {
                return true;
            }
        }
    }
    return false;
}
using namespace std;
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
    int start, end;
    cin>>start>>end;
    if(hasPath(adj,visited,start,end)==true)
    {
        cout<<"true";
    }
    else
        cout<<"false";
        return 0;
}
