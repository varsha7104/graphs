/*Given a Graph with V vertices (Numbered from 0 to V-1) and E edges. Check whether the graph is bipartite or not.

A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:

All edges connect vertices from one set to vertices in the other set.
No edges exist between vertices within the same set.*/

class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
      vector<int>adj[V];
      for(auto &edge:edges){
          int u=edge[0],v=edge[1];
          adj[u].push_back(v);
          adj[v].push_back(u);
          
      }
     vector<int>color(V,-1);
     queue<int>q;
     q.push(0);
     color[0]=0;
     while(!q.empty()){
         int u=q.front();
         q.pop();
         for(int & v:adj[u]){
             if(color[v]==-1){
                 color[v]=1-color[u];
                 q.push(v);
             }
             else if(color[v]==color[u]) return false;
         }
     }return true;
    }
};
/*V = 3, edges[][] = [[0, 1], [1,2]]
Bipartite-Graph
Output: true*/
