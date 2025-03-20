//in this problem we have to find the logest subset whcih has each pair divisble 

//we will sort the array bacause order does not matter then 
// we now have the same thing like LIS we have to find divisible in place of  increasing 

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),hash(n);
        int maxi=1,idx=0;   //index make 0 i
        for(int i=0;i<n;i++){ 
             hash[i]=i;
            for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]) {  // here nums[i]%nums[j] we have  to take care....
              dp[i]=1+dp[j];
                hash[i]=j;
            } 
            if(maxi<dp[i]){
                maxi=dp[i];
                idx=i;
            }  
            } 
        }   
        vector<int>ans;
      
        while(hash[idx]!=idx) {
            ans.push_back(nums[idx]);
            idx=hash[idx];
        } 
          ans.push_back(nums[idx]); 
          reverse(ans.begin(),ans.end());
          return ans;
    }
};  
