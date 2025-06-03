// in unbounded knapsack we can select element multiple times...
// we will not move forward if we take somthing from  arrays..

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

// there is  a question Shopping Offers in this question we have to do given 
 price array ={}, need array={},offers={{},{},{}} we need to find the minimum cost such that all the item i can buy with frequency
 //    Note :: my item should'nt increase from the given value.... leetcode 638
 class Solution {
public:   
     
       struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t hash = 0;
            for (int num : v) {
                hash = hash * 31 + std::hash<int>()(num);
            }
            return hash;
        }
    };

    
    unordered_map<vector<int>, int, VectorHash> memo;
     int knapsack(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
         if(memo.count(needs))  return memo[needs];
         //now we have to count amount..  
         int minCost=0;
          int n=price.size();
          for(int i=0;i<n;i++){
             minCost+=(price[i]*needs[i]);
          } 

          for(auto &offer:special){ 
               bool flag=true;
              vector<int>newneed(needs);
              for(int i=0;i<n;i++){
                if(newneed[i]<offer[i]) {
                     flag=false; 
                     break;
                }  
                newneed[i]-=offer[i];  
              }    
              if(flag) {
                      int currentCost = offer[n]+knapsack(price,special,newneed);
                      minCost=min(minCost,currentCost);
              }   

          }      
         return   memo[needs] = minCost;   
     }          

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
         return knapsack(price,special,needs);
    }
};  

