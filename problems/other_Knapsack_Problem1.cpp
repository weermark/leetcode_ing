#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
    vector<int> w = {1, 3, 4};
    vector<int> v = {15, 20, 30};
    int bag = 4;

    vector<int> dp(bag + 1, 0);
    // 內層迴圈，物品不變
    for(int i = 0; i < w.size(); i++){
        // 需倒序，否則 dp[j] 之前的值 dp[j-1] ~ dp[0] 先被更改，取值就會錯誤
        for(int j = dp.size(); j >= w[i]; j--){
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    for(int i : dp)
        cout << i << ' ';
}