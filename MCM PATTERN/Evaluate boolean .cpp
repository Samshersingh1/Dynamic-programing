
// here is the link of the question   https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card


// User function Template for C++
  
class Solution{
public:  
 int MOD=1003;  
     int helper(int i,int j,string &s,bool isflag, vector<vector<vector<int>>>&dp){
       //   if(i>j) return 0;  
           if(i==j){
                if(isflag==true){
                   return s[i]=='T'; 
               }
                else{
                   return s[i]=='F';
               }
          }  
          if(dp[i][j][isflag]!=-1) return dp[i][j][isflag];
           int ans=0;
            for(int k=i+1;k<=j;k+=2){
               int lt=helper(i,k-1,s,true,dp);
              int lf=helper(i,k-1,s,false,dp);
               int rt=helper(k+1,j,s,true,dp);
               int rf=helper(k+1,j,s,false,dp); 
            if(s[k]=='&'){
                if(isflag==true){
                    ans= ans+lt*rt;
                }
                else{
                     ans= ans+lt*rf+lf*rt+rf*lf; 
                }
            } 
               else if(s[k]=='|'){
                if(isflag==true){
                     ans=ans+lt*rf+rt*lf+rt*lt;
                }
                else{
                      ans= ans+lf*rf;
                }
            } 
               else if(s[k]='^'){
                if(isflag==true){
                        ans= ans+lt*rf+rt*lf; 
                } 
                else{
                      ans= ans+lf*rf+rt*lt;  
                }
                }  
              //  dp[i][j][isflag]=ans;
            
         }
         return dp[i][j][isflag]=ans%MOD;
    }
         int countWays(int n, string s){ 
         vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1))); 
        return helper(0,n-1,s,true,dp);
        }
};