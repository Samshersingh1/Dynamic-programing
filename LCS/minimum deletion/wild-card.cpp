/* 
 you are given a string and a patten and you have to  find the is therer any chance that  string can match with the patten ..
  you can cchange ? to any charecter and * to and sequence of charecter... 
  eg:: abcde  p=a*d?e   output:: false.. */ 

Approach 1::  GREEDY APPROACH ... O(N)  
same just think like but when you got * we will store the index and move forward and again when we got mismatching charecter we will use the stroing index ..

   class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0; 
        int starIdx = -1, matchIdx = -1; 
        while (i < s.size()) {
            if (j < p.size() && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }   
            else if (j < p.size() && p[j] == '*') {
                starIdx = j;
                matchIdx = i;
                j++; 
            }
            else if (starIdx != -1) {
                j = starIdx + 1;  
                matchIdx++;     
                i = matchIdx;   
            }
            else {
                return false;
            }
        }
        while (j < p.size() && p[j] == '*') {
            j++;
        }
        return j == p.size(); 
    }
}; 

Approach 2:: DYNAMIC PROGRAMING 
 first step we have to take care of base case smartly 
 just like greedy logic we will do but in case of * we will cheack(i-1,j) || (i,j-1) if either of anyone my answer will come out to be true then answer is true..






class Solution {
public:

    // TC:: will be o(n*m) this will be number of maximum state ..
    // SC:: will be o(n*m)+o(m+n)... we can remove(o(m+n)) this using tabulation method here ....
      bool solve(int i,int j,string &s,string &p,vector<vector<int>>&dp){
         if(i<0 && j<0) return true;
         if(i>=0 && j<0) return false;
         if(i<0 && j>=0){
             for(int  k=0;k<=j;k++){
                if(p[k]!='*') return false;
             } 
             return true;
         }
         if(dp[i][j]!=-1) return dp[i][j];
         if(s[i]==p[j] || p[j]=='?') return dp[i][j]= solve(i-1,j-1,s,p,dp);  // if charecter mathcing then we will move forward ...
         if(p[j]=='*') return dp[i][j]= solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp);   // we we got * then we will stop in that and move ahead or we will skip this 


          return dp[i][j]=false;  //if string are not matching  return false straight...
      }
    bool isMatch(string s, string p) {
         int n=s.size();
         int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
         return solve(n-1,m-1,s,p,dp);
    }
};



















  
