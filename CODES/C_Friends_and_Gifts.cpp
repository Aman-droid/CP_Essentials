#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
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
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        int n,m,u,v;cin>>n;
        int a[n+1];
        set<int>st;
        vector<int>vis(n+1,0);
        rep(i,1,n){
            cin>>a[i];
            if(a[i]!=0)vis[a[i]]=1;
        }
        rep(i,1,n){
            if(vis[i]==0)st.insert(i);
        }
        rep(i,1,n){
            if(a[i]==0 && st.count(i)){
                auto id=st.upper_bound(i);
                if(id!=st.end()){
                    a[i]=*id;
                    st.erase(id);
                }
                else{
                    a[i]=*st.begin();
                    st.erase(st.begin());
                }
            }
        }
        rep(i,1,n){
            if(a[i]==0){
                auto id=st.upper_bound(i);
                if(id!=st.end()){
                    a[i]=*id;
                    st.erase(id);
                }
                else{
                    a[i]=*st.begin();
                    st.erase(st.begin());
                }
            }
        }
        rep(i,1,n)cout<<a[i]<<" ";
    }
    return 0;   
}