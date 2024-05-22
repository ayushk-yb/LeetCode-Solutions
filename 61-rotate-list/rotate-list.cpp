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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        int n = 0;
        for(int i = 0; i < k; i++){
            fast = fast->next;
            n++;
            if(fast == NULL){
                k = k % n;
                if(k == 0){
                    return head;
                }
                fast = head;
                for(int j = 0; j < k; j++){
                    fast = fast->next;
                }
                break;
            }
        }

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* nextNode = slow->next;
        slow->next = NULL;
        fast->next = head;
        return nextNode;
    }
};