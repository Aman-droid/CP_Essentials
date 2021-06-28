#include<bits/stdc++.h>
#define ll long long 
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
const int mxn=1e5+2;
int t[4*mxn] , arr[mxn];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } 
    else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm); //left 
        build(a, v*2+1, tm+1, tr); //right
        t[v] = min(t[v*2] , t[v*2+1]);
    }
}
 
// int query(int si , int ss , int se , int qs , int qe)
// {
// 	if(qe < ss || qs> se) // completely outside
// 		return INF;
 
// 	if(ss>=qs && se<=qe) // completely inside
// 		return st[si];
 
// 	int mid = (ss + se)/2;
// 	int l = query(2*si , ss , mid , qs , qe);
// 	int r = query(2*si+1 , mid+1 , se , qs , qe);
 
// 	return min(l , r);
// }
int query(int v, int tl, int tr, int l, int r) {
    //watch(v);
    //watch2(l,r);
    //watch2(tl,tr);
    if (l > r) 
        return mod;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)),query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
int main()
{
	int n , q , l , r;
	cin>>n;
    int a[n+1];
	rep(i,1,n)
		cin>>a[i];
 
	cin>>q;
	build(a,1 , 1 , n);
	while(q--)
	{
		cin>>l>>r;
		cout<<query(1 , 1 , n , l+1 , r+1)<<endl;
	}
}