#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll           long long
#define int          long long 
#define endl         '\n'
#define rep(i,a,b)   for(int i=a;i<=b;i++)
#define ren(i,a,b)   for(int i=a;i>=b;i--)
#define pll          pair<ll,ll>
#define pii          pair<int,int>
#define vpll         vector<pll>
#define SZ(x)        ((int)x.size())
#define FIO          ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)     cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)  cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb           push_back
#define pf           push_front

const int mxn=2e5;
vector<int> adj[mxn];
int ans[mxn];
int vis[mxn];

void solve(){
    int n,m; cin>>n>>m;
    rep(i,1,m){
        int u,v; cin>>u>>v;
        adj[u].pb(v); 
        adj[v].pb(u);
    }

    int cnt1=0,cnt2=0,cnt3=0;
    int fl=0;
    rep(i,1,n){
        if(ans[i]==0){
            cnt1++;
            ans[i]=1;
 
            for(auto it:adj[i]){
                ans[it]=2;
                vis[it]++;
            }
        } 
    }
 
    rep(i,1,n){
        if(ans[i]!=1){
            if(vis[i]!=cnt1){
                fl=1;
                cout<<-1<<endl; 
                return;
            }
        }
    }
 
    if(cnt1>=n){
        cout<<-1<<endl;
        return;
    }
 
    rep(i,1,n)
        vis[i]=0;
 
    rep(i,1,n){
        if(ans[i]==2){
            cnt2++; 
            for(auto it:adj[i]){
                if(ans[it] == 2)ans[it]=3;
                vis[it]++;
            }
        } 
    }
 
    if(cnt1+cnt2>=n){
        cout<<-1;
        return;
    }
 
    rep(i,1,n){
        if(ans[i]!=2){
            if(vis[i]!=cnt2){
                cout<<-1<<endl;
                return;
            }
        }
    }
 
    for(int i=1;i<=n;i++){
        if(ans[i] == 3){
            for(auto it:adj[i]){
                if(ans[it]==3){
                    cout<<-1<<endl;
                    return;
                } 
            }
        } 
    }
 
    rep(i,1,n) 
        cout<<ans[i]<<" ";
    cout<<endl;
 
}

signed main() {
    FIO;
    ll T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
} 
 

 
