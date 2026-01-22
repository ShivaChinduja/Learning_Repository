//celebrity problem
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int celebrity(vector<vector<int>> arr){
    int candidate;
    stack<int> st;
    for(int i=0;i<arr.size();i++){st.push(i);}
    while(st.size() > 1){
        int A = st.top(); st.pop();
        int B = st.top();st.pop();
        if(arr[A][B]==1){
            st.push(B);
        }
        else{
            st.push(A);
        }
    }
    candidate = st.top();
    for(int i=0;i<arr.size();i++){
        if(i == candidate) continue;
        if(arr[i][candidate] == 0) return -1;
        if(arr[candidate][i]==1) return -1;
    }
    return candidate;
}
int main(){
    vector<vector<int>>arr={{1,1},{1,1}};
    cout << celebrity(arr);
}