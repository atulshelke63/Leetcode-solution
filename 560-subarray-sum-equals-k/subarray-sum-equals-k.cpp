class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int n=nums.size();
        // int count=0;
        // for (int i=0;i<n;i++){
        //     int sum=0;
        //     for (int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if (sum==k){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        int n=nums.size();
        int count=0;
        vector<int> prefix_sum(n,0);
        prefix_sum[0]=nums[0];
        for (int i=1;i<n;i++){
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        unordered_map<int,int> m;
        for (int j=0;j<n;j++){
            if (prefix_sum[j]==k){
                count++;
            }
            int val=prefix_sum[j]-k;
            if (m.find(val) != m.end()){
                count+=m[val];
            }
            if (m.find(val) == m.end()){
                m[prefix_sum[j]]==0;
            }
            m[prefix_sum[j]]++;
        }
        return count;
    }
};