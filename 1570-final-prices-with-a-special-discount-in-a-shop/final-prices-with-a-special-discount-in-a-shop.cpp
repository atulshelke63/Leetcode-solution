// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         vector<int> ans;
//         for (int i=0 ; i<prices.size() ; i++){
//             bool found=false;
//             for (int j=i+1 ; j<prices.size() ; j++){
//                 if (prices[j]<=prices[i]){
//                     ans.push_back(prices[i]-prices[j]);
//                     found=true;
//                     break;
//                 }
//             }
//             if (!found){
//                 ans.push_back(prices[i]);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        vector<int> ans(prices.size());

        for (int i=prices.size()-1;i>=0;i--){
            while (!s.empty() && s.top()>prices[i]){
                s.pop();
            }
            if (s.empty()){
                ans[i]=prices[i];
            }
            else{
                ans[i]=prices[i]-s.top();
            }
            s.push(prices[i]);
        }
        return ans;
    }
};        