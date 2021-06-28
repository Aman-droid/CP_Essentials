/// https://www.spoj.com/problems/DQUERY/
//No of unique elements in the given range because using sqrt decomp./segment tree 
//cant store set at the particular index 
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
#define INF 1000000000
#define endl '\n'
using namespace std;
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;


#define BLOCK 555
struct query{
	int l;
	int r;
	int i;
};
query Q[200001];
int ar[30001] , ans[200001];
int fre[1000001];
int cnt = 0;
 
//comp ==>firstly according to Block number then according to R value 
bool comp(query a , query b){
	if(a.l / BLOCK != b.l/BLOCK)
	return a.l/BLOCK < b.l/BLOCK;
 
	return a.r < b.r;
}
 
void add(int pos)
{
	fre[ar[pos]]++;
	if(fre[ar[pos]] == 1)
	cnt++;
}
 
void remove(int pos)
{
	fre[ar[pos]]--;
	if(fre[ar[pos]] == 0)
	cnt--;
}
 
int main()
{
	FIO;
	int n , q;	cin>>n;
	for(int i=0;i<n;i++)cin>>ar[i];
	cin>>q;

	for(int i=0;i<q;i++){
		cin>>Q[i].l>>Q[i].r;
		Q[i].i = i , Q[i].l-- , Q[i].r--;
	}
 
	sort(Q , Q+q , comp);
 
	//why ML = 0 , and MR = -1?
	int ML = 0 , MR = -1;
	for(int i=0;i<q;i++)
	{
		int L = Q[i].l;
		int R = Q[i].r;
 
        //Extending Range:-
		while(ML > L)ML-- , add(ML);
        while(MR < R)MR++ , add(MR);

        //Reducing Range:-
		while(ML < L)remove(ML) , ML++;
        while(MR > R)remove(MR) , MR--;
 
		ans[Q[i].i] = cnt;
	}
 
	for(int i=0;i<q;i++)
	cout<<ans[i]<<'\n';
}