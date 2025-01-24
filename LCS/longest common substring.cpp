//we are given two string we have to find the longest common substring lenth...

//input s1="abcdef",s2="bde";
//output=2;

#include<bits/stdc++.h>
using namespace  std;

 void fun(int i,int j,string s1,string s2,int c,int ans){
       if(i>=s1.size() || j>=s2.size()) return ; 

       if(s1[i]==s2[j]){
         c++;
         ans=max(ans,c); 
        fun(i+1,j+1,s1,s2,c,ans); 
       }  
       else{
        fun(i+1,j,s1,s2,0,ans);
        fun(i,j+1,s1,s2,0,ans); 
       } 
  }  
int main(){
    string s1="abdef";
    string s2="bce"; 
    int ans=0,c=0;
      fun(0,0,s1,s2,c,ans); 
    cout<<ans;
} 