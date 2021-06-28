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
    int n,l,r,s,dif=0,mn,mx,tmp;cin>>n>>l>>r>>s;
    int N = r -l  + 1;
    int x = N-1; 
    mn = (N*(N+1))/2;
    mx = (N*n)-(x*(x+1)/2);
    set<int>s1,s2;
    dif=s-(N*(N+1)/2);
    int dmx = n-N;
    int val;
    
    //watch2(mn,mx);
    if(s>=mn && s<=mx){
        rep(i,1,n){
            s1.insert(i);
        }
        for(int i=N;i>=1;i--){
            tmp=min(dmx,dif);
            val=i+tmp;
            dif=dif-tmp;
            s1.erase(val);
            s2.insert(val);
        }
        rep(i,1,n){
            if(i<l || i>r){
                auto it=s1.begin();
                cout<<*it<<" ";
                s1.erase(it);
            }
            else{
                auto it=s2.begin();
                cout<<*it<<" ";
                s2.erase(it);
            }
        } 
        cout<<endl;   
    }
    else{
       cout<<"-1"<<endl; 
    }

}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}