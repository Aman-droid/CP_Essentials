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
    int n;cin>>n;
    int N=n/3;
    int t=0,m=0;
    string s;cin>>s;
    int fl=0;
    int cnt1[n+2]={0},cnt2[n+2]={0};

    rep(i,1,n){
        if(s[i-1]=='T'){
            t++;
            cnt1[i]=1+cnt1[i-1];
        }
        else{
            m++;
            cnt1[i]=cnt1[i-1];
        }
    }
    for(int i=n;i>=1;i--){
        if(s[i-1]=='T'){
            cnt2[i]=1+cnt2[i+1];
        }
        else{
            cnt2[i]=cnt2[i+1];
        }
    }

    if(m!=N){
        cout<<"NO"<<endl;
        return;
    }
    else{
        int M=0;
        rep(i,1,n){
            if(s[i-1]=='M')M++;
            if(cnt1[i]<M){
                fl=1;
                break;
            }
        }
        M=0;
        for(int i=n;i>=1;i--){
            if(s[i-1]=='M')M++;
            if(cnt2[i]<M){
                fl=1;
                break;
            }
        }
    }

    if(fl==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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