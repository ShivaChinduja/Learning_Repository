#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    vector<int> arr ={4, 8, 5, 2, 25};
    int n = arr.size();
    vector<int> res(n,-1);
    stack<int> index;
    for(int i=0;i<n;i++){
        while(!index.empty() && arr[index.top()] > arr[i]){
            res[index.top()] = arr[i];
            index.pop();
        }
        index.push(i);
    } 
    for(auto i: res){cout << i << " ";}
    cout << endl;

    

    return 0;
}