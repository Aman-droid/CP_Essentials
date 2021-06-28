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
#define mod           998244353
#define INF (ll)      (1e18)
#define all(c)        (c).begin(),(c).end()

using namespace std;

ll power(ll a, ll b){ ll res=1; a=a%mod; while(b>0){ if(b&1){
    res=(res*a)%mod;b--;} a=(a*a)%mod;b>>=1;} return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

const int mxn=2e5+5;
int inv(int a){
return power(a,mod-2);
}

int fact[mxn];
int inr[mxn];

void pre(){
    fact[0]=1;
    for(int i=1;i<mxn;i++)fact[i]=(fact[i-1]*i)%mod;
    inr[0]=1;
    for(int i=1;i<mxn;i++)inr[i]=inv(fact[i]);
}

int ncr(int n,int r){
    int a=(fact[n]*inr[r])%mod;
    int b=(a*inr[n-r])%mod;
    return b;
}

void solve(int T){
    int n,m;cin>>n>>m;
    if(m<n-1 || n==2 ){
        cout<<"0"<<endl;
        return;
    }

    int com = ncr(m,n-1LL); //take n-1 from m
    //watch(com);
    com=(com*(n-2))%mod;
    //max //two equal //rem = n-3
    com=(com*power(2LL,n-3))%mod;      //except max all can repeat
    //watch(com);
    cout<<com<<endl;

}

signed main() {
    FIO;
    pre();
    int T=1;//cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
    return 0;   
}



