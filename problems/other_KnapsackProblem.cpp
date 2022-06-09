#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void printdp(vector<vector<int>>& dp){
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    vector<int> w = {1, 3, 4};
    vector<int> v = {15, 20, 30};
    int bag = 4;
    vector<vector<int>> dp(w.size(), vector<int>(bag + 1, 0));
    // init
    for(int i = 0; i < w.size(); i++){
        dp[i][0] = 0;
    }
    
    for(int j = 0; j < w[0]; j++){
        dp[0][j] = 0;
    }
    for(int j = w[0]; j <= bag; j++){
        dp[0][j] = v[0];
    }
    printdp(dp);

    // transfer
    for(int i = 1; i < dp.size(); i++){
        for(int j = 1; j < dp[0].size(); j++){
            if(j < w[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    
    // finish
    printdp(dp);


}