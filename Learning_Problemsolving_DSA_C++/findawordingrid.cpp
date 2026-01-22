//find a word in grid

#include<iostream>
#include<vector>
using namespace std;
vector<int> x = {-1,-1,-1,0,0,1,1,1};
vector<int> y = {-1,1,0,1,-1,1,-1,0};
bool valid(int x,int y , int l,int h){
    return x>=0 && x<h && y>=0 && y<l;
}
bool findword(int index ,vector<vector<char>>& g,string word,int r,int c,int dr,int dc,int l,int h){
    if(index == word.length()) return true;
    if(valid(r,c,l,h) && word[index] == g[r][c]){
        return findword(index+1,g,word,r+dr,c+dc,dr,dc,l,h);
    }
    return false;
}
vector<vector<int>> searchword(vector<vector<char>>& g,string word){
    int length = g[0].size();
    int height = g.size();
    vector<vector<int>> res;
    for(int i=0;i<height;i++){
        for(int j=0;j<length;j++){
            for(int k=0;k<8;k++){
                if(findword(0,g,word,i,j,x[k],y[k],length,height)){
                    res.push_back({i,j});
                }
            }
        }
    }
    return res;
}


int main(){
    
    vector<vector<char>> grid = {
  {'A','B','C'},
  {'A','B','E'},
  {'A','D','E'}

    };
    string search = "ABE";
    vector<vector<int>> ans = searchword(grid , search);
    for(auto x: ans){
        for(auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}