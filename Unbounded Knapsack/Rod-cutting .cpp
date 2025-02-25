   /*  
   Given a rod of length n(size of price) inches and an array of prices, price. price[i] denotes the value of a
    piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
   */ 

   //approach for unbounded  knapsack problems ....
   //recursion Based question...


   #include<bits/stdc++.h>
   using namespace std;  
    
   int maxprofit(int id,int n,vector<int>&arr){
    if(n==0 || id>=arr.size()) return 0; 
    
    int nottake=maxprofit(id+1,n,arr);
    int take=INT_MIN;
    if(n>=id+1){
        take=arr[id]+maxprofit(id,n-(id+1),arr);
    }
     return max(take,nottake);
}

int cutRod(vector<int> &price) {
   int n=price.size();
   return maxprofit(0,n,price);
}

   int main(){
       int n;
       cin>>n; 
       vector<int>arr;
       for(int i=0;i<n;i++){
      cin>>arr[i];
       } 
       return cutRod(arr);  

   }  

// Now here ti tabulation of this 
//tc o(n*n)
sc:: o(n*n) ..
   class Solution {
  public:
     int maxprofit(int id,int n,vector<int>&arr){
         if(n==0 || id>=arr.size()) return 0; 
         
         int nottake=maxprofit(id+1,n,arr);
         int take=INT_MIN;
         if(n>=id+1){
             take=arr[id]+maxprofit(id,n-(id+1),arr);
         }
          return max(take,nottake);
     }
    int cutRod(vector<int> &price) {
        int n=price.size();
       // return maxprofit(0,n,price); 
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));  
          for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                 int nottake=dp[i-1][k]; //nottake.... 
               int take=INT_MIN;
                 if(k>=i){
                     take=price[i-1]+dp[i][k-(i)]; //take..
                }   
                   dp[i][k]= max(take,nottake);  
            }
        } 
        return dp[n][n]; 
        
    }
