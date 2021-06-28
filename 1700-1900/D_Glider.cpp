// #include<bits/stdc++.h>
// #define ll long long
// #define int long long 
// #define endl '\n'
// #define rep(i,a,b)  for(int i=a;i<=b;i++)
// #define pll pair<ll,ll>
// #define pii pair<int,int>
// #define vpll vector<pll>
// #define SZ(x) ((int)x.size())
// #define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
// #define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
// #define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
// #define pb push_back
// #define pf push_front
// #define ff first
// #define ss second
// #define mod 1000000007
// #define INF (ll)(1e18)
// #define all(c) (c).begin(),(c).end()

// using namespace std;
// ll power(ll a, ll b){//a^b
// ll res=1;
// a=a%mod;
// while(b>0){
//     if(b&1){res=(res*a)%mod;b--;}
//     a=(a*a)%mod;
//     b>>=1;
// }
//     return res;
// }
// ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
// //-------------------soln-----------------------------//

// const int mxn=2e5;

// void solve(){
//     ll n,h,x1,x2;cin>>n>>h;
//     pair<ll,ll> a[n+2];
//     vector<pair<ll,ll>>v;
//     rep(i,0,n-1){
//         cin>>a[i].ff>>a[i].ss;
//     }

//     ll mx=-1;

//     //v.pb({0,a[0].ff+ 1e9});
//     rep(i,0,n-1){
//         mx=max(mx,a[i].ss-a[i].ff);
//         if(i==n-1)
//             v.pb({a[i].ss-a[i].ff ,1e9 - a[i].ss});
//         else
//             v.pb({a[i].ss-a[i].ff ,a[i+1].ff-a[i].ss});
//     }

//     int j=0,i=0;
//     int cur=0,sum=0;
//     int ans=mx+h;

//     while(j<n){
//         //watch(j);
//         //watch2(v[j].ff,v[j].ss);
//         sum+=v[j].ff;
//         cur+=v[j].ss;
//        // watch2(sum,cur);
//         if(cur<h){ 
//             //continue;   
//             //watch2(sum,cur);
//         }
//         else{
//             ans=max(ans,sum+h);
//             //watch(ans);
//             while(cur>=h && i<=j ) {
//                 cur-=v[i].ss;
//                 sum-=v[i].ff;
//                 i++;
//             }
//             ///cout<<"*"<<endl;
//             //watch2(sum,cur);
//             //i++;
//         }
//         j++;
//     }

//     if(cur>=h){
//         ans=max(ans,sum+h);
//     }
//     cout<<ans<<endl;

// }


// signed main() {
//     FIO;
//     int T=1;//cin>>T;
//     while (T--){
//        solve();
//     }
//     return 0;   
// }

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
void solve(){
	int n,h;cin>>n>>h;
    pair<int,int>a[n];

	for(ll i=0;i<n;i++){
        cin>>a[i].ff>>a[i].ss;
    }
	
    int j=0;
    int sum=0,ans=0;

	for(ll i=0;i<n;i++){
		
        while(j<n && (a[j].ff-a[i].ff < sum+h)){
			sum+=(a[j].ss-a[j].ff);
			j++;
		}
		ans=max(ans,sum+h);
		sum-=(a[i].ss-a[i].ff);
	}
    ans=max(ans,sum+h);	
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