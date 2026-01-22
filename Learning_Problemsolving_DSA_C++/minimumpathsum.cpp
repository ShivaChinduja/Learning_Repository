//minimum path sum 
#include<iostream>
#include<vector>
using namespace std;
int findcost(vector<vector<int>>& mat , vector<vector<int>>& memo, int x,int y){

    int n = mat.size();
    int m = mat[0].size();
    if(x>= m || y >=n){return INT_MAX;}
    if(x == m-1 && y == n-1){return mat[x][y];}
    if(memo[x][y] !=-1) return memo[x][y];
    return memo[x][y] = mat[x][y]+ min(findcost(mat,memo,x,y+1),min(findcost(mat,memo,x+1,y),findcost(mat,memo,x+1,y+1)));

}
int mincost(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>>memo(m,vector<int>(n,-1));
    return findcost(mat,memo,0,0);
}
int main(){
    vector<vector<int>> mat = {{ 1, 2, 3 },
        { 4, 8, 2 },
        { 1, 5, 3 } };
    cout << mincost(mat) << endl;
    return 0;
}