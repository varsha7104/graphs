/*Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.*/

class Solution {
  public:
  void dfs(int u,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&res){
      vis[u]=true;
      res.push_back(u);
      for(int &v:adj[u]){
          if(!vis[v]){
              dfs(v,adj,vis,res);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int>res;
        int n=adj.size();
        vector<bool>vis(n,false);
     dfs(0,adj,vis,res);
     return res;
    }
};
/*
Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

Output: [0, 2, 4, 3, 1]
*/
