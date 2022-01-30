#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

// f - start
// s - end

bool compare(pair<int,int> a, pair<int,int> b){
	return a.f < b.f;
}

vector<pair<int,int>> mergeIntervals(vector<pair<int,int>>& input){
	sort(input.begin() , input.end() , compare);
	stack<pair<int,int>> s;
	s.push(input[0]);
	for(int i = 1;i < input.size();i++){
		pair<int,int> top = s.top();
		// f - start
		// s - end
		//condition to not merge and simply push
		if(input[i].f > top.s){
			s.push(input[i]);
		}
		//condition to merge 
		else if(input[i].s > top.s){
			top.s = input[i].s;
			s.pop();
			s.push(top);
		}
	}
	vector<pair<int,int>> res;
		//empty the stack inside the vector
		while(!s.empty()){
			pair<int,int> top = s.top();
			res.push_back(top);
			s.pop();
		}
		//sort the vector and return
		sort(res.begin() , res.end() , compare);
		return res;
}

int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> input;
	for(int i = 0;i < n;i++){
		int start,end;
		cin>>start>>end;
		input.push_back(make_pair(start,end));
	}	
	vector<pair<int,int>> ans = mergeIntervals(input);
	for(int i = 0;i < ans.size();i++){
		cout<<ans[i].f<<" "<<ans[i].s<<endl;
	}
}

// 4
// 1 3
// 2 6
// 8 10
// 15 18
