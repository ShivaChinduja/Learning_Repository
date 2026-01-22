//search in sorted matrix

#include<iostream>
#include<vector>
using namespace std;
bool search(vector<int>& mat , int x){
    int low =0, high = mat.size()-1;
    while(low<=high){
        int mid =(low+high)/2;
        if(x == mat[mid]) return true ;
        else if(x > mat[mid]) low = mid+1;
        else high = mid-1;
    }
    return false;
}
bool searchmatrix(vector<vector<int>>&mat , int x){
    int low = 0;
    int high = mat.size()-1;
    int row = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(x == mat[mid][0]) return true;
        else if(x > mat[mid][0] ){
            row = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    if(row == -1) return false;

    return search(mat[row],x);
    
}
int main(){
    vector<vector<int>> mat = {{1,5,9}, 
                                {14,16,25},
                                {31,42,53}};
    int x = 12;
    cout << (searchmatrix(mat,x)?"True":"False") << endl;
    return 0;
}