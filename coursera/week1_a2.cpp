#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long ans=a[n-1]*a[n-2];
    cout<<ans<<endl;
}