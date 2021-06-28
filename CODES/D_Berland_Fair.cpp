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
//-------------------soln-----------------------------//

const int mxn=2e5;
int ans=0,sum=0,cnt=0;;
int n,x,T;

void func(int a[] ){
    int tmp=T;
    sum=0;
    cnt=0;
    rep(i,0,n-1){
        if(tmp>=a[i]){
            tmp=tmp-a[i];
            sum+=a[i];
            cnt++;
        }
    }
}

void solve(){
    cin>>n>>T;
    int a[n];
    int cur;
    rep(i,0,n-1){
        cin>>a[i];
    }
    int ans=0;
    while(T>0){
        func(a);
        if(cnt==0)break;
        ans+=cnt*(T/sum);
        T= T%sum; 
    }
    cout<<ans<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}