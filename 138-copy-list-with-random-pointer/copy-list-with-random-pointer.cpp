/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return nullptr;
        
        Node* curr = head;
        while(curr)
        {
            Node* clonedNode = new Node(curr->val);
            clonedNode->next = curr->next;
            curr->next = clonedNode;
            curr = clonedNode->next;
        }
        curr = head;
        while(curr)
        {
            if(curr->random)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        Node* cloneHead = head->next;
        Node* cloneCurr = cloneHead;
        curr = head;
        while(curr)
        {
            curr->next = curr->next->next;
            if(cloneCurr->next)
            {
                cloneCurr->next = cloneCurr->next->next;
            }
            cloneCurr = cloneCurr->next;
            curr = curr->next;
        }
        return cloneHead;
    }
};