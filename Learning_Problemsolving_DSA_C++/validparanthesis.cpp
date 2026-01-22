#include<iostream>
#include<stack>
using namespace std;
bool isvalid(string s){
    stack<char> res;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i] == '[' || s[i] == '{'){
            res.push(s[i]);
        }
        else{
            if(res.empty()) return false;
            if(s[i]==')' && res.top()=='(' || s[i]==']' && res.top()=='[' || s[i]=='}' && res.top()=='{'){
                res.pop();
            }
            else{
                return false;
            }
        }
    }
    return res.empty();
}
int main(){
    string s = "()[]{}";
    
    cout<< (isvalid(s)?"true":"false") << endl;
    return 0;
}