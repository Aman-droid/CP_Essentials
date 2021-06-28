#include <bits/stdc++.h>
using namespace std;

const int mxn=2e5;
int n,c[mxn];
vector<int>adj[mxn];

void dfs(int node=1,int p=-1){
    c[node]=1;
    for(int child:adj[node]){
        dfs(child,node);
        c[node]+=c[child];
    }
}
int main()
{
    cin>>n;
    for(int i=2;i<=n;i++){
        int p;cin>>p;
        adj[p].push_back(i);
    }
    dfs();
    for(int i=1;i<=n;i++)
        cout<<c[i]-1<<" ";
}