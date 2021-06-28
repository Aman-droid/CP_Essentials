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

void solve(int T){
    int n;cin>>n;
    string a,b;cin>>a;
    int pos[n];
    rep(i,0,n-1){
        pos[i]=-1;
    }
    b=a;
    sort(all(b));
    cout<<b<<endl;
    ren(i,n-1,0){
        char c=b[i];
        for(int j=n;j>=0;j--){
            if(a[j]==c  && pos[j]==-1){
                pos[j]=i;
                break;
            }
        }
    }
    rep(i,0,n-1){
        cout<<pos[i]<<" ";
    }
    cout<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
    return 0;   
}
