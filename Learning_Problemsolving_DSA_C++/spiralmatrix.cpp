//Spiral matrix 
#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralmat(vector<vector<int>>& mat){
    vector<int> res;
    int left =0,top=0;
    int right = mat[0].size() - 1;
    int bottom = mat.size()-1;
    while(top<= bottom && left <= right){
        for(int i=left;i<=right;i++){
            res.push_back(mat[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            res.push_back(mat[i][right]);
        }
        right--;
        if(top<bottom){
            for(int i=right;i>=left;i--){
                res.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        if(left<right){
            for(int i=bottom;i>=top;i--){
                res.push_back(mat[i][left]);
            }
            left++;

        }
    }
    return res;

}
int main(){
    vector<vector<int>> mat ={{1,2,3},
                            {4,5,6},
                            {7,8,9}};
    vector<int> res;
    res = spiralmat(mat);
    for(auto i: res) cout << i << " ";
    return 0;
}