class Solution {
  public:
 bool dfs(int u,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&parent){
      vis[u]=true;
      for(int &v:adj[u]){
          if(!vis[v]){
              parent[v]=u;
             if(dfs(v,adj,vis,parent)) return true;
          }else if(parent[u]!=v) return true;
      }return false;
  }
  bool bfs(int u,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&parent ,queue<int>&q)
{q.push(u);
while(!q.empty()){
    vis[u]=true;
    u=q.front();
    q.pop();
    for(int &v:adj[u]){
        if(!vis[v]){
            vis[v]=true;
            parent[v]=u;
            q.push(v);
        }else if(parent[u]!=v) return true;
    }}return false;
}
    
    bool isCycle(int V, vector<vector<int>>& edges) {

    vector<vector<int>>adj(V);

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }int n=V;
    vector<bool>vis(n,false);
    vector<int>parent(n,-1);
    queue<int>q;
for(int i=0;i<n;i++){
    if(!vis[i]){
        if(bfs(i,adj,vis,parent,q)) return true;
    }
}        return false;
    }
};
