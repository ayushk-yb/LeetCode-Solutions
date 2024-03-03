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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
            
        ListNode* temp = head;
        int numNodes = 0;
        while(temp != NULL)
        {
            numNodes++;
            temp = temp->next;
        }
        if(numNodes == n)
            return head->next;
        n = numNodes - n - 1;
        temp = head;
        while(n > 0)
        {
            temp = temp->next;
            n--;
        }
        temp->next = temp->next->next;

        return head;
    }
};