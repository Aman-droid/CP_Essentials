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

const int mxn=200;
int cnt[mxn];

void get(int n,int k){
    int j=0;
    while(n>0){
        int tmp=n%k;
        cnt[j]+=tmp;
        n=n/k;
        j++;
    }
}
void solve(int T){
    int n,k;cin>>n>>k;
    int a[n];
    rep(i,0,100){
        cnt[i]=0;
    }
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        get(a[i],k);
    }

    rep(i,0,100){
        if(cnt[i]>1){
            cout<<"NO"<<endl;
            return; 
        }
    }
    cout<<"YES"<<endl;


}

signed main() {
    FIO;
    int T=1;cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
    return 0;   
}