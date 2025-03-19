//in this problem we have to find the Number of longest incresing subsequenses  how many are there with maxi lenth...

// a={1 3 5 4 7}  answer will be 2...

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN,idx=-1;
        vector<int>dp(n,1),ways(n,1);
        for(int i=0;i<n;i++){
             for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && 1+dp[j]>dp[i]) {
                        dp[i]=dp[j]+1;
                        ways[i]=ways[j];     
                }  
                else if(nums[i]>nums[j] && 1+dp[j]==dp[i]) {
                       ways[i]+=ways[j];  // if this is equal the dry run in this you will get the answer
                } 
             }    
              if(maxi<dp[i]) {
                        maxi=dp[i];
                     } 

        }    
        int ans=0;
        for (int i = 0;i<n; i++) {
            if (dp[i] == maxi) {
                ans += ways[i];
            }
        }
        return ans;

    }
};       
