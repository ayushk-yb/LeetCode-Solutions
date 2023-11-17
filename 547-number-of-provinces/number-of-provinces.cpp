class DisjointSet {
    vector<int> parent, rank, size;

    public:
        DisjointSet(int n){
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            size.resize(n + 1, 1);
            for(int i = 0; i <= n; i++)
            {
                parent[i] = i;
            }
        }

        int findUPar(int node)
        {
            if(node == parent[node])
                return node;
            
            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v)
        {
            int ulPar_u = findUPar(u);
            int ulPar_v = findUPar(v);

            if(ulPar_u == ulPar_v)
                return;
            if(rank[ulPar_u] < rank[ulPar_v])
            {
                parent[ulPar_u] = ulPar_v;
            }
            else if(rank[ulPar_v] < rank[ulPar_u])
            {
                parent[ulPar_v] = ulPar_u;
            }
            else
            {
                parent[ulPar_v] = ulPar_u;
                rank[ulPar_u]++;
            }
        }

        void unionBySize(int u, int v)
        {
            int ulPar_u = findUPar(u);
            int ulPar_v = findUPar(v);

            if(ulPar_u == ulPar_v)
                return;
            if(size[ulPar_u] < size[ulPar_v])
            {
                parent[ulPar_u] = ulPar_v;
                size[ulPar_v] += size[ulPar_u];
            }
            else
            {
                parent[ulPar_v] = ulPar_u;
                size[ulPar_u] += size[ulPar_v];
            }
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j])
                {
                    if(ds.findUPar(i) != ds.findUPar(j))
                    {
                        ds.unionBySize(i, j);
                    }
                }
            }
        }
        unordered_set<int> st;
        for(int i = 0; i < n; i++)
        {
            st.insert(ds.findUPar(i));
        }

        return st.size();
    }
};