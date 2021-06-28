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
    int n,t;cin>>n>>t;
    int a[n];
    rep(i,0,n-1){
        cin>>a[i];
    }
    sort(a,a+n);
    int res=-1;
    int low=1,high=1e18;
    while(low <= high){
        int mid=(low+high)/2;
        int sum=0;
        //cout<<low<<" "<<high<<" "<<mid<<endl;
        rep(i,0,n-1){
            sum += min(mid/a[i],(int)1e9);
        }
        if(sum == t){
            res = mid;
            high = mid-1;
        }
        else if(sum < t){
            low = mid+1;
        }
        else{
            res=mid;
            high=mid-1;
        }
    }
    cout<<res<<endl;

}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}