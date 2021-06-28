#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vll vector<pll>
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

int main(){
    FIO;
    int T;cin>>T;
    while(T--){
        ll n,q;cin>>n>>q;
        vector<ll> a(n);
        unordered_map<ll,ll> mp;
        rep(i,0,n-1){
            cin>>a[i];
            mp[a[i]]=i;
        }
        vector<ll> b=a;
        sort(b.begin(),b.end());
        while(q--){
            //swaps==no of incorrect position while doing binary search
            ll x;cin>>x;
            bool flag=true;
            ll l=0,r=n-1;
            //wrongly placed x is with respect to mid
            int big,small;
            int pos=lower_bound(b.begin(),b.end(),x)-b.begin();
            small=pos;
            big=n-pos-1;
            int cnt1=0,cnt2=0;
            while(l<=r){
                ll mid=(l+r)/2;
                ll idx=mp[x];
                if(a[mid]==x)
                    break;
                else if(idx<mid){
                    if(big>0 && a[mid]>x)
                        big--;//correct
                    else if(big>0){
                        big--;//for swap
                        cnt1++;
                    }
                    else{
                        flag=false;  //not present
                        break;
                    }
                    r=mid-1;
                }
                else{
                    if(small>0 && a[mid]<x)
                        small--;//correct
                    else if(small>0){
                        small--;
                        cnt2++;
                    }
                    else{
                        flag=false;//no small present
                        break;
                    }
                    l=mid+1;
                }
            }
        //no of elements needed to be smaller than x
        if(!flag)
            cout<<-1<<"\n";
        else
            cout<<max(cnt1,cnt2)<<"\n";}
        
    }
}
