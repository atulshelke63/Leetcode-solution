// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> ans(n,-1);

//         for (int i=0;i<n;i++){
//             for (int j=1;j<n;j++){
//                 int idx=(i+j)%n;

//                 if (nums[idx]>nums[i]){
//                     ans[i]=nums[idx];
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        vector<int> ans(n,-1);

        for (int i=2*n-1;i>=0;i--){
            while (!s.empty() && nums[s.top()]<=nums[i%n]){
                s.pop();
            }
            
            if (i<n && !s.empty()){
                ans[i%n]=nums[s.top()];
            }
            
            s.push(i%n);
        }
        return ans;
    }
};        