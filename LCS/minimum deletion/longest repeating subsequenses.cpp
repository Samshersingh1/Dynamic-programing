// in this problem ew want sequense which are repating 
/* 
 in this s=AABEBCDD the ABD are reapting twice so it has to be apprers twice..
*/ 

Approach first will cheack logic behind how an charecter is not a part of our lrs then got a logic if whenever the (i==j) will arrive we will got same elemnt 
but in (i!=j) case we can get diffrent charecter but if (i!=j) we can able to get same charecter means this will be our part of LCR...

class Solution {
  public:
    int LongestRepeatingSubsequence(string &s) {
          int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0)); 
       for(int i=0;i<=n;i++) dp[i][0]=0;
       for(int j=0;j<=n;j++) dp[0][j]=0;

       for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){ 
            
              if(s[i-1]==s[j-1] && i!=j){
                    dp[i][j]= 1+dp[i-1][j-1];
                  }  
                  else{
                   dp[i][j]=0 +max(dp[i-1][j],dp[i][j-1]);
                  }
        } 
       } 

      return  dp[n][n];
    }
};

//tc:: o(n^2) && sc will also be same
