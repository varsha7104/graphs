// User function Template for C++
/*Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.*/
class Solution {
  public:
  void dfs(int u,vector<vector<int>>&adj,vector<bool>&vis){
      vis[u]=true;
      for(int  &v:adj[u]){
          if(!vis[v])
{
    dfs(v,adj,vis);
}      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
    vector<vector<int>>adjs(V);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
{
    if(adj[i][j]!=0 && i!=j){
        adjs[i].push_back(j);
    }}}int c=0;
    vector<bool>vis(V,false);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            c++;
            dfs(i,adjs,vis);
        }
    }return c;
    }
};/*Input:[[1, 0, 1],[0, 1, 0],[1, 0, 1]]
 
Output:
2*/
