#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    vector<int> arr = {10, 4, 5, 90, 120, 80};
    vector<int> span(arr.size(),0) ;
    stack<int> track;
    for(int i=0;i<arr.size();i++){
        while(!track.empty() && arr[i] >= arr[track.top()]){
            track.pop();
        }
        if(track.empty()){
            span[i] = i+1;
        }
        else{
            span[i] = i-track.top();
        }
        track.push(i);
    }
    for(auto i: span){
        cout << i << " ";
    }
    return 0;

}