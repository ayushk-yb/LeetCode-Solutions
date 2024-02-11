struct Node {
    Node* children[2];

    bool containsKey(int key)
    {
        return (children[key] != NULL);
    }

    Node* get(int bit)
    {
        return children[bit];
    }

    void put(int bit, Node* node)
    {
        children[bit] = node;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node* node = root;
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMaxXor(int x)
    {
        int maxi = 0;
        Node* node = root;
        for(int i = 31; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            if(node->containsKey(1 - bit))
            {
                maxi = maxi | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }

        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi = -1e8;
        int n = nums.size();
        Trie trie;
        for(int i = 0; i < n; i++)
        {
            trie.insert(nums[i]);
        }

        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, trie.getMaxXor(nums[i]));
        }

        return maxi;
    }
};