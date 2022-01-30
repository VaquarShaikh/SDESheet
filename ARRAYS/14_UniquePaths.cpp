#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second


int uniquePaths(int m , int n){
	if(m == 1 && n == 1){
		return 1;
	}
	int** output = new int*[m];
	for(int i = 0;i < m;i++){
		output[i] = new int[n];
		for(int j = 0;j < n;j++){
			output[i][j] = 0;
		}
	}
	for(int i = n - 2;i >= 0;i--){
		output[m-1][i] = 1;
	}
	for(int i = m-2;i >= 0;i--){
		output[i][n-1] = 1;
	}
	for(int i = m-2;i >= 0;i--){
		for(int j = n-2;j >= 0;j--){
			output[i][j] = output[i+1][j] + output[i][j+1];
		}
	}
	return output[0][0];
}


int main(){
	int m,n;
	cin>>m>>n;
	cout<<uniquePaths(m,n);
}