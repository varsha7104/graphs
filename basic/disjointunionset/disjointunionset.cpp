/*Given an array par[] that stores all number from 1 to n (both inclusive and sorted) and k queries.

The task is to do the following operations on array elements :

1. UNION x z : Perform union of x and z i.e. parent of z will become the parent of x.
2. FIND x: Find the ultimate parent of x and print it.

Note: Initially all are the parent of themselves.The ultimate parent is the topmost node such that par[node]=node.

Input: n = 5, k = 4, queries[] = {{find 4}, {find 1}, {unionSet 3 1}, {find 3}}
Output: 4 1 1
Explanation:*/
//*Complete the functions below*/
int find(int par[], int x) {

if(par[x]==x){
    return x;
}return  find(par,par[x]);
}

void unionSet(int par[], int x, int z) {
int px=find(par,x);
int py=find(par,z);
if(px!=py){
    par[px]=py;
}
}
