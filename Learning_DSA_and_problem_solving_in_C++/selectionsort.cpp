//selection sort in c++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector <int> arr = {0,50,20,5,8,5,40};
    for(int i=0;i<arr.size();i++){
        int min_index = i;
        for(int j=i;j<arr.size();j++){
            if(arr[j]< arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i] , arr[min_index]);
    }

    for (auto i: arr){cout << i << " ";}
    return 0;
}