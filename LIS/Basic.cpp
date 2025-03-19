//here is the problem input:; {0,1,0,3 ,2 ,3} we have find longest incresing subpequesme output 4 {0,1,2,3} 

//we have to print both lenth and anser 

class Solution {
public:  
         int LIC(int i,int last,vector<int>&arr,vector<vector<int>>&dp){
            if(i==arr.size()) return 0;
            if(dp[i][last+1]!=-1) return dp[i][last+1];   //we are making last+1 beacause of last =-1
             int b=0+LIC(i+1,last,arr,dp);
             int a=0;
            if(last==-1 || arr[i]>arr[last] ) {
             a=1+LIC(i+1,i,arr,dp); 
            } 
             return dp[i][last+1]=max(a,b);
         }    
    int lengthOfLIS(vector<int>& nums) {
         int n=nums.size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,0)) ;  //our answer will be at dp[n][n] means we can solve it in o(n).. 
    //  for(int i=0;i<=n;i++) dp[i][nums[0]]=1;
         
             for(int i=n-1;i>=0;i--){ 
              for(int j=i-1;j>=-1;j--){
                  int b=0+dp[i+1][j+1];
                  int a=0;
                  if(j==-1 || nums[i]>nums[j]) {
                     a=1+dp[i+1][i+1];
                  } 
                  dp[i][j+1]=max(a,b);
              }
           } 
        return  dp[0][0]; 
    } 
};    
  //tc:: (n*n) this is not a best solution 

 //best soution will be in o(n) ... time complexity
  for(int i=0;i<n;i++){
         for(int j=0;j<i;j++){
          if(a[i]>a[j]){
             dp[i]=max(dp[i],1+dp[j]);
          }
         }
  }   

//our answer will be max of all the dp array 
// tc will be o(n*n) but sc will trim down to O(N)..

//FOR PRINTING LIS ....  


//for printing the lis we have to check whcih elemnt is recently smalest than the current elemnt the nwe will go deep woth index using another array

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
         vector<int>dp(n,1),hash(n,0); 
		  int idx=-1,maxi=INT_MIN;
    for(int i=0;i<n;i++){ 
		   hash[i]=i;   //this is another array for checking the previous lelents index whcxih is sammelr than the current elemtns 
		 for(int j=0;j<i;j++){ 
            if(arr[i]>arr[j] && dp[j]+1>dp[i]) {  // if current elemnt is smaaler than given and  given elemnts LIC is greater than the given elemnts lIS 
	             dp[i]=dp[j]+1;  //change the LIS of the given elemnts 
	               hash[i]=j;   //this is importent step chnge the index present in the hash
             }  

			 if(maxi<dp[i]) {
				  maxi=dp[i];
				  idx=i;   //find the index whcih has greater  LIS value 
			 } 
            
		 }     
	}  

	    vector<int>ans;
		 ans.push_back(arr[idx]);
	   while(hash[idx]!=idx) {   // we will stop when we cncounter the  hash[idx]=idx means here  dp[idx]=1  
		  
		   idx=hash[idx];
		    ans.push_back(arr[idx]);
	   } 
	   reverse(ans.begin(),ans.end());
	   return ans;
 
	}   


    
