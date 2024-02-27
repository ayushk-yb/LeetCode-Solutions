class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adjList(n);
        int i = 0;
        for(auto it : edges)
        {
            adjList[it[0]].push_back({it[1], succProb[i]});
            adjList[it[1]].push_back({it[0], succProb[i]});
            i++;
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;

        while(!pq.empty())
        {
            pair<double, int> p = pq.top();
            double curr_prob = p.first;
            int curr_node = p.second;
            if(curr_node == end_node)
                return curr_prob;

            pq.pop();

            for(auto it : adjList[curr_node])
            {
                int node = it.first;
                double new_prob = it.second * curr_prob;
                if(new_prob > prob[node])
                {
                    prob[node] = new_prob;
                    pq.push({new_prob, node});
                }
            }
        }

        return 0.0;
    }
};