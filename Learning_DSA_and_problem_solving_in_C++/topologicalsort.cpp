//topological sort 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addedge(vector<vector<int>>& adj , int u,int v){
    adj[u].push_back(v);
}
vector<int> topologicalsort(vector<vector<int>>& adj){
    int n = adj.size();
    queue<int> q;
    vector<int> res;
    vector<int> indegree(n,0);
    cout << "n " <<  n << endl;
    for(int i=0;i<n;i++){
        for(int next: adj[i]){indegree[next]++;}
    }
    for(int i=0;i<n;i++){
        if(indegree[i] == 0){q.push(i);}
    }
    while(!q.empty()){
        int top = q.front();
        q.pop();
        res.push_back(top);
        for(int next:adj[top]){
            indegree[next]--;
            if(indegree[next] == 0) q.push(next);
        }
    }
    
    return res;
}
int main(){
    vector<vector<int>> adj(6);
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,4,5);
    addedge(adj,5,1);
    addedge(adj,5,2);
    vector<int> ans = topologicalsort(adj);
    cout <<"\ntopolicalsort output\n" << endl;
    for(auto i:ans) cout << i << " ";
    cout << endl;

    
    return 0;
}