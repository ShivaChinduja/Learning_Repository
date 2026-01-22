//island
#include<iostream>
#include<vector>
using namespace std;
vector<int> dr = {-1,1,0,0};
vector<int> dc = {0,0,-1,1};
bool issafe(int r , int c , vector<vector<int>>& grid){
    return r>=0 && r<grid.size() && c>=0 && c<grid[0].size()
    && grid[r][c] == 1;
}
void dfs(vector<vector<int>>&grid ,vector<vector<int>>&vis,int r,int c){
    int n = grid.size();
    int m = grid[0].size();
    vis[r][c] = 1;
    for(int i=0;i<4;i++){
        int xr = r+dr[i];
        int xc = c+dc[i];
        if(issafe(xr,xc,grid) && vis[xr][xc] == 0){
            dfs(grid,vis,xr,xc);
        }
    }
}
int countisland(vector<vector<int>>& grid){
    int count =0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1 && visited[i][j] ==0){
                dfs(grid , visited,i,j);
                count++;
            }
        }
    }
    return count;
}
int main(){
    vector<vector<int>> grid = {
    {1,1,0,0,0},
    {1,1,0,0,0},
    {0,0,1,0,0},
    {0,0,0,1,1}};
    cout << countisland(grid) << endl;
    return 0;
}