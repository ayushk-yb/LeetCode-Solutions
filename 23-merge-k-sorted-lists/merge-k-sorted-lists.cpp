/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        struct compare
        {
            bool operator()(ListNode *a, ListNode *b)
            {
                return a->val > b->val;
            }
        };
    ListNode* mergeKLists(vector<ListNode*> &lists)
    {
        ListNode *ans = new ListNode(0);
        ListNode *dummy = ans;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(auto it : lists)
        {
            if(it)
                pq.push(it);
        }

        while(!pq.empty())
        {
            ListNode* curr = pq.top();
            pq.pop();
            dummy->next = curr;
            dummy = dummy->next;

            if(curr->next)
                pq.push(curr->next);
        }

        return ans->next;
    }
};