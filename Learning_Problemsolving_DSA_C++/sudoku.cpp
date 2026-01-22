//sudoku solver
#include<iostream>
#include<vector>
#define N 9
using namespace std;
bool issafe(vector<vector<int>>& grid,int row,int col, int num){
    for(int i=0;i<grid.size();i++){
        if(grid[i][col] == num){return false;}
    }
    for(int i=0;i<grid[0].size();i++){
        if(grid[row][i] == num){return false;}
    }
    int startr = row-row%3;
    int startc = col-col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[startr+i][startc+j] == num){return false;}
        }
    }
    return true;
}
void printboard(vector<vector<int>>& grid){
    for(auto i: grid){
        for(auto j:i){
            cout << j << " " ;
        }
        cout << endl;
    }
}
bool sudokusolver(vector<vector<int>>& grid){
    int row =-1 , col=-1;
    bool isempty = false;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j] == 0){
                row =i;
                col =j;
                isempty = true;
                break;
            }
        }
        if(isempty) break;
    }
    if(!isempty) return true;
    for(int i=1;i<=9;i++){
        if(issafe(grid , row , col ,i))
        {
            grid[row][col] = i;
            if(sudokusolver(grid)) return true;
            grid[row][col] = 0;
        }
    }
    return false;


}
int main(){
    vector<vector<int>> grid = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
      	{5, 2, 0, 0, 0, 0, 0, 0, 0}, 
      	{0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
      	{9, 0, 0, 8, 6, 3, 0, 0, 5}, 
      	{0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
      	{0, 0, 0, 0, 0, 0, 0, 7, 4}, 
      	{0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if(sudokusolver(grid)) printboard(grid);
    else cout << "Wrong entries in sudoku bord" << endl ;
    return 0;
}