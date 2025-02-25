/*Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, 
and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't
 do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and 
 arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum 
 total merit points Geek can achieve .*/

 class Solution {
    public: 
              int helper(int id,int n,vector<vector<int>>& arr,int lastIndex, vector<vector<int>>&dp){
                  if(id>=n) return 0; 
                  if(dp[id][lastIndex]!=-1) return dp[id][lastIndex];
                int a=INT_MIN,b=INT_MIN,c=INT_MIN; 
                
                
                if(lastIndex!=0){
                    a=arr[id][0]+helper(id+1,n,arr,0,dp);
                }   
                
                 if(lastIndex!=1){
                    b=arr[id][1]+helper(id+1,n,arr,1,dp); 
                }   
                
                 if(lastIndex!=2){
                    c=arr[id][2]+helper(id+1,n,arr,2,dp);
                }   
                return dp[id][lastIndex]=max({a,b,c}); 
                
              }
      int maximumPoints(vector<vector<int>>& arr) {
           int n=arr.size(); 
             vector<vector<int>>dp(n,vector<int>(4,-1));
           int ans=0;
           for(int i=0;i<3;i++){
               ans=max(ans,arr[0][i]+helper(1,n,arr,i,dp));
           } 
           return ans;
      }
  }; 
