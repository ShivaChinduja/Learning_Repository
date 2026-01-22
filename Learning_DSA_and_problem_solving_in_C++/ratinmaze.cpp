//rat in a maze
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string direction = "DLRU";
vector<int> dr = {1,0,0,-1};
vector<int> dc = {0,-1,1,0};
bool isvalid(int r , int c , vector<vector<int>> maze , int siz){
    return (r>=0 && r<siz && c>=0 && c<siz && maze[r][c] == 1);

}
void findpath(int row,int col, string& path,vector<string>& res, vector<vector<int>>& maze , int n){
    if(row == n-1 && col == n-1){
        res.push_back(path);
        return;
    }
    maze[row][col] = 0;
    for(int i=0;i<n;i++){
        int nr = row+dr[i];
        int nc = col+dc[i];
        if(isvalid(nr , nc , maze,n)){
            path.push_back(direction[i]);
            findpath(nr,nc,path,res,maze,n);
            path.pop_back();
        }
    }
    maze[row][col] = 1;
}
vector<string> ratinmaze(vector<vector<int>>& maze){
    vector<string> res;
    int n = maze.size();
    string path = "";
    if(maze[0][0] == 1 && maze[n-1][n-1]==1){
        findpath(0,0,path,res,maze,n);
        sort(res.begin(),res.end());
    }
    else{
        cout << "No possibilities" << endl;
    }
    return res;
}
int main(){
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> result = ratinmaze(maze);
    for(auto i: result){cout << i << " ";}


    return 0;
}
//output DDRDRR DRDDRR