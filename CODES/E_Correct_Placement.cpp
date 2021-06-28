#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
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
/*struct edge
{
    ll h;
    ll w;
    ll id;
};

edge arr[1000000];       // array of type edge
ll par[10001];

bool comp(edge a,edge b){
    if(a.h>b.h && a.w >b.w)
        return true ;        //true means a will come before b
    else if(a.h>b.w && a.w > b.h)
        return true;
    else
        return false;       //b will come before a
}

int main()
{
    //FIO;
	ll T=1;cin>>T;
	while(T--)
	{
        ll n,m,a,b,w;cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i].h>>arr[i].w;
            arr[i].id=i+1;
        }
        sort(arr,arr+n,comp);
        int sum=0;
        ll ans[n+1];
        rep(i,1,n)ans[i]=-1;
        rep(i,0,n-2){
            if(arr[i].h>arr[i+1].h && arr[i].w >arr[i+1].w)
            {
                ans[arr[i].id]=arr[i+1].id;//cout<<arr[i+1].id<<" ";
            }
            if(arr[i].h>arr[i+1].w && arr[i].w >arr[i+1].h)
            {
                ans[arr[i].id]=arr[i+1].id;//cout<<arr[i+1].id<<" ";
            }
            else 
                ans[arr[i].id]=-1;
        }
        ans[arr[n-1].id]=-1;
        rep(i,1,n){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}*/
const int N=1e6;
struct edge
{
	ll w;
    ll h; 
    ll idx;
};
 
ll n;
ll ans[N];
edge a[N];
 
bool comp(edge &d1, edge &d2){
	if(d1.h != d2.h)
		return d1.h < d2.h;
	return 
        d1.w < d2.w;
} 
int main()
{
	FIO;
	int T;cin >> T;
	while(T--)
	{
		cin >> n;
        rep(i,1,n){
			cin >> a[i].h >> a[i].w;
			if(a[i].h > a[i].w)
				swap(a[i].h, a[i].w);
			a[i].idx = i;
			ans[i] = -1;
		}
		sort(a + 1, a + n + 1, comp);
		int l = 0, curMin = 2e9, curIdx = -1;
		for(int r = 1; r <= n; r++)
	    {
			while(l + 1 < r && a[l + 1].h < a[r].h)
			{
				l++;
				if(a[l].w < curMin)
				{
					curMin = a[l].w;
					curIdx = a[l].idx;
				}
			}
			if(curMin < a[r].w)
				ans[a[r].idx] = curIdx;
		}
		for(int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
