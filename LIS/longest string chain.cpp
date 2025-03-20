// here is the problem 




//approach 
1. Sorting the words by length is necessary because a longer word can only be formed by adding one character to a shorter word.
2. then just use patten of LIS and for checking use string matching type..

  class Solution {
public:
    int longestStrChain(vector<string>& s) {
         int n=s.size(); 
          sort(s.begin(), s.end(), [](string &a, string &b) {
            return a.size() < b.size(); // Sort by length
        });
         vector<int>dp(n,1); 
         int maxi=1;
         for(int i=0;i<n;i++){
             for(int j=0;j<i;j++){ 
                int a=s[i].size();
                int b=s[j].size(); 
                int p=0,q=0,c=0;
                
                        if(a-b==1) {
                          int p=0,q=0,c=0;
                          bool flag=false; 
                         
                           while(p<a && q<b) {
                            if(s[i][p]==s[j][q]) {
                          p++;
                        q++;
                           }  
                         else{
                        c++;
                        p++;
                        if(c>1) {
                            flag=true;
                            break;
                        }
                    }  
 
                       }    
                       if(flag==false && dp[j]+1>dp[i]) {
                             dp[i]=dp[j]+1;
                       }  
                      
                     } 
                    
                     maxi=max(maxi,dp[i]);
             }  
         }  
         return maxi;
    }  
};   
//tc will be o(n^2)
