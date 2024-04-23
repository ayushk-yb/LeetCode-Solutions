class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        List<Integer> res = new ArrayList<>();
        if(n == 1){
            res.add(0);
            return res;
        }
        int degree[] = new int[n];
        for(int i = 0; i < n; i++){
            adj.add(new ArrayList<>());
        }

        for(int[] edge : edges){
            degree[edge[0]]++;
            degree[edge[1]]++;
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                q.add(i);
            }
        }

        while(n > 2){
            int size = q.size();
            n = n - size;
            while(size-- > 0){
                int curr = q.poll();
                for(int v : adj.get(curr)){
                    degree[v]--;
                    if(degree[v] == 1){
                        q.add(v);
                    }
                }
            }
        }

        res.addAll(q);

        return res;
    }
}