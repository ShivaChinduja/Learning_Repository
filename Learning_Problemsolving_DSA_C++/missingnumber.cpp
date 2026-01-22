#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr = {1,2,3,4,6,7,8};
    int arr0=0,arr1=0;
    int res;
    for(auto x: arr){
        arr0^=x;
    }
    for(int i=1;i<= arr.size()+1;i++){
        arr1^=i;
    }
    res = arr0^arr1;
    cout << res << endl;
    return 0;
}