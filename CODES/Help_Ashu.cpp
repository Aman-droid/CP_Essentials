// #include<bits/stdc++.h>
// #define REP(i,n) for (ll i = 1; i <= n; i++)
// #define mod 1000000007
// #define pb push_back
// #define ff first
// #define ss second
// #define ii pair<ll,ll>
// #define vi vector<ll>
// #define vii vector<ii>
// #define lli long long ll
// #define INF 1000000000
// #define endl '\n'
// const double PI = 3.141592653589793238460;
 
// using namespace std;
// ll st[400001] , arr[100001];
 
// void build(ll si , ll ss , ll se)
// {
// 	if(ss == se)
// 	{
// 		st[si] = arr[ss];
// 		return;
// 	}
 
// 	ll mid = (ss + se)/2;
// 	build(2*si , ss , mid);
// 	build(2*si+1 , mid+1 , se);
 
// 	st[si] = min(st[2*si] , st[2*si+1]);
// }
 
// ll query(ll si , ll ss , ll se , ll qs , ll qe)
// {
// 	if(qe < ss || qs> se)
// 		return INF;
 
// 	if(ss>=qs && se<=qe)
// 		return st[si];
 
// 	ll mid = (ss + se)/2;
// 	ll l = query(2*si , ss , mid , qs , qe);
// 	ll r = query(2*si+1 , mid+1 , se , qs , qe);
 
// 	return min(l , r);
// }
// ll main()
// {
// 	ll n , q , l , r;
 
// 	cin>>n;
// 	REP(i , n)
// 		cin>>arr[i];
 
// 	cin>>q;
// 	build(1 , 1 , n);
// 	while(q--)
// 	{
// 		cin>>l>>r;
// 		cout<<query(1 , 1 , n , l+1 , r+1)<<endl;
// 	}
// }
#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define vpll vector<pll>
#define SZ(x) ((ll)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
ll power(ll a, ll b){//a^b
ll res=1;
a=a%mod;
while(b>0){
	if(b&1){res=(res*a)%mod;b--;}
	a=(a*a)%mod;
	b>>=1;
}
	return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//--------------------------------------------------------------------------------------------------------//

const ll mxn=1e5+2;
ll t[4*mxn];
void build(ll a[], ll v, ll tl, ll tr) {  //v=seg. tree index
    if (tl == tr) {
        if(a[tl]%2==1)
            t[v]=1;
        else
            t[v]=0;
    } 
    else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))+ sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(ll a[],ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        if(new_val%2==1){
            t[v]=1;
            a[tl]=new_val;
        }
        else{
            t[v]=0;
            a[tl]=new_val;
        }
    } 
    else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)update(a,v*2, tl, tm, pos, new_val);
        else update(a,v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int main() {
	FIO;
	ll T=1;//cin>>T;
	while (T--){
		ll n,q,m,x,y,tmp;cin>>n;
		ll a[n+1];
		rep(i,1,n){cin>>a[i];}
        cin>>q;
        build(a,1,1,n);
        while(q--){
            cin>>tmp;
            if(tmp==0){
               cin>>x>>y;
               if((a[x]%2)==(y%2))continue;
               update(a,1,1,n,x,y); 
            }
            else if(tmp==1){  //even
                cin>>x>>y;
                ll ans=sum(1,1,n,x,y);
                //watch(ans);
                ans=(y-x+1)-ans;
                cout<<ans<<endl;
                
            }
            else{           //odd
                cin>>x>>y;
                ll ans=sum(1,1,n,x,y);
                cout<<ans<<endl;
                
            }
            
        }


	}
	return 0;   
}