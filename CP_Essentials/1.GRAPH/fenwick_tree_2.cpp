/*
#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std; 
  
const int MAX_VAL = 1000009; 
  
void update(int i, int add, vector<int>& BIT) 
{ 
    while (i > 0 && i < BIT.size()) 
    { 
        BIT[i] += add; 
        i = i + (i & (-i)); 
    } 
} 
  
int sum(int i, vector<int>& BIT) 
{ 
    int ans = 0; 
    while (i > 0) 
    { 
        ans += BIT[i]; 
        i = i - (i & (-i)); 
    }   
    return ans; 
} 
  
int findKthSmallest(int k, vector<int> &BIT) 
{ 
    int l = 0; 
    int h = BIT.size(); 
    while (l < h) 
    { 
        int mid = (l + h) / 2; 
        if (k <= sum(mid, BIT)) 
            h = mid; 
        else
            l = mid+1; 
    }   
    return l; 
} 
 
void insertElement(int x, vector<int> &BIT) 
{ 
    update(x, 1, BIT); 
} 
 
void deleteElement(int x, vector<int> &BIT) 
{ 
    update(x, -1, BIT); 
} 
  
int findRank(int x, vector<int> &BIT) 
{ 
    return sum(x, BIT); 
} 
  
int main() 
{ 
    fastio;
    vector<int> BIT(MAX_VAL); 
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	int x;
    	cin>>x;
    	insertElement(x,BIT);
	}
	
	for(int i=0;i<q;i++)
	{
		int aa;
		cin>>aa;
		if(aa<0)
		{
			aa=abs(aa);
			int val=findKthSmallest(aa,BIT);
			deleteElement(val,BIT);
		}
		else insertElement(aa,BIT);
	}
    int num=findKthSmallest(1,BIT);
    if(num<=n)
    cout<<num<<endl;
    else cout<<"0"<<endl;
    return 0; 
} 


*/

//----------------------------------------------------------------
//-----https://codeforces.com/blog/entry/61364----------//
//HACKEREARTH  use this one
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
//-------------------soln-----------------------------//
//------point update and range query-----------------//

const int mxn=2e5;
int BIT[mxn], a[mxn], n;

//add "delta" at index "x"

void update(int x, int delta)       
{
    for(; x <= n; x += x&-x)
          BIT[x] += delta;
}

//returns the sum of first x elements in given array a[]
int query(int x)      
{
    int sum = 0;
    for(; x > 0; x -= x&-x)
        sum += BIT[x];
    return sum;
}



////lower bound on prefix ;;return index of prefix sum>=pr
// int binary_search(int v) // v is the value we are searching
// {
// 	int l = 1, r = n;
//     int res = 0;
// 	while(l <= r){
// 		int mid = (l+r) / 2;
// 		if(query(mid) <= v){
// 			l = mid+1;
//             res = mid;    //change this accordingly..
//         }
// 		else{
// 			r = mid-1;
//         }
// 	}
// 	return res;
// }

// int binary_search(long long prefSum){
//     int num = 0;
//     long long sum = 0;
//     for(int i = 21; i>=0 ; --i){
//         if((num + (1<<i) <= n) && (sum + BIT[num + (1<<i)] <= prefSum)){
//             num += (1<<i);
//             sum += BIT[num];
//         }
//     }
//     return num ;
// }

void solve(){    
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        update(i, a[i]); //add value a[i] at the index i initially BIT[i] = 0
    }
    cout<<"sum of first 10 elements is   " <<query(10)<<endl;
    cout<<"sum of all elements in range [2, 7] is" <<query(7)-query(2-1)<<endl;;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}


//range update and range queries

// def add(b, idx, x):
//     while idx <= N:
//         b[idx] += x
//         idx += idx & -idx

// def range_add(l,r,x):
//     add(B1, l, x)
//     add(B1, r+1, -x)
//     add(B2, l, x*(l-1))
//     add(B2, r+1, -x*r)

// def sum(b, idx):
//     total = 0
//     while idx > 0:
//         total += b[idx]
//         idx -= idx & -idx
//     return total

// def prefix_sum(idx):
//     return sum(B1, idx)*idx -  sum(B2, idx)

// def range_sum(l, r):
//     return prefix_sum(r) - prefix_sum(l-1)



/*

#include <bits/stdc++.h>
using namespace std;
int getSum(int BITree[], int i){
   int sum = 0;
   i++;
   while (i>0) {
      sum += BITree[i];
      i -= i & (-i);
   }
   return sum;
}
void updateBITree(int BITree[], int n, int i, int val) {
   i = i + 1;
   while (i <= n) {
      BITree[i] += val;
      i += i & (-i);
   }
}
void update(int BITTree1[], int BITTree2[], int n, int l, int r, int value) {
   updateBITree(BITTree1,n,l,value);
   updateBITree(BITTree1,n,r+1,-value);
   updateBITree(BITTree2,n,l,value*(l-1));
   updateBITree(BITTree2,n,r+1,-value*r);
}
int sum(int x, int BITTree1[], int BITTree2[]) {
   return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}
int getRangeSum(int l, int r, int BITTree1[], int BITTree2[]) {
   return sum(r, BITTree1, BITTree2) - sum(l-1, BITTree1, BITTree2);
}
int *createBITree(int n) {
   int *BITree = new int[n+1];
   for (int i=1; i<=n; i++)
   BITree[i] = 0;
   return BITree;
}
int main(){
   int n = 7;
   int *BITTree1, *BITTree2;
   BITTree1 = createBITree(n);
   BITTree2 = createBITree(n);
   update(BITTree1,BITTree2,n,3,6,9);
   update(BITTree1,BITTree2,n, 0, 4, 5);
   cout<<"The output of sum query after applying all update queries is \t"      <<getRangeSum(1,5,BITTree1,BITTree2);
   return 0;
}
*/