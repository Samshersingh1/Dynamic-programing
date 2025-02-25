Given an array arr[] of size n, where arr[i] denotes the height of ith stone. Geek starts from stone 0 and from stone i, he can jump to stones 
i + 1, i + 2, … i + k. The cost for jumping from stone i to stone j is abs(arr[i] – arr[j]). Find the minimum cost for Geek to reach the last stone. 


  //Note : in this version i alow to jump to up to kth index...

  Approach:; 
step 1:  declare a index
step 2: do all the stuff to that index up to k loop
step 3:: make sure index are valid (i-j>=0) here i is where it has jump and j is from where he is coming 
step 4:: retur the dp[n-1]..






tabulation form 

class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) { 
        int n=arr.size();
         vector<int>dp(n+1,1e9);
         dp[0]=0;
         for(int i=1;i<n;i++){
              for(int j=1;j<=k;j++){
                  if(i-j>=0){
                      dp[i]=min(dp[i],(dp[i-j]+abs(arr[i]-arr[i-j]))); 
                  }
              } 
         }
         return dp[n-1];
    }
};

tc=(n*k) 
sc=o(n)..  
