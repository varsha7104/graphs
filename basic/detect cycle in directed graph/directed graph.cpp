/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.
*/

class Solution {
  public:
  bool dfs(int u,vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&inrec){
      vis[u]=true;
      inrec[u]=true;
      for(int &v:adj[u]){
          if(!vis[v]  && dfs(v,adj,vis,inrec)) return true;
          else if(inrec[v]==true) return true;
      }inrec[u]=false;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
  
        }vector<bool>vis(V,false);
        vector<bool>inrec(V,false);
     for(int i=0;i<V;i++){
         if(!vis[i ] && dfs(i,adj,vis,inrec)) return true;
     }return false;
    }
};
/*V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 0], [2, 3]]

Output: true*/
