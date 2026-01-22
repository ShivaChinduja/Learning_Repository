#include<iostream>
#include<vector>
using namespace std;
void reverse(string& s, int start , int end){
    while(start<end){
        swap(s[start] , s[end]);
        start++;
        end --;
    }
}
int main(){
    string s = "I am in zoho interview";
    reverse(s, 0, s.length()-1);
    int start =0;
    for(int i=0;i<=s.length();i++){
        if(i==s.length() || s[i]==' '){
            reverse(s,start,i-1);
            start = i+1;
        }
    }

    cout << s << endl;
    //. Find missing number in array
    vector<int> v= {1,4,5,2,6};
    int n = 6;
    int sumi =0;
    int suma =0;
    for(int i=1;i<=n-1;i++){
        sumi+=i;
        suma+=v[i-1];
    }
    cout << suma - sumi;

    
    return 0;
}