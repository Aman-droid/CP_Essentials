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
#define ff           first
#define ss           second
#define prec(n)      fixed<<setprecision(n)
#define mod          1000000007
#define INF          (ll)(1e18)
#define all(c)       (c).begin(),(c).end()


ll power(ll x,ll y){ ll res=1;
    while(y>0){if(y%2==1)res=(res*x)%mod;y=y/2;x=(x*x)%mod;}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//delete element(x) =>  s.erase(s.find_by_order(s.order_of_key(x)));
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

const ll mxn=2e5;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
       
}

signed main() {
    FIO;
    ll T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}