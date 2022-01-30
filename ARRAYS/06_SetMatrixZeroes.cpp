#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second


// **********APPROACH***********
// Simply try the O(mn) approach . In this approach , we will simply set the rows and columns to be zeroes we 
// encounter it .

void makeZero(vector<vector<int>>& matrix , int row,int col){
	int r = matrix.size();
	int c = matrix[0].size();
	for(int i = 0;i < c;i++){
		matrix[row][i] = 0;
	}for(int j = 0;j < r;j++){
		matrix[j][col] = 0;
	}
}
void setZeroes(vector<vector<int>>& matrix) {
	vector<pair<int,int>> zeroIndex;
	for(int i = 0 ;i < matrix.size();i++){
		for(int j = 0;j < matrix[0].size();j++){
			if(matrix[i][j] == 0){
				zeroIndex.push_back(make_pair(i,j));
			}
		}
	}
	for(int i = 0;i < zeroIndex.size();i++){
		int row = zeroIndex[i].first;
		int col = zeroIndex[i].second;
		makeZero(matrix , row , col);
	}
}

int main(){
	int m,n;
	cin>>m>>n;
	vector<vector<int>> matrix;
	for(int i = 0;i < m;i++){
		vector<int> row;
		for(int j = 0;j < n;j++){
			int temp;
			cin>>temp;
			row.push_back(temp);
		}
		matrix.push_back(row);
	}
	setZeroes(matrix);
	for(int i = 0;i < matrix.size();i++){
		for(int j =0;j < matrix[i].size();j++){
			cout<<matrix[i][j]<<" ";
		}cout<<endl;
	}
}