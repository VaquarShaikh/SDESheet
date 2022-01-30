#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second


int maxProfit(vector<int>& prices){
	int len = prices.size();
	int i = 0, j = 1,ans = 0;
	while(j < len){
		int diff = (prices[j] - prices[i]);
		if(diff > ans){
			ans = diff;
			j++;
		}else if(diff > 0){
			j++;
		}else{
			i = j;
			j++;
		}
	}
	return ans;
}


int main(){
	int n;
	cin>>n;
	vector<int> prices;
	for(int i = 0;i < n;i++){
		int temp;
		cin>>temp;
		prices.push_back(temp);
	}	
	cout<<maxProfit(prices)<<endl;
}