//this is problem in this we have to find shortest common supersequences this is a LCS Based question ... 
// in this Lenth of (SCS=n+m-LCS ) where ther n is lenth of string 1 and m is lenth of string 2...

// but we have to find the string of SCS so just like we had print LCS we will do the same ...

Step 1:: first we crete a 2-D dp table which tells us LCS of  at the given cell at (i,j)...
Step 2:: Now,we will start from (n,m) cell and check where it is equal or not if yes then just add in our aswer
Step 3:: if it is not equal then we will check max((i-1,j),(i,j-1)) which is greater just add this in string (NOTE:: if i is greater add s1 if j then add s2)
Step 4:: there may be chance whether i>0 || j>0 means they are not exhausted right Now...
Step 5:: we will add remaing to tghe answer... 

//let's discuss time and space complexcity  
//TC:: o(n*m)+o(n+m) 
//sc:: o(n*m) but can be O(min(n,m))..

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
         int n=str1.size();
         int m=str2.size(); 
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         for(int i=1;i<=n;i++){
             for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];  
                } 
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                } 
             } 
         } 
         // now we are have a 2-D table which  has LCS.. 
         string ans="";
         int i=n,j=m;
         while(i>0 && j>0) {
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            } 
            else{
                if(dp[i][j-1]>dp[i-1][j]) {
                    ans+=str2[j-1];
                    j--;
                }  
                else{
                    ans+=str1[i-1];
                    i--;
                } 
            } 
         } 
         while(i>0){
             ans+=str1[i-1];
             i--;
         }
          while(j>0){
             ans+=str2[j-1];
             j--;
         }  
         reverse(ans.begin(),ans.end());
         return ans;

    }  
}; 
