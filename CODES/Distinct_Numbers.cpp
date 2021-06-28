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
signed main() {
    FIO;
    int n,x;cin>>n;
    set<int >s;
    rep(i,0,n-1){
        cin>>x;
        s.insert(x);
    }
    cout<<SZ(s)<<endl;
    return 0;   
}