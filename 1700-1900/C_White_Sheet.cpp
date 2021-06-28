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
bool out(int x,int y,int x1,int y1,int x2,int y2){
    if(x<x1 || x>x2 || y<y1 || y>y2){
        return true;
    }
    else{
        return false;
    }
}
void solve(){
    int x1,x2,x3,x4,x5,x6;
    int y1,y2,y3,y4,y5,y6;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    cin>>x5>>y5>>x6>>y6;
    x1 =x1*2;y1=y1*2;
    x2 =x2*2;y2=y2*2;
    x3 =x3*2;y3=y3*2;
    x4 =x4*2;y4=y4*2;
    x5 =x5*2;y5=y5*2;
    x6 =x6*2;y6=y6*2;

    for(int x=x1;x<=x2;x++){
        if(out(x,y1,x3,y3,x4,y4) && out(x,y1,x5,y5,x6,y6)){
            cout<<"YES"<<endl;
            return;
        }
        if(out(x,y2,x3,y3,x4,y4) && out(x,y2,x5,y5,x6,y6)){
            cout<<"YES"<<endl;
            return;
        }
    }
    //watch2(x1,x2);
    for(int y=y1;y<=y2;y++){
        if(out(x1,y,x3,y3,x4,y4) && out(x1,y,x5,y5,x6,y6)){
            cout<<"YES"<<endl;
            return;
        }
        if(out(x2,y,x3,y3,x4,y4) && out(x2,y,x5,y5,x6,y6)){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;

}
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}