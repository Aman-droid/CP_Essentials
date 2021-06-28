#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()
using namespace std;

const int mxn=2e5;

void solve(){
    string a,b;cin>>a>>b;
    int n = SZ(a);
    int m = SZ(b);
    if(n!=m){cout<<"NO"<<endl;return;}
    else if(n==1){
        if(a[0]==b[0])
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
        return;
    }
    else if(a==b)cout<<"YES"<<endl;
    else{
        int fl1=0,fl2=0;
        rep(i,0,n-1){
            if(a[i]=='1')fl1=1;
            if(b[i]=='1')fl2=1;
        }
        if(fl1 && fl2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
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