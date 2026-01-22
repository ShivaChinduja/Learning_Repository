//singleton design patterns
#include<iostream>
#include<utility>
using namespace std;
class GlobalConfig{
    int key;
    int value;
    //privte constructor
    GlobalConfig(){}
    public:
    // remove copy constructor ability
    GlobalConfig(GlobalConfig const&) = delete;
    //remove assignment operator ability 
    GlobalConfig operator=(GlobalConfig const&) = delete;
    //static method to access private constructor
    static GlobalConfig& get(){
        static GlobalConfig config;
        return config;
    } 
    void setstate(const int k,const int v){
        key =k;
        value = v;
    }
    pair<int,int> getstate(){
        return {key,value};
    }
};
int main(){
    GlobalConfig& obj = GlobalConfig::get();
    GlobalConfig& obj2 = GlobalConfig::get();
    obj.setstate(1,2);
    pair<int,int> v=obj2.getstate();
    cout << v.first << " "<< v.second; 


    return 0;
}
