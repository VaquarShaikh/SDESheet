#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

int fact(int n)
{
	return (n==1 || n==0) ? 1: n * fact(n - 1);
}

int nCr(int n,int r){
	int numer = fact(n); 
	int deno = fact(n - r) * fact(r);
	int res = numer/deno;
	return res;
}

// vector<vector<int>> generate(int numRows){
// 	vector<vector<int>> ans;
// 	for(int i = 0;i < numRows + 1;i++){
// 		vector<int> row;
// 		for(int j = 0;j <= i;j++){
// 			int temp = nCr(i , j);
// 			row.push_back(temp);
// 		}
// 		ans.push_back(row);
// 	}
// 	return ans;
// }


vector<vector<int>> generate(int numRows) {
	vector<vector<int>> res;
	for(int i = 1;i <= numRows;i++){
		int c = 1;
		vector<int> temp;
		for(int j = 1;j <= i;j++){
			temp.push_back(c);
			c = c*(i - j)/j;
		}
		res.push_back(temp);
	}
	return res;
}



int main(){
	int numRows;
	cin>>numRows;
	vector<vector<int>> res = generate(30);
	for(int i = 0;i < numRows;i++){
		for(int j = 0;j < res[i].size();j++){
			cout<<res[i][j]<<" ";
		}cout<<endl;
	}	

	// for(int i = 0;i <= numRows;i++){
	// 	cout<<nCr(numRows, i)<<" ";
	// }
}