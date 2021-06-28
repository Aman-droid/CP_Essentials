#include<bits/stdc++.h>
#define ll            long long
#define int           long long 
#define endl          '\n'
#define rep(i,a,b)    for(int i=a;i<=b;i++)
#define ren(i,a,b)    for(int i=a;i>=b;i--)
#define pii           pair<int,int>
#define SZ(x)         ((int)x.size())
#define FIO           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)      cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)   cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb            push_back
#define ff            first
#define ss            second
#define mod           1000000007
#define INF (ll)      (1e18)
#define all(c)        (c).begin(),(c).end()

using namespace std;

ll power(ll a, ll b){ ll res=1; a=a%mod; while(b>0){ if(b&1){
    res=(res*a)%mod;b--;} a=(a*a)%mod;b>>=1;} return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

int query(int low,int high){
    int x;
    if(low==high)return -1;

    cout<<"? "<<low<<" "<<high<<endl;
    cin>>x;
    return x;
}
 
void solve(int T){
    int n;cin>>n;
    int low=1,high=n;

    int pos = query(low,high);
    int x,res=-1;
    //left 
    if(query(1,pos) == pos ){
        low =1;
        high =pos-1;
        while(low<=high){
            int mid=(low+high)/2;
            x = query(mid,pos);
            if( x==pos){
                res = mid;
                low = mid+1;
            }
            else{
                high=mid-1;
            }
        }
        cout<<"! "<<res<<endl;
    }
    else{
        low = pos+1;
        high = n;
        while(low<=high){
            int mid=(low+high)/2;
            x = query(pos,mid);
            if(x == pos){
                res = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        cout<<"! "<<res<<endl;
    }
    
}
signed main() {
    //FIO;
    int T=1;//cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
    return 0;   
}