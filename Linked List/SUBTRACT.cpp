Given a singly linked list, modify the value of first half nodes such that :

1st node’s new value = the last node’s value - first node’s current value
2nd node’s new value = the second last node’s value - 2nd node’s current value,
and so on …

 NOTE :
If the length L of linked list is odd, then the first half implies at first floor(L/2) nodes. So, if L = 5, the first half refers to first 2 nodes.
If the length L of linked list is even, then the first half implies at first L/2 nodes. So, if L = 4, the first half refers to first 2 nodes.
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5,

You should return 4 -> 2 -> 3 -> 4 -> 5
as

for first node, 5 - 1 = 4
for second node, 4 - 2 = 2
Try to solve the problem using constant extra space.

Link:- https://www.interviewbit.com/problems/subtract/

CODE:-

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::subtract(ListNode* A) 
{
    int count=0,flag=0,desi=0;
    vector<int> v;
    ListNode *head = A;
    ListNode *temp = A;
    while(temp!=NULL)
    {
        flag++;
        temp=temp->next;
    }
    temp=A;
    if(count%2==0)
    {
        count=flag/2;
        desi=flag/2;
    }
    else
    {
        count=flag/2+1;
        desi=flag/2+1;
        
    }
    while(count!=0)
    {
        temp=temp->next;
        count--;
    }
    
    while(temp!=NULL)
    {
        v.push_back(temp->val);
        temp=temp->next;
    }
    temp=A;
    while(desi!=0)
    {
        
        if(flag%2!=0)
        {
        temp->val=v[desi]-(temp->val);
        temp=temp->next;
        desi--;
        }
        if(flag%2==0)
        {
        temp->val=v[desi-1]-(temp->val);
        temp=temp->next;
        desi--;
        }
    }
    return head;
    
}
