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
    ll res=1LL;
    rep(i,1,b){
        res=res*3LL;
    }
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

void solve(){
    int N,n,tmp,pw;cin>>N;
    n=N;
    int a[45]={0};

    for(int i=0;i<=38;i++){
        a[i]=n%3;
        n=n/3;
        if(n==0)break;
    }

    int pos=-1;

    rep(i,0,38){
        //cout<<a[i]<<" ";
        if(a[i]==2){
            pos=i;
        }
    }

    if(pos==-1){
        cout<<N<<endl;
        return;
    }

    int i = pos+1;

    while(i<=41){
        if(a[i]==0){
            pos=i;
            a[i]=1;
            break;
        }
        i++;
    }

    int ans=0;
    rep(i,pos,39){
        if(a[i]==1){
            ans+=power(3LL,i);
        }
    }
    cout<<ans<<endl;  

}


signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}