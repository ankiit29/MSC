#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fun(int n, vector<vector<int>>& jobs, vector<int>& comp, vector<int>& dp) {
    int m = jobs.size();
    
   
    fill(dp.begin(), dp.end(), 0);
    
    
    for (int i = 0; i < m; ++i) {
       
        int take = jobs[i][2];
        if (comp[i] != -1) {
            take += dp[comp[i]]; 
        }

        
        int nottake = (i > 0) ? dp[i - 1] : 0;

        
        dp[i] = max(take, nottake);
    }
    
   
    return dp[m - 1];
}

int main() {
    
    vector<vector<int>> jobs = {
        {1, 3, 50},  
        {4, 6, 70},
        {6, 7, 30},
        {5, 8, 60}
    };
    
    int n = jobs.size();
    
    
    sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; 

   
    vector<int> comp(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (jobs[i][1] <= jobs[j][0]) {  
                comp[i] = j;
                break;
            }
        }
    }

    
    vector<int> dp(n, 0);  
    
    int result = fun(0, jobs, comp, dp);

    
    cout << "Maximum Profit: " << result << endl;
    
    return 0;
}

