#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second


int calculateMinimumHP(vector<vector<int>>& dungeon){
    /*
        dp[i][j] stores the minimum strength required to reach 
        bottom right corner of grid from the index (i, j)
    */
	int n = dungeon.size();
	int m = dungeon[0].size();
	int **dp = new int*[n + 1];

	for (int i = 0; i <= n; ++i) {
		dp[i] = new int[m + 1];

		for (int j = 0; j <= m; ++j) {
			dp[i][j] = INT_MAX;
		}
	}

	dp[n][m - 1] = 1;
	dp[n - 1][m] = 1;

	for (int i = n - 1; i >= 0; --i) {

		for (int j = m - 1; j >= 0; --j) {
            // 'neededStrength' stores the minimum strength needed to survive
			int neededStrength = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
			dp[i][j] = (neededStrength <= 0) ? 1 : neededStrength;
		}

	}

	int ans = dp[0][0];
	
	for (int i = 0; i <= n; ++i) {
		delete[] dp[i];
	}

	delete[] dp;

	return ans;
}



int main(){
	int m,n;
	cin>>m>>n;
	vector<vector<int>> dungeon;
	for(int i = 0;i < m;i++){
		vector<int> row;
		for(int i = 0;i < n;i++){
			int temp;
			cin>>temp;
			row.push_back(temp);
		}
	}	
	cout<<calculateMinimumHP(dungeon)<<endl;
}