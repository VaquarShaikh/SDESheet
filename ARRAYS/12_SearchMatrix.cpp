#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

// bool bSearch(vector<int>& matrix , int start , int end ,int target){
// 	bool res = false;
// 	if(start >= end){
// 		res = false;
// 	}
// 	int mid = start + (end - start)/2;
// 	if(matrix[mid] == target){
// 		res = true;
// 	}
// 	if(mid > target){
// 		res = bSearch(matrix , start , mid - 1 , target);
// 	}else{
// 		res = bSearch(matrix , mid + 1 , end , target);
// 	}
// 	return res;
// }

bool searchMatrix(vector<vector<int>>& matrix , int target){
	bool res = false;
	int interval = 0;
	for(int i = 0;i < matrix.size();i++){
		if(target >= matrix[i][0] && target <= matrix[i][matrix[i].size() - 1]){
			interval = i;
			res = true;
		}
	}
	if(res){
		res = false;
		for(int i = 0 ; i < matrix[interval].size();i++){
			if(matrix[interval][i] == target){
				res = true;
			}
		}
	}
	return res;
}


int main(){
	int n,m,target;
	cin>>n>>m;
	vector<vector<int>> matrix;
	for(int i = 0;i < n;i++){
		vector<int> row;	
		for(int i = 0;i < m;i++){
			int temp;
			cin>>temp;
			row.push_back(temp);
		}
		matrix.push_back(row);
	}	
	cin>>target;
	if(searchMatrix(matrix , target)){
		cout<<"True";
	}else{
		cout<<"False";
	}
}

// 3 4
// 1 3 5 7
// 10 11 16 20
// 23 30 34 60