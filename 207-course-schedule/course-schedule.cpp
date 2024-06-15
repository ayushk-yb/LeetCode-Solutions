class Solution {
public:
    bool checkCourse(int i, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis){
        vis[i] = true;
        dfsVis[i] = true;

        for(auto it : adj[i]){
            if(!vis[it]){
                if(checkCourse(it, adj, vis, dfsVis)){
                    return true;
                }
            }
            else if(dfsVis[it] == true){
                return true;
            }
        }
        dfsVis[i] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> dfsVis(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(checkCourse(i, adj, vis, dfsVis)){
                    return false;
                }
            }
        }
        return true; 
    }
};