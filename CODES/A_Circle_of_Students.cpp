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
        int n,m,u,v;cin>>n;
        int a[n];
        int p1=-1,p2=-1;
        rep(i,0,n-1){
            cin>>a[i];
            if(a[i]==1)p1=i;
            else if(a[i]==n)p2=i;
        }
        int fl1=0;
        int fl2=0;
        rep(i,1,n-1){
            if(a[(p1+i)%n]!=i+1)
                fl1=1;
        }
        rep(i,1,n-1){
            if(a[(p2+i)%n]!=n-i)
                fl2=1;
        }
        if(fl1==0 ||fl2==0)
            cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;   
}