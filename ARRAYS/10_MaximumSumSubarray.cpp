#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

int maxSubArray(vector<int>& nums){
	int curr = 0 , maxTillNow = 0;
	for(int i = 0;i < nums.size();i++){
		curr += nums[i];
		maxTillNow = max(maxTillNow , curr);
		if(curr < 0){
			curr = 0;
		}
	}
	return maxTillNow;
}


int main(){
	int n;
	cin>>n;
	vector<int> nums;
	for(int i = 0;i < n;i++){
		int temp;
		cin>>temp;
		nums.push_back(temp);		
	}	

	cout<<maxSubArray(nums)<<endl;
}