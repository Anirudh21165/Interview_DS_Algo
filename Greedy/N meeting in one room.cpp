#include<bits/stdc++.h>
using namespace std;

struct meetings{
    int start;
    int end;
    int pos;
};

class Solution{
    public:
    bool static comparator(struct meetings m1 , meetings m2){
        if(m1.end < m2.end)return true;
        else if(m1.end > m2.end)return false;
        else if(m1.pos < m2.end)return true;
        else return false;
    }
    void maxmeetings(int s[],int e[],int n){
        struct meetings meet[n];
        for(int i=0;i<n;i++){
            meet[i].start=s[i] , meet[i].end=e[i] , meet[i].pos=i+1; 
        }
        sort(meet , meet+n , comparator);
        vector<int> ans;
        int limit=meet[0].end;
        ans.push_back(meet[0].pos);
        for(int i=1;i<n;i++){
            if(meet[i].start > limit){
                limit=meet[i].end;
                ans.push_back(meet[i].pos);
            }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<"  ";
        }
    }
};

int main(){
    Solution obj;
    int n=6;
    int start[]={0,3,1,5,5,8};
    int end[]={5,4,2,9,7,9};
    obj.maxmeetings(start,end,n);
    return 0;
}