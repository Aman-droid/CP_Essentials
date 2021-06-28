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

    int a[n+1],L[n+2],R[n+2];
    
    int fl=0;
    rep(i,1,n){
        cin>>a[i];
    }

    L[1]=a[1];
    R[n]=a[n];

    rep(i,2,n){
        L[i] = L[i-1]^a[i];
    }

    for(int i=n-1;i>=1;i--){
        R[i] = R[i+1]^a[i];
    }

    if(L[n]==0){
        cout<<"YES"<<endl;
        return;
    }

    rep(i,1,n){
        rep(j,i+1,n-1){
            if(L[i] == (L[j]^L[i])  && L[i] == R[j+1] ){   ///if(L[i] == L[j]^L[i]  && L[i] == R[j+1] ) this one gives WA as [priority ==  > ^ ] in c++ 
               cout<<"YES"<<endl;
                return;
            } 
        }
    }
    cout<<"NO"<<endl;

}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}