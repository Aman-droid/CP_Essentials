/*
union normal find = O(n)
union path compression = O(log(n))
union by rank/size =  O(alpha(n)) alpha is a very small number

space= O(n);
*/

#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define mp make_pair
#define pb push_back
#define pf push_frontal
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
const int mxn=2e5;

int par[mxn];
int R[mxn]; // Rank no of node connected to current par..
int par[mxn];

void make_set(int v) {
    par[v] = v;  //can take v or -1;
}
//FIND function with ******path compression******
//find set in which v belongs
int find(int v)  
{
	if(par[v]==v)
		return v;
	else{
		int x = find(par[v]);
		par[v] = x;
		return x;
	}
}

//UNION:- join two different sets
void Union(int a,int b){
    int a=find(a);
    int b=find(b);
    if(a==b)
        return;
    else 
        par[a]=b; //can decide acc to the ques...
}

//Union by rank node having larger number of childs will be parent 
void merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b)return;
	if(R[a]>R[b]){	//a will be parent 
		par[b]=a;
		R[a]+=R[b];
	}
	else {	//b will be parent 
		par[a]=b;
		R[b]+=R[a];
	}
} 

int main()
{
	int n , m , a , b;
	cin>>n>>m; 
	//initializing
	for(int i=1;i<=n;i++){
		par[i] = -i;
		R[i]=1;
	}
	while(m--){
		cin>>a>>b;
		a = find(a) , b = find(b); 
		if(a != b) Union(a , b);  //merge(a,b); for rank order
	}
}

/*
CYCLE DETECTION

	for all edge u,v{ 
		x= find(u);
		y= find(v);
		if(x==y){
			//same set cycle found
			return true;
		}
		union(a,b);
	}
	return false;



*/