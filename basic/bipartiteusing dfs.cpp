/*Given a Graph with V vertices (Numbered from 0 to V-1) and E edges. Check whether the graph is bipartite or not.

A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:

All edges connect vertices from one set to vertices in the other set.
No edges exist between vertices within the same set.
Examples:

Input: V = 3, edges[][] = [[0, 1], [1,2]]
Bipartite-Graph
Output: true*/
class Solution {
  public:
  bool dfs(int u,vector<int>adj[],vector<int>&color,int c){
      color[u]=c;
      for(int &v:adj[u]){
          if(color[v]==c) return false;
          if(color[v]==-1){
             if(!dfs(v,adj,color,1-c)) return false;
          }
      }return true;
  }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int>adj[V];
        for(auto &edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }vector<int>color(V,-1);
        int n=V;
        for(int i=0;i<n;i++){int c=0;
            if(color[i]==-1){
                if(!dfs(i,adj,color,c)) return false;
            }
        }return true;
    }
};
