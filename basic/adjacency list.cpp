/*Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.*/
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>>adj(V);
for(int i=0;i<edges.size();i++){

    int x=edges[i].first;
    int y=edges[i].second;
    adj[x].push_back(y);
    adj[y].push_back(x);
    
}return adj;
        
    }
};
/*Input:
Input:
V = 5, E = 7
edges = [[0,1], [0,4], [4,1], [4,3], [1,3], [1,2], [3,2]]

Output: 
[[1,4], [0,2,3,4], [1,3], [1,2,4], [0,1,3]]
  */
