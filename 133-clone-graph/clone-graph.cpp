/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        unordered_map<Node*, Node*> copied;
        queue<Node*> q;
        copied[node] = new Node(node->val);
        q.push(node);
        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            for(Node* neighbor : curr->neighbors)
            {
                if(!copied.count(neighbor))
                {
                    copied[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                copied[curr]->neighbors.push_back(copied[neighbor]);
            }
        }

        return copied[node];
    }
};