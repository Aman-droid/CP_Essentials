#include<bits/stdc++.h>
#define ll long long 
#define int long long 
#define endl '\n'
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
using namespace std;
signed main() {
    int T=1;//cin>>T;
    while (T--){
        // int a[11][2],b[11][2],c[11];
        // int n,x,f;cin>>n;
        // char ch;

        // for(int i=0;i<=10;i++){
        //     a[i][0] = b[i][0]=0;
        //     a[i][1] = b[i][1]=1;
        //     c[i]=0;
        // }
        // for(int i=9;i>=0;i--){
        //     cout<<b[i][0]<<" ";

        // }
        // cout<<endl;
        // for(int j=1;j<=n;j++){
        //     cin>>ch>>x;
        //     cout<<"x====>   "<<x<<endl;
        //     if(ch=='|'){
        //         rep(i,0,10){
        //             f= (x & (1<<i))== 0 ? 0:1;
        //             //cout<<f<<endl;
        //             b[i][0]= b[i][0] | f;
        //             b[i][1]= b[i][1] | f;
        //         }
        //     }
        //     else if(ch=='&'){
        //         rep(i,0,10){
        //             f = (x & (1LL<<i));
        //             b[i][0]= b[i][0] & f;
        //             b[i][1]= b[i][1] & f;
        //         }
        //     }
        //     else {
        //         rep(i,0,10){
        //             f = x & (1LL<<i);
        //             b[i][0]= b[i][0] ^ f;
        //             b[i][1]= b[i][1] ^ f;
        //         }
        //     }
        //     for(int i=9;i>=0;i--){
        //         cout<<b[i][0]<<" ";
        //     }
        //     cout<<endl;
        //     for(int i=9;i>=0;i--){
        //         cout<<b[i][1]<<" ";
        //     }
        //     cout<<endl;
        // }

        // int sum=0;
        // rep(i,0,9){
        //     sum+=(1LL<<i);
        //     if(a[i][0]==b[i][0] && a[i][1]== b[i][1] ){
        //         continue;
        //     }
        //     else if(a[i][0]!=b[i][0] && a[i][1]!= b[i][1] ){
        //         c[i]=1; //XOR 1
        //     }
        //     else if(a[i][0]==0 && a[i][1]==0 ){
        //         c[i]=2;
        //     }
        //     else if(a[i][0]==1 && a[i][1]==1 ){
        //         c[i]=3;
        //     }
        // }
        // int x1=0,x2=sum,x3=0;
        // rep(i,0,9){
        //     if(c[i]==1){
        //         x1 += (1LL<<i);
        //     }
        //     else if(c[i]==2){
        //         x2 -= (1LL<<i);
        //     }
        //     else if(c[i]==3){
        //         x3 += (1LL<<i);
        //     }
        // }
        int n;cin >> n;
	    int a = 0,b = 1023;
	    while(n--){
	        char c;int x;cin >> c >> x;
	        if(c == '|') a |= x,b |= x;
	        if(c == '&') a &= x,b &= x;
	        if(c == '^') a ^= x,b ^= x;
	    }
        
	    int ans1 = a^(b^1023), ans2 = b^1023;

	    cout << 2 << endl << "| " << ans1 << endl << "^ " << ans2;
    }   
    return 0;   
}