#include<iostream>
#include<vector>
using namespace std;
void rotateclockwie(vector<vector<int>>& mat){
    //reverse matrix 
    int r = mat.size();
    int c = mat[0].size();
    for(int i=0;i<r;i++){
        for(int j=0;i<c;j++){
            swap(mat[i][j] , mat[j][i]);
        }
    }
    // rever rows
    for(int i=0;i<r;i++){
        reverse(mat[i].begin(), mat[i].end());
    }

}
int main(){
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotateclockwie(mat);
    cout << "clock" << endl;
    for(auto i : mat){
        for(auto j:i){cout << j << " ";}
        cout << endl;
    }
    return 0;
}