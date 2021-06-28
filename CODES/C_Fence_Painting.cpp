#include<bits/stdc++.h>
#define ll long long 
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
//--------------------------------------------------------------------------------------------------------//
const int mxn=2e5;
vector<int>adj[mxn];
signed main() {
    //FIO;
    int T=1;cin>>T;
    while (T--){
        int n,m,x;cin>>n>>m;
        unordered_map<int,int>cnt;
        int a[n+1],b[n+1],c[m+1];
        rep(i,1,n)adj[i].clear();
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=m;i++)cin>>c[i];  
        rep(i,1,n){
            if(a[i]!=b[i]){
                adj[b[i]].pb(i);
            }
            else{
                cnt[b[i]]=i;
            }    
        }
        // //watch2(n,m);
        int fl=0;
        int pos=-1;
        int p;
        vector<pair<int,int>>res;
        for(int i=m;i>=1;i--){
            if(adj[c[i]].size() > 0){
                p=SZ(adj[c[i]])-1;
                int tmp=adj[c[i]][p];
                res.pb({i,tmp});
                adj[c[i]].pop_back();
                pos=tmp;
            }
            else if(pos==-1){
                if(cnt.count(c[i])==0){
                    fl=1;
                    break;
                }
                else{
                    res.pb({i,cnt[c[i]]});
                }
            }
            else if(pos!=-1){
                res.pb({i,pos});
            }
        }
        //watch(SZ(res));
        rep(i,1,n){
            if(SZ(adj[i])!=0)fl=1;
        }
        if(fl==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            for(int i=m-1;i>=0;i--){
                cout<<res[i].ss<<" ";
            }
            cout<<endl;
        }       
    }
    return 0;   
}