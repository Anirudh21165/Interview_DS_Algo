#include<bits/stdc++.h>
using namespace std;

struct job{
    int id;
    int dead;
    int profit;
};
class solution{
    public:
     bool static comparison(job a,job b){
            return (a.profit > b.profit);
     }
    pair<int , int>jobScheduling(job arr[] , int n){
        sort(arr , arr+n ,comparison);
        int maxi=arr[0].dead;
        for(int i=1;i<n;i++){
            maxi=max(maxi,arr[i].dead);
        }
        int slot[maxi+1];
        for(int i=0;i<=maxi;i++)slot[i]=-1;
        int cntjob=0;
        int maxprofit=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j++){
                if(slot[j]==-1){
                    slot[j]=i;
                    cntjob++;
                    maxprofit+=arr[i].profit;
                    break;
                }
            }
        }
        return make_pair(cntjob,maxprofit);
    }
};

int main() {
   int n = 4;
   job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   solution ob;

   pair < int, int > ans = ob.jobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
} 