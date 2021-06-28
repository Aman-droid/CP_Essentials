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
    int n,x ;cin>>n;
    int a[2][n];
    string s1,s2;
    cin>>s1>>s2;
    rep(i,0,n-1){
        x= s1[i]-'0';
        if(x<=2){
            a[0][i]=0;
        }
        else{
            a[0][i]=1;
        }
    }
    rep(i,0,n-1){
        x= s2[i]-'0';
        if(x<=2){
            a[1][i]=0;
        }
        else{
            a[1][i]=1;
        }
    }
    int fl=0;
    int cnt=0;
    int p=0;
   

    if(a[0][0]==0){
        p=0;
    }
    else{
        if(a[0][0]!=a[1][0]){
            fl=1;
        }
        else{
            p=1;
        }
    }
    //cout<<" p "<<p<<endl;
    //cout<<" fl "<<fl<<endl;

    if(fl==0){
        rep(i,1,n-1){
            if(a[0][i]==a[1][i] && a[0][i]==1){
                p=p^1;
            }
            else if(a[p][i]==0){
                continue;
            }
            else{
                fl=1;
                break;
            }
           // cout<<" p "<<p<<endl;
            //cout<<" i "<<i<<endl;

        }
    }
    if(fl==1 || p==0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
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