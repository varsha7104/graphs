/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]*/bool hascycle=false;
void dfs(int u,vector<bool>&vis,vector<bool>&inrec,   unordered_map<int ,vector<int>>&adj,stack<int>&st){
    vis[u]=true;
    inrec[u]=true;
    for(int &v:adj[u]){
        
       if(inrec[v]){
            hascycle=true; break;
        }if(!vis[v]) dfs(v,vis,inrec,adj,st);
     
    }st.push(u);
    inrec[u]=false;
   // return false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int ,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto &edge: prerequisites){
            int u=edge[0];
            int v=edge[1];
adj[v].push_back(u);
indegree[u]++;
        }stack<int>st;
       vector<bool>vis(numCourses,false);
       vector<bool>inrec(numCourses,false);
       for(int i=0;i<numCourses;i++){
        if(!vis[i] )dfs(i,vis,inrec,adj,st);
       }vector<int>res;
       if(hascycle )return{};
       while(!st.empty()){
        res.push_back(st.top());
        st.pop();
       }
   return res; }
};
