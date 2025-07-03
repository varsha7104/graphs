
/*Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.*/
  class Solution {
  public:

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);queue<int>q; vector<int>res;
        vector<int>indegree(V,0);
for(int i=0;i<edges.size();i++){
    int u=edges[i][0];
    int v=edges[i][1];
    adj[u].push_back(v);
    indegree[v]++;
}for(int i=0;i<V;i++){
    if(indegree[i]==0) {
        q.push(i);
    }
}while(!q.empty()){
    int u=q.front();
    q.pop();res.push_back(u);
    for(int &v:adj[u]){
        indegree[v]--;
        if(indegree[v]==0) {
        q.push(v);
        }
    }
}return res;

    }
};/* V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

Output: true*/
