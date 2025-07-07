/*Problem statement
You have been given a graph consisting of ‘N’ vertices numbered from 1 to ‘N’. The graph has ‘M’ edges. In an operation, you can shift an edge between two directly 
connected vertices to between pair of disconnected vertices to make them directly connected. Return the minimum number of operations to make the graph connected. 
If it is not possible to make graph connected return -1.

Example:
Let’s say ‘N’ is 4 and ‘M' is 3. The 3 edges are (1,2), (2,3) and (1,3). Then our graph will look as follows:-*/
// User function Template for C++

class Solution {
  public:
  vector<int>rank;
  vector<int>par;
  int find(int u){
      if(u==par[u]) return u;
      return par[u]=find(par[u]);
  }
  void unionset(int u,int v){
      int x=find(u);
      int y=find(v);
      if(x==y)return;
      if(rank[x]<rank[y])par[x]=y;
      else if(rank[y]<rank[x]) par[y]=x;
      else {
          par[x]=y;
          rank[x]+=1;
      }
  }
    int Solve(int n, vector<vector<int>>& edge) {
      if(edge.size()<n-1) return -1;
      rank.resize(n);
      par.resize(n);
      for(int i=0;i<n;i++){
       par[i]=i;
      }int c=n;
      for(auto & vec:edge){
          if(find(vec[0]) !=find(vec[1])){
              c--;
              unionset(vec[0],vec[1]);
          }
      }
        return c-1;
    }
};/*Input:
n = 4
m = 3
Edges = [ [0, 1] , [0, 2] , [1, 2] ]
Output:
1*/
