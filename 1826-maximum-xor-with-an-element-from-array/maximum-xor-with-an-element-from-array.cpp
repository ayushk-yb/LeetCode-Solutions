struct Node {
    Node* children[2];

    bool containsKey(int key) { return (children[key] != NULL); }

    Node* get(int bit) { return children[bit]; }

    void put(int bit, Node* node) { children[bit] = node; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMaxXor(int x) {
        int maxi = 0;
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxi = maxi | (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        vector<pair<int, pair<int, int>>> offlineQueries;
        sort(arr.begin(), arr.end());
        int index = 0;
        for (auto& it : queries) {
            offlineQueries.push_back({it[1], {it[0], index++}});
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        int i = 0;
        int n = arr.size();
        Trie trie;

        for (auto& it : offlineQueries) {
            while (i < n && arr[i] <= it.first) {
                trie.insert(arr[i]);
                i++;
            }
            if (i != 0)
                ans[it.second.second] = trie.getMaxXor(it.second.first);
            else
                ans[it.second.second] = -1;
        }
        return ans;
    }
};