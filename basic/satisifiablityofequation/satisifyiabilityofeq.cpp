/*990. Satisfiability of Equality Equations

You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes
one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.*/
class Solution {
public:
vector<int>par;
vector<int>rank;
int find(int u){
    if(u==par[u]){ return u;}
    return par[u]=find(par[u]);
}
void unionset(int u,int v){
    int x=find(u);
    int y=find(v);
    if(x==y)
    return ;
    if(rank[x]>rank[y]){
        par[y]=x;

    }else if(rank[x]<rank[y]){
        par[x]=y;
    }else {
        par[x]=y;
        rank[x]+=1;
    }
}

    bool equationsPossible(vector<string>& equations) {
        par.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++) par[i]=i;
        for(string &s: equations){
            if(s[1]=='=') {
                int f=s[0]-'a';
                int sec=s[3]-'a';
                unionset(f,sec);
            }
        }
        for(string &s:equations){
            if(s[1]=='!') {
                if(find(s[0]-'a')==find(s[3]-'a')) return false;
            }
        }return true;
    }
};
/*Output:
equations = ["a==b","b!=a"]
Output: false
*/

 
