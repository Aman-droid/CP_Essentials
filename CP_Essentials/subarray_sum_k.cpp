#include <bits/stdc++.h>
using namespace std;
int  subarraysum(int arr[],int n,int sum)
{
    unordered_map<int,int>psum;
    int res=0;
    int csum=0;
    for(int i=0;i<n;i++)
    {
        csum+=arr[i];
        if(csum==sum)
            res++;
        if(psum.find(csum-sum)!=psum.end())
            res+=(psum[csum-sum]);
        psum[csum]++;
    }
    return res;
}
int main()
{
    int arr[]={ 10, 2, -2, -20, 10 };
    int sum=-10;
    int n=5;
    cout<<subarraysum(arr,n,sum);
    return 0;
}
