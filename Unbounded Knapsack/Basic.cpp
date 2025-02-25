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
