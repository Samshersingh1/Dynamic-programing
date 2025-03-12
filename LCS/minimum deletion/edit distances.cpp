//the main catch in this problem is Base case means if any of the string reaches it's end then base case will return remaing charecter of other string 

class Solution {
public: 
           int  editDistane(int i,int j,string word1,string word2,vector<vector<int>>&dp) {  
            if(i<0) return j+1; 
            if(j<0) return i+1; 
            int a=INT_MAX,b=INT_MAX,c=INT_MAX;
            if(dp[i][j]!=-1) return dp[i][j];

            if(word1[i]==word2[j]) {
               return dp[i][j]=editDistane(i-1,j-1,word1,word2,dp);
            } 
            else{
                int a=editDistane(i-1,j-1,word1,word2,dp);
                int b=editDistane(i-1,j,word1,word2,dp);
                int c=editDistane(i,j-1,word1,word2,dp); 
               return dp[i][j]= 1+min({a,b,c});
            }

           } 
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,1e9));
       // return editDistane(n-1,m-1,word1,word2,dp); 
         for(int i=0;i<=n;i++){
             dp[i][0]=i;
         }
          for(int j=0;j<=m;j++){
             dp[0][j]=j;
         }  

       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            if(word1[i-1]==word2[j-1]) {
                 dp[i][j]=dp[i-1][j-1];
            } 
            else{
                dp[i][j]= 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});    
            }
        }
       } 
       return dp[n][m];

    } 
};       
