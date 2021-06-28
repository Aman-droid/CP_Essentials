#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pdouble pair<double,double>
#define pii pair<double,double>
#define vpdouble vector<pdouble>
#define SZ(x) ((double)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
//--------------------------------------------------------------------------------------------------------//
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        int n,l,x;cin>>n>>l;
        double a[n];
        rep(i,0,n-1){cin>>a[i];}
        sort(a,a+n);
        double dif=-1;
        rep(i,1,n-1){dif=max(a[i]-a[i-1],dif);}
        dif=dif/2;
        double x1,x2;
        x1=a[0]-0;
        x2=l-a[n-1];
        double ans=max({dif,x1,x2});
        cout<<fixed<<setprecision(10);
        cout<<ans<<endl;
    }
    return 0;   
}