// RPOBLEM :: You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

 

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3


APPROACH 1: use of back tracking ..
class Solution {
public: 
   void helper(int id,int n,vector<int>&v,vector<int>&nums,int &k,long long &c) {
    if(id==n) {
        int sum=accumulate(v.begin(),v.end(),0); 
        if(sum==k) c++;
        return ; 
    }       
       v.push_back(-nums[id]);  
       helper(id+1,n,v,nums,k,c) ;
      v.pop_back();
      v.push_back(nums[id]);
      helper(id+1,n,v,nums,k,c); 
       v.pop_back();
   }  
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(); 
        vector<int>v;
         long long c=0;
        helper(0,n,v,nums,target,c);  
        return c;
    }   
};        
TC:: O(2^n).
SC:: o(n) using the recursive stack.. 

  approach 2:: use of dp 
class Solution {
public:
 
          int findways(int i,int k,vector<int>&nums, vector<vector<int>>&dp,int offset){
               if(i<0){
                  if(k==0){
                    return 1;
                  } 
                  return 0;
               }  
               if(k+offset<0 || k+offset>=dp[0].size()) return 0; 
                if(dp[i][k+offset]!=-1) return dp[i][k+offset];
                int negative= findways(i-1,k+nums[i],nums,dp,offset);
              
              int   positive = findways(i-1,k-nums[i],nums,dp,offset); 
               
               return dp[i][k+offset]=(positive+negative); 
          }
      
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(); 
        int sum=accumulate(nums.begin(),nums.end(),0); //accomdate the all the values odf nums..
        int offset=sum;
        if (abs(target) > sum) return 0;
        vector<vector<int>>dp(n,vector<int>(2*sum+1,-1)); 
        return findways(n-1,target,nums,dp,offset); 

    }  
};  
tc:: o(n*sum)
sc:: o(n*sum)
  
