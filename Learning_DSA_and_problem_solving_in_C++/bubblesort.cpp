//bubble sort
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector <int> arr = {0,50,20,5,8,5,40};
    for(int i=0;i< arr.size();i++){
        for(int j=0;j< arr.size()-i-1;j++){
            if(arr[j+1] < arr[j]){
                swap(arr[j] , arr[j+1]);
             }
        }
        
    }
    for(auto i: arr){cout << i << " " ;}
    return 0;
}