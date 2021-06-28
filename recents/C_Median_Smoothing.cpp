#include<bits/stdc++.h>
#define ll long long
#define int long long 
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
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

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
//-------------------soln-----------------------------//

const int mxn=2e5;
void solve(){
    int n;cin>>n;
    int a[n+1],pk[n+1]={0};
    
    rep(i,1,n){
        cin>>a[i];
    }

    for(int i=2;i<=n-1;i++){
        if(a[i-1]==a[i+1] && a[i-1]!=a[i]){
            pk[i]=1;
        }
    }
    // watch(n);
    // rep(i,1,n)cout<<pk[i]<<" ";
    // cout<<endl;

    vector<vector<int>>res;
    
    int mx=0;

    rep(i,2,n-1){
        if(pk[i]==1){
            int j=i;
            while(pk[j]==1 && j <= n-1){
                j++;
            }
            j--;
            res.pb({i,j,a[i-1]});
            mx=max(mx,(j-i+1+1)/2);
            i=j;
        }
    }
    cout<<mx<<endl;
    if(mx==0){
        rep(i,1,n)cout<<a[i]<<" ";
        cout<<endl;    
        return;
    }
    int l,r,x,mid;
    for(auto it:res){
        l=it[0];
        r=it[1];
        x=it[2];
        mid=(l+r)/2;

        if((r-l+1)%2==1){
            for(int i=l;i<=r;i++){
                a[i]=x;
            }
        }
        else{
            for(int i=l;i<=r;i++){
                if(i<=mid)a[i]= x;
                else a[i]=  x^1;
            }
        }
    }

    rep(i,1,n){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}