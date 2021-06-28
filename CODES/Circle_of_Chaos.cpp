#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main() {
	int T;cin >> T;
	while(T--){
	    ll m, n;cin >>n>>m;
	    ll arr[300001];
	    for(ll i=0; i<m; i++){
	        cin >> arr[i];
	    }
	    ll res = arr[0];
	    for(int i=1; i<m; i++){
	        res = gcd(res, arr[i]);
	    }
	    if(n>=res){
	        cout << n-res << endl;
	    }
        else if(res==1){
	        cout << n-1 << endl;
	    } 
        else {
	        int l = n;
	        while(l!=0 && res%l!=0){
	            l--;
	        }
	        cout << n-l << endl;
	    }
	}
	return 0;
}
