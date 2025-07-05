/*
Detect Cycle using DSU
Difficulty: MediumAccuracy: 48.37%Submissions: 64K+Points: 4Average Time: 15m
Given an undirected graph with no self loops with V (from 0 to V-1) nodes and E edges, the task is to check if there is any cycle in the undirected graph.

Note: Solve the problem using disjoint set union (DSU).

*/


class Solution {
  public:
vector<int>par,rank;
int find(int x){
    if(par[x]==x) return x;
    return find(par[x]);
}
void unionset(int u,int v){
    int p_u=find(u);
    int p_v=find(v);
    if(p_u==p_v) return;
    if(rank[p_u]<rank[p_v]){
        par[p_u]=p_v;
        
    }else if(rank[p_v]>rank[p_u]){
        par[p_v]=p_u;
    }else {
        par[p_u]=p_v;
        rank[p_v]+=1;
    }
}
    int detectCycle(int V, vector<int> adj[]) {
    par.resize(V);
    rank.resize(V,0);
    for(int i=0;i<V;i++) par[i]=i;
    for(int u=0;u<V;u++){
        for(int &v:adj[u]){
            if(u<v){
                int x=find(u);
                int y=find(v);
                if(x==y)return true;
                unionset(u,v);
            }
        }
    }return false;
        
    }
};/*
Input:
[[3,4],[3],[3,4],[0,1,2],[0,2]]
  Output:true*/
