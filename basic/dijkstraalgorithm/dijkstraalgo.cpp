/*Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge 
between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest 
distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.*/


// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
     vector<vector<pair<int,int>>>adj(V);
     for(auto &edge:edges){
         int u=edge[0];
         int v=edge[1];
         int w=edge[2];
         adj[u].push_back({v,w});
     }
     
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     pq.push({0,src});
     vector<int>res(V,INT_MAX);
     res[src]=0;
     while(!pq.empty()){
         int dist=pq.top().first;
         int node=pq.top().second;
         pq.pop();
         for(auto &p:adj[node]){
             int adjnode=p.first;
             int wt=p.second;
            
             if(dist+wt<res[adjnode]){
                 res[adjnode]=dist+wt;
                 pq.push({res[adjnode],adjnode});}
         }
     }return res;
    }
};

/*Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
Output: [4, 3, 0]*/
