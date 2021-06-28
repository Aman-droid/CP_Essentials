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
int d[105];

int mel(int a[],int l,int r){
    if(l==r)return l;
    int p =-1;
    int mx=-1;
    rep(i,l,r){
        if(a[i]>mx){
            mx=a[i];
            p=i;
        }
    }
    return p;
}
void solve(int a[],int l,int r,int ml,int mr, int c){
    if(l<ml || r>mr||l>r)return;

    else if(l==r){
        d[l] = c;

    }
    else{
        int k=mel(a,l,r);
        //watch(k);
        //watch2(l,r);
        d[k]=c;
        c++;
        solve(a,ml,k-1,ml,k-1,c);
        solve(a,k+1,mr,k+1,mr,c);
    }
}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        int n,m,x;cin>>n;
        int a[n+1];
        rep(i,1,n){
            cin>>a[i];
            d[i]=0;
        }
        solve(a,1,n,1,n,0);
        rep(i,1,n){
           cout<<d[i]<<" "; 
        }
        cout<<endl;
    }
    return 0;   
}