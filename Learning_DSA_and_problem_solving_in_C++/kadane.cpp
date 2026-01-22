#include<iostream>
#include<vector>

using namespace std;
void kadanealg(vector<int>arr)
{
    vector<int> result;
    int currentsum=arr[0];
    int maxsum=arr[0];
    int start = 0;
    int end = 0;
    int ws =0;
    int we=0;
    for(int i =0;i< arr.size();i++)
    {
        if(arr[i] > currentsum+arr[i]){
            currentsum = arr[i];
            start = i;
        }
        else{
            currentsum+=arr[i];
        }
        if(currentsum > maxsum){
            maxsum = currentsum;
            ws = start;
            we = i;

        }

    }
    for(int i = ws;i<=we;i++){
        cout << arr[i] << " ";
    }
    cout << "\n max sum is : " << maxsum << endl;
}
int main(){
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    kadanealg(arr);
    return 0;
}