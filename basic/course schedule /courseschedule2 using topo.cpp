/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]*/

vector<int>topo(unordered_map<int,vector<int>>&adj,vector<int>indegree,int n){
    vector<int>res;queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){ q.push(i);res.push_back(i);}
    }
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(int&v:adj[f] ){
            indegree[v]--;
            if(indegree[v]==0){res.push_back(v);
                q.push(v);
            }
        }
    }if(res.size()==n) return res;
    return {};
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int ,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto &edge: prerequisites){
            int u=edge[0];
            int v=edge[1];
adj[v].push_back(u);
indegree[u]++;
        }
        return topo(adj,indegree,numCourses);
    }

