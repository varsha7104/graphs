
/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true*/
  bool dfs(vector<bool>&vis,vector<bool>&inrec,unordered_map<int,vector<int>>&adj,int u){
vis[u]=true;
inrec[u]=true;
for(int &v:adj[u]){
    if(!vis[v] && dfs(vis,inrec,adj,v)) return true;
    else if(inrec[v]) return true;
}inrec[u]=false;
return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int,vector<int>>adj;
    vector<int>indegree(numCourses,0);
    for(auto &vec: prerequisites){
        int a=vec[0];
        int b=vec[1];
        adj[b].push_back(a);
        indegree[a]++;
    }
    vector<bool>inrec(numCourses,false);
    vector<bool>vis(numCourses,false);
    for(int i=0;i<numCourses;i++){
        if(!vis[i] &&dfs(vis,inrec,adj,i)) return false;
    }return true;
    }
};
