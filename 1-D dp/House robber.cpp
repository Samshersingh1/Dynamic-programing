//here is the problem 
/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money 
stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last
 one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if 
 two adjacent houses were broken into on the same night.Given an integer array nums representing the amount of money
  of each house, return the maximum amount of money you can rob tonight without alerting the police.*/   



  //TO SOLVE THIS PROBLEM WE HACEW TO WORK SMARTLY THIS WAS 
  //THE EXTENTION OF THE HOUSE ROBBER 1 PROBLEM IN THIS WE HAVE NOT TO TAKE FIRST IN WE TAKE LAST AND VICE VERSA 
  //OUR ANSWER WILL NOT CONTAINS FIRST AND LAST ELEMNT TOGERTHER SO DOING SPREATLY WORKS 
  // FIRST (0 TO N-2) THEN (1 TO N-1) THEN RETURN MAX  OF THESE 2

  #include<bits/stdc++.h>
  using namespace std;   
    
  int MaxProfit(int id,vector<int>&nums, vector<int>&dp1){
    if(id==0) return nums[0];
    if(id<0) return 0;
     if(dp1[id]!=-1) return dp1[id];
  int nottake=MaxProfit(id-1,nums,dp1); 
    int  take=nums[id]+MaxProfit(id-2,nums,dp1); 
   
  return dp1[id]=max(take,nottake); 
  }  

    int MaxAmount(vector<int>&nums){ 
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>nums1,nums2;
         for(int i=0;i<n;i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=n-1) nums2.push_back(nums[i]);
         } 
        int p=nums1.size();
        int q=nums2.size(); 
        vector<int>dp1(p,-1);
        vector<int>dp2(q,-1);
      long long  int a= MaxProfit(p-1,nums1,dp1);  
       long long  int b=MaxProfit(q-1,nums2,dp2);    
        
        return (a>b)?a:b;        

    }   

  int main(){ 
      int n;
      cin>>n;
    vector<int>arr(n); 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 

     return MaxAmount(arr);

  } 

  //TC:: O(N)
  //SC:: O(3N)+O(N) RECURSIVE STACK USE  HUA HAI 


 