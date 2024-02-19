/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        Node* curr = root;
        queue<Node*> q;
        q.push(curr);
        while(!q.empty())
        {
            int size = q.size();
            vector<Node*> level;
            while(size--)
            {
                Node* temp = q.front();
                q.pop();
                level.push_back(temp);
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
            }
            int levelSize = level.size();
            for(int i = 0; i < levelSize - 1; i++)
            {
                level[i]->next = level[i + 1];
            }
        }

        return root;
    }
};