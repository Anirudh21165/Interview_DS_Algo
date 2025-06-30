//2-pointer approach 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());  // O(n log n)

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;  // skip duplicate "first" elements

            int target = -nums[i];
            int l = i + 1, r = n - 1;

            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == target) {
                    res.push_back({nums[i], nums[l], nums[r]});

                    // skip duplicates for second and third elements
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    while (l < r && nums[r] == nums[r - 1]) --r;

                    ++l;
                    --r;
                }
                else if (sum < target) {
                    ++l;
                }
                else {
                    --r;
                }
            }
        }

        return res;
    }
};


//3-pointer approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l=n-1;
            int j=i+1;
            while(j<l){
                long long sum=nums[i];
                sum+=nums[j];
                sum+=nums[l];
                if(sum==0){
                    vector<int>temp={nums[i],nums[j],nums[l]};
                    res.push_back(temp);
                     while (j < l && nums[j] == nums[j + 1]) ++j;
                    while (j < l && nums[l] == nums[l - 1]) --l;
                    l--;
                    j++;
                }
                else if(sum>0)l--;
                else j++;
            }
        }
        return res;
    }
};
