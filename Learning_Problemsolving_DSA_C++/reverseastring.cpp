#include<iostream>
using namespace std;
void reverse(string&s ,int start ,int end){
    while(start < end){
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
    
}
int main(){
    string s = "My name is shiva";
    string sub="";
    string res=" ";
    int start=0;                           
    int i =0;
    reverse(s,start,s.length()-1);
    while(i<s.length()){
        while(i < s.length() && s[i]!=' ' ){
            i++;
        }
       
        reverse(s,start,i-1);
        
        
        start= i+1;
        i=start;

    }
    cout << s << endl;
    return 0;
}