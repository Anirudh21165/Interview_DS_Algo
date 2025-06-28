#include<bits/stdc++.h>
using namespace std;

vector<int>maxsubsequence(vector<int> &nums , int k){
    int n=nums.size();
    vector<pair<int , int>>vec(n);
    for(int i=0;i<n;i++){
        vec[i]=make_pair(i,nums[i]);
    }
    auto lambda=[](auto &p1 , auto &p2){
        return p1.second>p2.second;
    };
    sort(begin(vec) , end(vec) , lambda);
    sort(vec.begin(), vec.begin() + k, [](auto &a, auto &b){
        return a.first < b.first;
    });
    vector<int>result;
    for(int i=0;i<k;i++){
        result.push_back(vec[i].second);
    }
    return result;
}

int main(){
    vector<int>nums={-1,-2,-10,-11,5,4,9,7};
    int k=4;
    cout<<"hello";
    vector<int>result=maxsubsequence(nums,k);
    for(int i=0;i<k;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}