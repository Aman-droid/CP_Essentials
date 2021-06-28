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
    int T=1;cin>>T;
    while (T--){
        string s;cin>>s;
        int n=s.length();
        int x=-1;
        int fl=0;
        rep(i,0,n-1){
            if(s[i]=='1' && (x==-1 || x==i-1)){
                x=i;
            }
            else if(s[i]=='1'){
                fl=1;
                break;
            }
        }
        if(fl) cout<<"NO"<<endl;
        else if(x==-1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;   
}