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
/*int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll n,k,sum=0;cin>>n>>k;
        ll a[n];rep(i,0,n-1){cin>>a[i];sum+=a[i];}
        sort(a,a+n,greater<ll>());
        if(sum<2*k || n==1){
            cout<<"-1"<<endl;
            continue;
        }
        ll s1=0, s2=0,ans=0;
        vector<int>v1,v2;
        rep(i,0,n-1){
            if(i%2==0){
                if(s1<k){
                    s1+=a[i];
                    v1.pb(a[i]);
                    ans++;
                }
                else if(s2<k){
                    s2+=a[i];
                    v2.pb(a[i]);
                    ans++;
                }
            }
            else{
                if(s2<k){
                    s2+=a[i];
                    v2.pb(a[i]);
                    ans++;
                }
                else if(s1<k){
                    s1+=a[i];
                    v1.pb(a[i]);
                    ans++;
                }
            }   
        }
        /*
        while(n>0){
            int fl=0;
            if(n>0 &&s1<k){
                s1+=a[n-1];
                v1.pb(a[n-1]);
                n--;
                ans++;
                fl=1;
            }
            if(n>0 && s2<k){
                s2+=a[n-1];
                v2.pb(a[n-1]);
                ans++;
                n--;
                fl=1;
            }
            if(fl==0)
                break;
        }*/

        /*if(s1>=k && s2>=k){
            ll l1=SZ(v1),l2=SZ(v2),d;
            sort(v1.begin(),v1.end(),greater<ll>());
            sort(v2.begin(),v2.end(),greater<ll>());
            if(l1>=l2){
                rep(i,0,l1-1){
                    rep(j,0,l2-1){
                        d=abs(v1[i]-v2[j]);
                        //watch(d);
                        if(v2[j]>v1[i] && s2-d>=k && s1+d>=k ){
                            //watch(v2[j]);
                            //watch(v1[i]);
                            swap(v2[j],v1[i]);
                            s1=s1+d;
                            s2=s2-d;
                            break;
                        }
                    }
                }
                //watch(ans);
                sort(v1.begin(),v1.end());
                for(auto it: v1){
                    //cout<<it<<" ";
                    if(s1-it>=k){
                        ans--;
                        s1=s1-it;
                    }
                }
                //cout<<endl;
                cout<<ans<<endl;
            }
            else{
                rep(i,0,l2-1){
                    rep(j,0,l1-1){
                        d=abs(v2[i]-v1[j]);
                        if(v1[j]>v2[i] && s1-d>=k && s2+d>=k ){    
                            swap(v1[j],v2[i]);
                            s2=s2+d;
                            s1=s1-d;
                            break;
                        }
                    }
                }
                sort(v2.begin(),v2.end());
                for(auto it: v2){
                    if(s2-it>=k){
                        ans--;
                        s2=s2-it; 
                    }
                }
                cout<<ans<<endl;
            }
        }
        else 
            cout<<"-1"<<endl;
    }
    return 0;   
}*/


ll isSubsetSum(ll arr[], ll n, ll sum,ll k) 
{      
    bool subset[2][sum + 1]; 
    for (ll  i= 0; i <= n; i++) { 
        for (ll j = 0; j <= sum; j++) {   
            if (j == 0) 
                subset[i % 2][j] = true;  
            else if (i == 0) 
                subset[i % 2][j] = false;  
            else if (arr[i - 1] <= j) 
                subset[i % 2][j] = subset[(i + 1) % 2][j - arr[i - 1]] || subset[(i + 1) % 2][j]; 
            else
                subset[i % 2][j] = subset[(i + 1) % 2][j]; 
        } 
    } 
    ll res=-1;
  	for(ll i=k;i<=sum;i++){
  		if(subset[n%2][i]==1){
  			res=i;
  			break;
		}
	}
    return res; 
} 

int main()
{
	FIO;int T;cin>>T;
	while(T--){
		ll n,k;cin>>n>>k;
		ll a[n];
		ll sum[n];
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}
		if(n==1){
			cout<<"-1\n";
			continue;
		}
		sort(a,a+n);
		for(ll i=0;i<n/2;i++){
			swap(a[i],a[n-i-1]);
		}
		sum[0]=a[0];
		for(ll i=1;i<n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		int fl=1;
		for(ll i=1;i<n;i++){
			if(sum[i]>=2*k){
				ll B[i+1];
				for(ll j=i;j>=0;j--){
					B[i-j]=a[j];
				}
				ll x=isSubsetSum(B,i+1,100000,k);
				if(x!=-1 && sum[i]-x>=k){
					cout<<i+1<<endl;
					fl=0;
					break;
				}
			}
		}
		if(fl){
			cout<<"-1"<<endl;
		}
	}	
	return 0;
}