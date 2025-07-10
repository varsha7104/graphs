// User function Template for C++
/*Number of Provinces
Difficulty: MediumAccuracy: 54.29%Submissions: 153K+Points: 4Average Time: 20m
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.*/
// User function Template for C++

class Solution {
  public:
  void bfs(int u,vector<vector<int>>&adj,vector<bool>&vis){
      queue<int>q;
      vis[u]=true;
      q.push(u);
      while(!q.empty()){
          int u=q.front();
          q.pop();
          for(int &v:adj[u]){
              if(!vis[v]){
                  vis[v]=true;
                  q.push(v);
              }
          }
      }
  }
 
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>>adjls(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i!=j && adj[i][j]!=0){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }vector<bool>vis(V,false);
        int c=0;
      for(int i=0;i<V;i++){
          if(!vis[i]) { bfs(i,adjls,vis);c++;}
      }
       
       
       
       return c;
    }
};
};/*Input:[[1, 0, 1],[0, 1, 0],[1, 0, 1]]
 
Output:
2*/
