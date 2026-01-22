#include<iostream>
#include<vector>
using namespace std;
string dir = "DLRU";
vector<int> x = {1,0,0,-1};
vector<int> y ={0,-1,1,0};
bool issafe(vector<vector<int>>& maze, int r , int c,int n,vector<vector<int>>& vis){
    return (r>=0 && c>=0 && r<n && c<n && maze[r][c] && !vis[r][c]);
}
void findpath(vector<vector<int>>& maze , int r , int c , vector<string>& res,string& path,vector<vector<int>>& vis){
    int n = maze.size();
    if(r == n-1 && c ==n-1){
        res.push_back(path);
        return;
    }
    vis[r][c] = 1; // visited
    for(int i=0;i<4;i++){
        //4 possible directions
        int dr = r+x[i];
        int dc = c+y[i];
        if(issafe(maze, dr,dc,n,vis)){
            path.push_back(dir[i]);
            findpath(maze,dr,dc,res,path,vis);
            path.pop_back();
        }
    }
    vis[r][c] = 0;
}
void findpathmaze(vector<vector<int>>& maze){
    int n = maze.size();
    vector<string> result;
    string path;
    vector<vector<int>> vis(n,vector<int>(n,0));
    if(maze[0][0]==1 && maze[n-1][n-1] == 1){
    findpath(maze,0,0,result,path,vis);}
    for(auto i: result){
        cout<< i << " " ;
    }
}
int main(){
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    findpathmaze(maze);
    return 0;
}