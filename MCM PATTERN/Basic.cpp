 

 /* 
    HERE ARE SOME BASIC STEPS TO RECONGNISE A MCM PROBLEM IN DYNAMIC PROGRAMING....  
    1. there will be a partition on array or string....(feel aayegi partition karne ki..)
    2. diffrent type of value in the expression ...(2*3+5-10)? 
    3. most optimal order to partition an array for min/max cost..
    4. check whether an expresion cna be true or not...
 */   


/* 
  STEP TO SOLVE ANY MCM BASED QUESTON ...
  
  step 1 :: recongnise boundry where we have to do partition (i,j) genearrly it will be (0,n-1) but not all the time may be varry question by question
  step 2::  check base case least optimal solution....
  step 3 :: k-loop (i to j but it will differ question wise )  ..IMP STEP..
  step 4::  find ans from temp ans by doing max(ans,tmep)(generally)..   */  

  
  