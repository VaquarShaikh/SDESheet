#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

void rotateMatrix(vector<vector<int>>& input){
	stack<vector<int>> s;
	for(int i = 0;i < input.size();i++){
		s.push(input[i]);
	}
	int len = input.size();
	int k = 0;
	input.clear();
	while(!s.empty()){
		vector<int> x = s.top();
		input.push_back(x);
		s.pop();
	}
	for(int i = 0;i < len;i++){
		for(int j = i+1;j < len;j++){
			swap(input[i][j],input[j][i]);
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> input;
	for(int i = 0;i < n;i++){
		vector<int> temp;
		for(int j = 0;j < n;j++){
			int t;
			cin>>t;
			temp.push_back(t);
		}
		input.push_back(temp);
	}
	rotateMatrix(input);
	for(int i = 0;i < input.size();i++){
		for(int j = 0;j < input[i].size();j++){
			cout<<input[i][j]<<" ";
		}cout<<endl;
	}
}