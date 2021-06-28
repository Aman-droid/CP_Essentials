#include<bits/stdc++.h>
#define ll            long long
#define int           long long 
#define endl          '\n'
#define rep(i,a,b)    for(int i=a;i<=b;i++)
#define ren(i,a,b)    for(int i=a;i>=b;i--)
#define pii           pair<int,int>
#define SZ(x)         ((int)x.size())
#define FIO           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)      cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)   cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb            push_back
#define ff            first
#define ss            second
#define mod           1000000007
#define INF (ll)      (1e18)
#define all(c)        (c).begin(),(c).end()

using namespace std;

ll power(ll a, ll b){ ll res=1; a=a%mod; while(b>0){ if(b&1){
    res=(res*a)%mod;b--;} a=(a*a)%mod;b>>=1;} return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

const int mxn=2e5;

vector<vector<int>> adj;
set<int> s1,s2;
vector<int> vis;
 
int dfs(int x){
    if(s1.count(x))
        return x;

    vis[x]=1;
    for(int child:adj[x]){
        if(!vis[child]){
            int z=dfs(child);
            if(z!=-1)
                return z;
        }
    }
    return -1;
}

void solve(int T){
    int n;cin>>n;
    int k1,k2,x;

    adj.clear();
    vis.clear();
    adj.resize(n+1);
    vis.resize(n+1);
    
    rep(i,1,n-1){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    cin>>k1;
    vector<int> v1(k1);
    rep(i,0,k1-1){
        cin>>v1[i];
        s1.insert(v1[i]);
    }

    cin>>k2;
    vector<int> v2(k2);
    rep(i,0,k2-1){
        cin>>v2[i];
        s2.insert(v2[i]);
    }

    cout<<"B "<<v2[0]<<endl;
    cin>>x;

    int y = dfs(x);

    cout<<"A "<<y<<endl;
    cin>>x;

    if(s2.count(x))
        cout<<"C "<<y<<endl;
    else
        cout<<"C -1"<<endl;
}

 
 
signed main() {
    //FIO;
    int T=1;cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
    return 0;   
}