//You are given an array of integers nums and an integer target.
//Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum 
//element on it is less or equal to target. Since the answer may be too large,
// return it modulo 109 + 7.

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
       const int M=1e9+7;
        int n=nums.size();
        sort(nums.begin() , nums.end());
        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % M;
        }
        int i=0;
        int r=n-1;
        int result=0;
        while(i<=r){
            if(nums[i]+nums[r]<=target){
                int x=r-i;
                result = (result + power[r-i]) % M;
                i++;
            }
            else r--;
        }
        return result;
    }
};