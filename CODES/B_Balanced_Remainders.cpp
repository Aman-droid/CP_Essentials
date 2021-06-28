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
signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        int n,m,x;cin>>n;
        int c[3]={};
        int ans=0;
        rep(i,0,n-1){
            cin>>x;
            c[x%3]++;
        }
        int k=n/3;
        while(1){
            if(c[0]==c[1] && c[1]==c[2]){
                cout<<ans<<endl;
                   break;
            }
            if(c[0]>k){
                c[1]+=(c[0]-k);
                ans+=(c[0]-k);
                c[0]=k;
            }
            if(c[1]>k){
                c[2]+=(c[1]-k);
                ans+=(c[1]-k);
                c[1]=k;   
            }
            if(c[2]>k){
                c[0]+=(c[2]-k);
                ans+=(c[2]-k);
                c[2]=k;   
            }
        }

    }
    return 0;   
}
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define MOD 1000000007
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);  
#define all(x) x.begin(),x.end()
//*s.find_by_order(p)   returns the value of pth largest starting from 0 
//s.order_of_key(p)   returns no. of items that are strictly < p 
//s.erase(s.upper_bound(p))  p is value and delete only one occurance of p
//string bin = bitset<64>(m).to_string();     convert decimal m to binary ..... continue