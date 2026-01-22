/*#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
void possiblestrings(string s){
    int n = s.length();
    vector<string> res;
    for(int i=0;i<(1<<n);i++){
        string sub="";
        for(int j=0;j<n;j++){
            if(i&(1<<j)){sub+=s[j];}
        }
        res.push_back(sub);
    }
    for(auto i : res){cout << i << " ";}

}
class LRU{
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> mp;

    public:
    int capacity;
    LRU(int cap):capacity(cap){}
    void put(int key , int value){
        auto data = mp.find(key);
        if(data!=mp.end()){
            data->second->second = value;
            cache.splice(cache.begin(),cache,data->second);
            print();
            return;
        }
        if(mp.size() == capacity){
            auto last = cache.back();
            mp.erase(last.first);
            cache.pop_back();
        }
        cache.push_front({key,value});
        mp[key] = cache.begin();
        print();

    }
    int get(int key){
        auto data = mp.find(key);
        if(data != mp.end()){
            cache.splice(cache.begin(),cache,data->second);
            print();
            return data->second->second;
        }
        cout << "Value not found;" << endl; 
        return -1;
    }
    void print(){
        cout << "Current data is : " << endl;
        for(auto values: cache){
            cout << values.first << " " << values.second << endl;
        }
    }
};
int main(){
    string s = "abc";
    LRU* l = new LRU(3);
    l->put(1,10);
    l->put(2,20);
    l->put(3,30);
    cout <<"Getting value : " <<  l->get(1) << endl;
    l->put(4,40);


    delete l;
    //possiblestrings(s);
    
    return 0;
}*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void generatesubset(int index,string& cur,string& s, vector<string>& res){
    if(index ==s.length()){
        res.push_back(cur);
        return;
    }
    generatesubset(index+1,cur,s,res);
    cur.push_back(s[index]);
    generatesubset(index+1,cur,s,res);
    cur.pop_back();
}
int main(){
    string s= "abc";
    vector<string> res;
    string current = "";
    generatesubset(0,current,s,res);
    sort(res.begin(),res.end());
    for(auto i:res){
        cout << i << " ";
    }
    return 0;
}