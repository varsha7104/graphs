/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 */
class Solution {
public:
bool topo(unordered_map<int,vector<int>>adj,int n,vector<int>inde){
    queue<int>q;
    for(int i=0;i<n;i++){
        if(inde[i]==0)q.push(i);
    }int c=q.size();
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(int &v:adj[f]){
            inde[v]--;
            if(inde[v]==0){c++;
            q.push(v);}
        }
    } return c==n;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int,vector<int>>adj;
    vector<int>indegree(numCourses,0);
    for(auto &vec: prerequisites){
        int a=vec[0];
        int b=vec[1];
        adj[b].push_back(a);
        indegree[a]++;
    }return topo(adj,numCourses,indegree);    
    }
};
/*Input: numCourses = 2, prerequisites = [[1,0]]
Output: true*/
