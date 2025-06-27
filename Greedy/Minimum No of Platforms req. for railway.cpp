#include<bits/stdc++.h>
using namespace std;
int minplatformreq(int arr[] , int dep[] , int n){
    int ans;
    int cnt=1;
    sort(arr,arr+n);
    sort(dep,dep+n);
    int i=1;
    int j=0;
    while(i<n){
        if(arr[i]<=dep[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        ans=max(ans,cnt);
    }
    return ans;
}
int main(){
    int n=6;
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    cout<<minplatformreq(arr,dep,n);
    return 0;
}