Problem Description
You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.
Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.
NOTE: if B > N, return an empty array.

Input Format
First argument is an integer array A
Second argument is an integer B.

Output Format
Return an integer array.

Example Input
Input 1:
 A = [1, 2, 1, 3, 4, 3]
 B = 3
 
Input 2:
 A = [1, 1, 2, 2]
 B = 1

Example Output
Output 1:
 [2, 3, 3, 2]
 
Output 2:
 [1, 1, 1, 1]

Example Explanation
Explanation 1:
 A=[1, 2, 1, 3, 4, 3] and B = 3
 All windows of size B are
 [1, 2, 1]
 [2, 1, 3]
 [1, 3, 4]
 [3, 4, 3]
 So, we return an array [2, 3, 3, 2].
 
Explanation 2:
 Window size is 1, so the output array is [1, 1, 1, 1].

LINK :- https://www.interviewbit.com/problems/distinct-numbers-in-window/

CODE:-

vector<int> Solution::dNums(vector<int> &A, int B) 
{
    unordered_map<int,int> hm;
    vector<int> res;
    int dis_count=0;
    int size=B;
    if(B==1)
    {
        for(int i =0 ; i<A.size();i++)
        res.push_back(1);
        return res;
    }
    if(B>A.size())
    {
        return res;
    }
    for(int i=0;i<B;i++)
    {
        if(hm[A[i]]==0)
        {
            dis_count++;
        }
        hm[A[i]]+=1;
    }
    res.push_back(dis_count);
    for(int i=B;i<A.size();i++)
    {
        if(hm[A[i-B]]==1)
        dis_count--;
        hm[A[i-B]]=hm[A[i-B]]-1;
        if (hm[A[i]] == 0) 
        { 
            dis_count++; 
        } 
        hm[A[i]] += 1; 
        res.push_back(dis_count);
    }
 return res;   
}
