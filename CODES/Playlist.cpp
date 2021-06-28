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
//longest continuous substring of unique characters.....
void solve(){
    int n;cin>>n;
    set<int>s;
    int a[n];
    
    rep(i,0,n-1){
        cin>>a[i];
    }

    int i=0,j=0;
    int ans=1;
    while(j<n){
        if(!s.count(a[j])){  //not in the set ==>insert
            s.insert(a[j]);
        }
        else{                   //belongs to the set==>remove the all before first occurance
            ans=max(ans,j-i);
            while(a[i]!=a[j]){
                s.erase(a[i]);
                i++;
            }
            i++;
        }
        j++;
    }
    
    ans=max(ans,j-i);
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