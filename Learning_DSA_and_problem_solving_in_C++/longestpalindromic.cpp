#include<iostream>
using namespace std;
string longestpalindrome(string s){
    int n = s.length();
    int start =0,maxlen = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=1;j++){
            int low =i;
            int high = i+j;
            while(low>=0 && high<n && s[low]==s[high]){
                int currentlen = high-low+1;
                if(currentlen>maxlen){
                    maxlen = currentlen;
                    start = low;
                }
                low--;
                high++;
            }
        }
    }
    return s.substr(start,maxlen);
}
int main(){
    string s = "forgeekskeegfor";
    cout << longestpalindrome(s)<< endl;
    return 0;
}