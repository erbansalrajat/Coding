Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Link:-
https://www.interviewbit.com/problems/jump-game-array/
https://leetcode.com/problems/jump-game/

CODE:-
//LEETCODE
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int reachable=0;
        for(int i=0;i<nums.size();i++)
        {
            if(reachable<i)
                return false;
            reachable=max(reachable,i+nums[i]);
        }
        return true;
    }
};

//INTERVIEWBIT
int Solution::canJump(vector<int> &A) 
{
    int reachable=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        if(i<n-1)
        reachable=max(reachable,i+A[i]);
    }
}
