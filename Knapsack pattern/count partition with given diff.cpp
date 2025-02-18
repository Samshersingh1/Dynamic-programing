//PROBLEM DECRIPTION  :: Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. 
//Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater 
//than or equal to sum2 and the difference between sum1 and sum2 is equal to d...

/* will solve it using a dp talbe*/
//APPROACH 
/* 
step 1: we have to find (sum1-sum2)>d like count subset which satisfie this we will some mathematics in this 
step 2:: beacus sum1+sum2=TotalSum then we have find the count the number of subset which satisfie k=(TotalSum-d)/2..; 
step 3:: we have to take care that a subset may contain empty elemnt..
*/ 
class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
         int sum=accumulate(arr.begin(),arr.end(),0);  //total sum
         if((sum-d)%2!=0 || sum-d<0) return 0; //not availbe..
         int k= (sum-d)/2; 
         
         // Now from here we have to count the total number of subsets whose sum is equal to k...
          int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));  
       dp[0][0]=1;
         
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){ 
                int nottake=dp[i-1][j];
                int take=0;
              if(arr[i-1]<=j){
                  take=dp[i-1][j-arr[i-1]];  
              }  
              dp[i][j]=take+nottake; 
            }
        }
        return dp[n][k];
    } 
};
//TC:; O(N*M) where n is arr lenth and m is target..
//space (n+1*m+1) ..because we are creating the dp table if this size..

//HERE IS THE MOST OPTIMSE O(1) SPACE SOLUTION .. 
class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
         int sum=accumulate(arr.begin(),arr.end(),0);  //total sum
         if((sum-d)%2!=0 || sum-d<0) return 0; //not availbe..
         int k= (sum-d)/2; 
         
         // Now from here we have to count the total number of subsets whose sum is equal to k...
          int n=arr.size();
       vector<int>pre(k+1,0),curr(k+1,0);
          pre[0]=1;
       //  curr[0]=1;
            for(int i=1;i<=n;i++){
            for(int j=k;j>=0;j--){   //we are using reverse because we did not want overwriting thing 
                int nottake=pre[j];
                int take=0;
              if(arr[i-1]<=j){
                  take=pre[j-arr[i-1]];  
              }  
              curr[j]=take+nottake; 
            } 
              pre=curr;
        }
        return pre[k];    
    } 
}; 
//TC :: time complexcity will be same 
//SC:: it Will be o(k) since we are using only this
