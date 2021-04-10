#include <iostream>

using namespace std;

// Recursive
int countWays(int steps){
    if(steps == 0 || steps == 1 || steps == 2){
        return steps == 0 || steps == 1 ? 1 : 2;
    }
    
    return countWays(steps - 1) + countWays(steps - 2) + countWays(steps - 3);
}

// Iterative
int main() {
    int T;
    cin>>T;
    
    while(T--){
        int n;
        cin>>n;
        
        int dp[n + 1];
        
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3;i <= n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        
        cout<<dp[n]<<"\n";
    }
}
