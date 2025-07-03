/*Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to right according to the given adjacency list, and return a list containing the BFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.*/
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
      queue<int>q;
      q.push(0);
      int n=adj.size();
      vector<bool>vis(n,false);
      vis[0]=true;
      vector<int>res;
      while(!q.empty()){
          int u=q.front();
          q.pop();res.push_back(u);
          for(int  & v:adj[u]){
              if(!vis[v]){
                  vis[v]=true;
                  q.push(v);
                  
              }
          }
      }return res;
        
    }
};
/* adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

Output: [0, 2, 3, 1, 4]*/
