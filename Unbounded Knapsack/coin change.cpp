//here is the problemPROBLEM :: You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin. 

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1 

Approach:: 
 in this problem the greedy will not work because of serverl reasons 
1.Greedy takes local optimum
2.Fails for non-standard denominations: If coins are not multiples of each other (e.g., [1, 3, 4]), then greedy fails.

so we will sove it using dynamic programing.../BFS 

  //memosation 
  class Solution {
public: 
            int  helper(int id,vector<int>&coins,int current_amount,vector<vector<int>>&dp)  {
               
                 if(id<0 ) {    //this will not  return 0 it will return max value because we are not able to collect coins ..
                   return 1e9;
                 }     
                  if(current_amount==0) return 0; 
                   if(dp[id][current_amount]!=-1) return dp[id][current_amount] ; 
                 int nottake= helper(id-1,coins,current_amount,dp); 
                 int take=INT_MAX;
                if(coins[id]<=current_amount) {
                    take =1+helper(id,coins,current_amount-coins[id],dp);  
                }  
                 // return helper(id-1,coins,current_amount);
               return dp[id][current_amount]=min(take,nottake);    
            }        
    int coinChange(vector<int>& coins, int amount) { 
         int n=coins.size(); 
          vector<vector<int>>dp(n,vector<int>(amount+1,-1));
         int ans=helper(n-1,coins,amount,dp);  
       //  vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
         return (ans==1e9)?-1:ans;
    }
};        

//TC:: (n*amount)..
//SC=(n*amount) +O(N)( because of recursive space)...

//NOW WE WILL DO IT BY TABULATION METHOD 

  int n=coins.size(); 
          vector<vector<int>>dp(n+1,vector<int>(amount+1,1e9)); 
         int ans=helper(n-1,coins,amount,dp);  
       //  vector<vector<int>>dp(n+1,vector<int>(amount+1,-1)); 
       for(int i=0;i<=n;i++) dp[i][0]=1; //for 0 amount it always possible for any coin to make 0..
          
           for(int i=1;i<=n;i++){
              for(int j=1;j<=amount;j++) {
                     int nottake= dp[i-1][j];  
                      int take=INT_MAX;
                if(coins[i-1]<=j) {
                    take =1+dp[i][j-coins[i-1]];   
                }  
                 // return helper(id-1,coins,current_amount);
                  dp[i][j]=min(take,nottake);    
              }  
           } 
           return (dp[n][amount]==1e9)?-1:dp[n][amount]-1;
         
    }
};          

TC: o(N*AMOUNT) 
  SC :: O(N*AMOUNT)..

Now we will do space optimasation too..
  int coinChange(vector<int>& coins, int amount) { 
         int n=coins.size(); 
         vector<int>pre(amount+1,1e9) ,curr(amount+1,1e9);
         pre[0]=1;
         curr[0]=1;
             for(int i=1;i<=n;i++){
              for(int j=1;j<=amount;j++) {
                     int nottake= pre[j];   
                      int take=INT_MAX;
                if(coins[i-1]<=j) {
                    take =1+curr[j-coins[i-1]];    
                }  
                 // return helper(id-1,coins,current_amount);
                  curr[j]=min(take,nottake);     
              }    
                 pre=curr;
           }   
            return (pre[amount]==1e9)?-1:pre[amount]-1; 
          
         
    }
};          

//tc:: O(n*amount)..
//sc:: o(amount) .. this is most optimise code for it 
