class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        for (int i=0;i<n;i++){
            if (i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int start=i+1,end=n-1;
            while (start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if (sum>0){
                    end--;
                }else if (sum<0){
                    start++;
                }else{
                    ans.push_back({nums[i],nums[start],nums[end]});
                    start++,end--;
                    while (start<end && nums[start]==nums[start-1]){
                        start++;
                    }
                    while (end>start && nums[end]==nums[end+1]){
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};