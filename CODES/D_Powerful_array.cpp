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
const int BLOCK=500;
int fre[1000005] , ar[200005];
ll ans[200005];
ll power = 0;

struct query{
	int l;
	int r;
	int i;
};
query Q[200001];
 
bool comp(query a , query b){

	if(a.l/BLOCK != b.l / BLOCK)
	return a.l/BLOCK < b.l/BLOCK;
 
	return a.r < b.r;
}
 
void add(int pos)
{
	ll cnt = fre[ar[pos]]; //current freuency 
	fre[ar[pos]]++; 
 
	power -= (cnt * cnt) * ar[pos] ;
    cnt++;
	power += (cnt * cnt) * ar[pos];
}
 
void remove(int pos)
{
	ll cnt = fre[ar[pos]];
	fre[ar[pos]]--;
 
	power -= (cnt * cnt) * ar[pos] , cnt--;
	power += (cnt * cnt) * ar[pos];
}
 
int main()
{
	int n , q;
	cin>>n>>q;
	rep(i,0,n-1) cin>>ar[i];
	for(int i=0;i<q;i++) {
		cin>>Q[i].l>>Q[i].r;
        Q[i].i = i ;
        Q[i].l-- ; 
        Q[i].r--;
	}
 
	sort(Q , Q+q , comp);
 
	int ML = 0 , MR = -1;
	for(int i=0;i<q;i++)
	{
		int L = Q[i].l;
		int R = Q[i].r;
 
		while(ML > L)ML-- , add(ML);
        while(MR < R)MR++ , add(MR);
 
		while(ML < L)remove(ML) , ML++;
        while(MR > R)remove(MR) , MR--;
 
		ans[Q[i].i] = power;
	}
 
	rep(i,0,q-1)
	    cout<<ans[i]<<endl;
}