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
    string a="",b="";
    string s;cin>>s;
    int fl=0;
    rep(i,0,n-1){
        if(s[i]=='0'){
            a+='0';
            b+='0';
        }
        else if(s[i]=='1'){
            if(fl==0){
                a+='1';
                b+='0';
                fl=1;
            }
            else{
                a+='0';
                b+='1';
            }
        }
        else{
            if(fl==0){
                a+='1';
                b+='1';
            }
            else{
                a+='0';
                b+='2';
            }
        }
    }
    cout<<a<<endl;
    cout<<b<<endl;

}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}