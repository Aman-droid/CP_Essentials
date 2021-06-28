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

const int mxn=2e5+10;

int par[mxn];
int R[mxn]; // Rank no of node connected to current par..

int find(int v)  {
    if(par[v]==-1)
        return v;
    else{
        int x = find(par[v]);
        par[v] = x;
        return x;
    }
}

//Union by rank node having larger number of childs will be parent 
bool merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)return false;

    if(R[a]>R[b]){	//a will be parent 
        par[b]=a;
        R[a]+=R[b];
    }
    else {	//b will be parent 
        par[a]=b;
        R[b]+=R[a];
    }
    return true;
} 

signed main(){
    int n,m,u,v,w ;cin>>n>>m; 
    vector<vector<int>>edges;//cost ,u,v
    
    vector<int> a(n);
    int ans=0; 
    rep(i,0,n-1)cin>>a[i];

    //initializing
    for(int i=0;i<n;i++){
        par[i] = -1;
        R[i] =1;
    }
    rep(i,0,m-1){
        cin>>u>>v>>w;
        u--;
        v--;
        edges.pb({w,u,v});
    }

    int mn = min_element(a.begin(),a.end())-a.begin();

    rep(i,0,n-1){
        if(i == mn)continue;
        else{
            edges.pb({a[i]+a[mn],mn,i});
        }
    }
    sort(all(edges));
    int cost=0;
    for(auto it:edges){
        cost=it[0];
        u =it[1];
        v =it[2];
        if(merge(u,v)){
            ans+=cost;
        }
    }
    cout<<ans<<endl;
}
