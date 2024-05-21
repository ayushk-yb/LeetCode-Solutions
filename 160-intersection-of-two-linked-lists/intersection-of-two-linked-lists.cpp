/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* dummyOne = headA;
        ListNode* dummyTwo = headB;
        while(dummyOne != dummyTwo){
            if(dummyOne == NULL){
                dummyOne = headB;
            }
            else if(dummyTwo == NULL){
                dummyTwo = headA;
            }
            else{
                dummyOne = dummyOne->next;
                dummyTwo = dummyTwo->next;
            }
        }

        return dummyOne;
    }
};