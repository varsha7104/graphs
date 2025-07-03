
/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.*/
class Solution {
  public:

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>>adj(V);vector<int>indegree(V,0);
        for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
  indegree[v]++;
        }
  queue<int>q;int c=0;
  for(int i=0;i<V;i++){
      if(indegree[i]==0){ q.push(i);c++;}
  }while(!q.empty())
{
    int u=q.front();q.pop();
    for(int  & v:adj[u])
{indegree[v]--;
    if(indegree[v]==0) {q.push(v);c++;}
}} 
if(c==V) return false;
return true;
        
        
        
    }
};/*: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 0], [2, 3]]

Output: true*/
