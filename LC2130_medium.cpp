/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* newHead;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* current = head;
        
        while(current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        newHead = prev;
        
        return newHead;
    }
    
    int calculateLen(ListNode* head)
    {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }
    int pairSum(ListNode* head) 
    {
        int len = calculateLen(head);
        ListNode* temp = head;
        ListNode* revHead;
        int cnt = len / 2;
        ListNode* prev;
        while(cnt--)
        {
            temp = temp->next;
        }
        
        revHead = reverse(temp);
        
        int ans = INT_MIN;
        
        while(head != NULL && revHead != NULL)
        {
            ans = max(ans , head->val + revHead->val);
            head = head->next;
            revHead = revHead->next;
        }
        return ans;
    }
};
