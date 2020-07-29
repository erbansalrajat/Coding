The task is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.

Input: 
First line consists of T test cases. First line of every test case consists of N and M, denoting the number of rows and number of column respectively.

Output: 
Single line output i.e count of all the possible paths from top left to bottom right of a mXn matrix.

Constraints:
1<=T<=100
1<=N<=100
1<=M<=100

Example:
Input:
1
3 3
Output:
6
//I have ignored large cases.

CODE:-
#include<bits/stdc++.h>
using namespace std;
int totalpaths(int n, int m)
{
	int dp[n][m];
	dp[0][0]=0;
	for(int j=1;j<m;j++)
	{
		dp[0][j]=1;
	}
	for(int j=1;j<n;j++)
	{
		dp[j][0]=1;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<dp[i][j];
		cout<<endl;
	}
	return dp[n-1][n-1];
}
int main()
{
	int n,m,paths;;
	cout<<"Enter the map dimensions"<<endl<<" Rows = ";
	cin>>n;
	cout<<"Columns = ";
	cin>>m;
	paths=totalpaths(n,m);
	cout<<"Paths = "<<paths;
	return 0;
}
