#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

using namespace std;
ll power(ll a, ll b){//a^b
ll res=1;
a=a%mod;
while(b>0){
    if(b&1){res=(res*a)%mod;b--;}
    a=(a*a)%mod;
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

const int mxn=2e5;
vector<int>adj[55];
int vis[55]={0};
vector<int>st;

void dfs(int node){
    vis[node]=1;
    st.pb(node);
    for(int child:adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
void solve(){
    int n,m,u,v;cin>>n>>m;
    vector<int>vec;
    vector< pair<pair<int,int>,int> >res;
    int cnt=0;
    int fl=0;
    rep(i,1,m){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    rep(i,1,n){
        if(adj[i].empty()){
            vec.pb(i);
        }
    }

    rep(i,1,n){
        st.clear();
        if(!adj[i].empty() && vis[i]==0){
            dfs(i);
            if(SZ(st)>3){
                fl=1;
                break;
            }
            else if(SZ(st)==3){
                res.pb({{st[0],st[1]},st[2]});
            }
            else if(SZ(st)==2){
                if(vec.empty()){
                    fl=1;
                    break;
                }
                res.pb({{st[0],st[1]},vec.back()});
                vec.pop_back();
            }
        }
    }
    if(fl==0){
        for(auto it:res){
            cout<<it.ff.ff<<" "<<it.ff.ss<<" "<<it.ss<<endl;
        }
        for(int i=0;i<SZ(vec);i=i+3){
            cout<<vec[i]<<" "<<vec[i+1]<<" "<<vec[i+2]<<endl;
        }
    }
    else{
        cout<<"-1"<<endl;
    }
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}