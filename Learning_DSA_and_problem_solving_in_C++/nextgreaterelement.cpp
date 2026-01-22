#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    stack<int> num;
    vector<int> res(arr.size(), -1);
    for(int i = 0;i < arr.size();i++){
        while(!num.empty() && arr[num.top()] < arr[i]){
            res[num.top()] = arr[i];
            num.pop();
        }
        num.push(i);

    }
    for(auto i: res){
        cout << i << " ";

    }
    return 0;
}