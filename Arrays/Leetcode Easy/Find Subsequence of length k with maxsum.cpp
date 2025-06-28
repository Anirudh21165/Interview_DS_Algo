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
    vector<int>result=maxsubsequence(nums,k);
    for(int i=0;i<k;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}

//Approach-2 (Using nth_element for partial sort)
//T.C : Average O(n+k)
//S.C : O(1)
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if (k == nums.size())
            return nums;

        // Copy nums to a temp vector to find k largest elements
        vector<int> temp(nums);
        
        // Use nth_element to put the k largest elements in the first k positions (unordered)
        nth_element(begin(temp), begin(temp) + k - 1, end(temp), greater<int>()); //Average TC is O(n)

        // Determine the threshold value (k-th largest element)
        int threshold = temp[k - 1];

        // Count how many times threshold appears in top k elements
        int countThreshold = count(temp.begin(), temp.begin() + k, threshold); //O(k)

        vector<int> result;
        for (int num : nums) {
            if (num > threshold) {
                result.push_back(num);
            } else if (num == threshold && countThreshold > 0) {
                result.push_back(num);
                --countThreshold;
            }
            if (result.size() == k)
                break;
        }

        return result;
    }
};