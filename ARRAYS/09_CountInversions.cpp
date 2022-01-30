#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second


int merge(vector<int>& input , int left , int mid , int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	vector<int> leftarr(n1);
	vector<int> rightarr(n2);
	int invCount = 0;
	for(int i = 0;i < n1;i++){
		leftarr[i] = input[left + i];
	}
	for(int i = 0;i < n2;i++){
		rightarr[i] = input[mid + 1 + i];
	}
	int i = 0, j = 0, k = left ;
	while(i < n1 && j < n2){
		if(leftarr[i] <= rightarr[j]){
			input[k] = leftarr[i];
			i++;
		}else{
			input[k] = rightarr[j];
			invCount += (mid - i + 1);
			j++;
		}
		k++;
	}

	while(i < n1){
		input[k] = leftarr[i];
		k++;
		i++;
	}while(j < n2){
		input[k] = rightarr[j];
		j++;
		k++;
	}
	return invCount;
}



int mergeSortHelper(vector<int>& input , int left , int right){
	if(left >= right){
		return 0;
	}

	int mid = left + (right - left)/2;
	int lic = mergeSortHelper(input , left , mid);
	int mic = mergeSortHelper(input , mid + 1 , right);
	int ric = merge(input , left , mid , right);
	return lic + mic + ric;

}


int mergeSort(vector<int>& input){
	int n = input.size();
	return mergeSortHelper(input , 0 , n - 1);
}


int main(){
	int n;
	cin>>n;
	vector<int> input;
	for(int i = 0;i < n;i++){
		int temp;
		cin>>temp;
		input.push_back(temp);
	}	

	cout<<mergeSort(input);
	// for(int i = 0;i < input.size();i++){
	// 	cout<<input[i]<<" ";
	// }
}