//We define a harmonious array as an array where the difference between its maximum value and its
//minimum value is exactly 1.
//Given an integer array nums, return the length of its longest harmonious subsequence among all its
//possible subsequences.
//Input: nums = [1,3,2,2,5,2,3,7]
//Output: 5
//The longest harmonious subsequence is [3,2,2,2,3].
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int maxcnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=n-1;
            while(nums[j]-nums[i]>1){
                 j--;
                }
            if(nums[j]-nums[i]==1){
                maxcnt=max(maxcnt , j-i+1);
            }    
        }
        return maxcnt;
    }
};