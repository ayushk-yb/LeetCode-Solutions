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
    ListNode* reverseList(ListNode* head){
        if(!head){
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* findKth(ListNode* head, int k){
        while(head){
            k--;
            if(k == 0){
                return head;
            }
            head = head->next;
        }

        return NULL;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* kthNode = findKth(temp, k);
            if(kthNode == NULL){
                if(prev){
                    prev->next = temp;
                }
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            kthNode = reverseList(temp);
            if(temp == head){
                head = kthNode;
            }
            else{
                prev->next = kthNode;
            }
            prev = temp;
            temp = nextNode;
        }

        return head;
    }
};