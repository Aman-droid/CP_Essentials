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
    int n,m;cin>>n>>m;
    string s;cin>>s;
    string t;cin>>t;
    int ans=0;

    int left[m];
    int right[m];

    int j=0;
    for(int i=0;i<n && j<m;i++){
        if(s[i] == t[j]){
            left[j]=i;
            j++;
        }
    }

    j=m-1;
    for(int i=n-1;i>=0 && j>=0;i--){
        if(s[i]==t[j]){
            right[j]=i;
            j--;
        }
    }

    for(int i=0;i<m-1;i++)
        ans=max(ans,right[i+1]-left[i]);

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