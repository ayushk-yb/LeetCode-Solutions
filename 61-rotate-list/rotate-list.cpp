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
    int countNodes(ListNode* head)
    {
        int count = 0;
        ListNode* temp = head;
        while(temp)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    ListNode* rotateHelper(ListNode* head)
    {
        ListNode* temp = head;
        while(temp->next->next)
        {
            temp = temp->next;
        }
        ListNode* dummy = temp->next;
        temp->next = NULL;

        return dummy;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        if(k == 0)
            return head;
        int n = countNodes(head);
        k = k % n;
        ListNode* temp = head;
        while(k > 0)
        {
            ListNode* newHead = rotateHelper(temp);
            newHead->next = temp;
            temp = newHead;
            k--;
        }
        return temp;

    }
};