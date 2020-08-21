SEARCHING A NUMBER

Given an array of N elements and a integer K. Your task is to return the position of first occurence of K in the given array.
Note: Position of first element is considered as 1.

Input:
First line of input contains T denoting the number of testcases. For each testcase there will be two space separated integer N and K denoting the size of array and the value of K respectively. The next line contains the N space separated integers denoting the elements of array.

Output:
For each test case, print the index of first occurrence of given number K. Print -1 if the number is not found in array.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= K <= 106
1 <= A[i] <= 106

Example:
Input :
2 
5 16
9 7 2 16 4
7 98
1 22 57 47 34 18 66

Output : 
4
-1

LINK:- https://practice.geeksforgeeks.org/problems/searching-a-number/0
 
CODE:- 
#include<bits/stdc++.h>
using namespace std;
int linear_search(vector<int> &v , int k )
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==k)
        {
            return i+1;
        }
    }
    return -1;
}
int main()
 {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n;
	    int k;
	    cin>>n>>k;
	    vector<int> v(n,0);
	    for(int j=0;j<n;j++)
	    {
	        cin>>v[j];
	    }
	    cout<<linear_search(v,k)<<endl;
	}
	
	return 0;
}
