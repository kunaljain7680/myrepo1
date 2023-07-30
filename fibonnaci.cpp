#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int fibo(int n,vector<int>&dp){

    if(n<=1){
        return n;
    }

    if(dp[n]!=-1) return dp[n];

    return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);   // here there are overlapping subproblems (i.e some subproblems evaluated again and again)
}

int main(){

    // normal recursion way

    // int n;
    // cin>>n;

    // return fibo(n);


    //  so to overcome overlapping subproblems use memoization: we tend to store the value of subproblems in some map/table

    // here 1 parameter so use 1-d array

    // MEMOIZATION (top -down) steps:

    // 1) declare dp array of size n+1 ,considering size of subproblems repeated subproblems will be constant time

    // 2) the value of f(n) is f(n-1)+f(n-2) should be stored in dp[n] in case of fibo . simply answer of subproblem must be put in dp[n]

    // 3) whenever calling new subproblems ,chefck if current subproblem is not solved first i.e dp[n]=-1 ,if yes then call subproblems or else not

    // t.c: O(N)  as linear calling

    // s.c: O(N)+O(N) as recursion stack space + dp array space

    // int n;
    // cin>>n;

    // vector<int>dp(n+1,-1);

    // cout<<fibo(n,dp);


// TABULATION (bottom-up) means base case to required 

// 1) intialize dp[n+1]

// 2) base case dp[0]=0,dp[1]=1, in case of fibonnaci 

// 3) go back to recursion relationship convert to tabulation form i.e in form of loop

// 4) t.c: O(N)

//    s.c :O(N): only loop space no recursion stack space


// here it is


int n;
cin>>n;

// vector<int>dp(n+1,-1);

// dp[0]=0;

// dp[1]=1;

// for(int i=2;i<=n;i++){
//     dp[i]=dp[i-1]+dp[i-2];
// }

// cout<<dp[n];


//  now use tabulation with space optimiztion
// use two pointers prev and prev2 which will be mostly used in dp

// T.C: O(N)  : for loop
// S.C: O(1) : as only variables used


int prev2=0;
int prev=1;

for(int i=2;i<=n;i++){
    int curi=prev+prev2;
    prev2=prev;
    prev=curi;
}

cout<<prev;
    
}