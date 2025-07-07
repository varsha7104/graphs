/*You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] 
denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

 */
  class Solution {
public:
vector<int>par;
vector<int>rank;
int find(int u){
    if(u==par[u]) return u;
    return par[u]=find(par[u]);
}
void unionset(int u,int v){
    int x=find(u);
    int y=find(v);
    if(x==y)return;
    if(rank[x]>rank[y]) par[y]=x;
    else if(rank[x]<rank[y]) par[x]=y;
    else {
        par[x]=y;
        rank[x]+=1;
    }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        rank.resize(n);
        par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
        for(auto &vec:edges){
         
                unionset(vec[0],vec[1]);
          
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int p=find(i);
            mp[p]++;
        }
        long long res=0,rem=n;
        for(auto &it:mp){
            long long n=it.second;
            res+=(n)*(rem-n);
            rem-=n;
        }return res;

    }
};/* n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0*/
