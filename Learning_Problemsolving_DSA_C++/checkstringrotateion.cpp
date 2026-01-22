#include<iostream>
#include<vector>
using namespace std;

bool efficientchek(string s1,string s2){
    if(s1.length() != s2.length()) return false;
    string temp = s1+s1;
    return(temp.find(s2) != string::npos);
}
bool findrotate(string s1, string s2){

    if(s1.length()!= s2.length()) return false;
    else{
        for(int i=1;i<=s1.length();i++){
            if(s1.substr(i)+s1.substr(0,i) == s2){
                return true;
            }
        }
    }
    return false;
}
int main(){
    string s1= "abcd", s2 = "cdab";
    cout << (findrotate(s1,s2)?"true":"false")<< endl;
    cout << "The most efficient way" << endl;
    cout <<(efficientchek(s1,s2)?"true":"false")<< endl;
    
    return 0;
}