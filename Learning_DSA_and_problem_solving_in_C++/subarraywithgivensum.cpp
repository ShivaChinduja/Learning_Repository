//. Subarray with given sum
//arr = [1, 2, 3, 7, 5]
//sum = 12
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr = {1,2,3,7,5};
    int start=0, end=0;
    int ls=0 , le=0;
    int currentsum =0;
    int sum =12;
    for(int i=0;i< arr.size();i++){
        currentsum+=arr[i];//1 // 3//6//13
        while( start<=i && currentsum > sum){
            currentsum-=arr[start++]; // 12
        }
        if(currentsum == sum){
            ls = start ;
            le = i;
            break;
        }
    }
    for(int i=ls;i<=le;i++){cout << arr[i] << " " ;}
    cout << endl;
    return 0;

}