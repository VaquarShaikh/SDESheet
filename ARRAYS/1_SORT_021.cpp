#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

// basic approach that came in to my mind.
// Simply count the number of zeroes ones and twos.
// Update the value of the array accordingly.
void sortColors1(vector<int>& nums){
	int n = nums.size();
	int c0 = 0,c1 = 0,c2 = 0;
	for(int i = 0;i < n;i++){
		if(nums[i] == 0){
			c0++;
		}else if(nums[i] == 1){
			c1++;
		}else{
			c2++;
		}
	}
	for(int i = 0;i < c0;i++){
		nums[i] = 0;
	}
	for(int i = c0;i < c0 + c1;i++){
		nums[i] = 1;
	}
	for(int i = c0 + c1;i < c0 + c1 + c2;i++){
		nums[i] = 2;
	}
}

// dutch flag algorithm.
// ********BASIC INTUTION**********
// basic intution behind the approach is to sort any of the two
// numbers . In this case we have decided 0 and 2 .
// if we sort these numbers i.e place them on their positions 
// accordingly , we get the third number already sorted in its 
// place .

// ********APPROACH**********
// We must use three pointers . low , mid and high . 
// elements in 0 to low are zero , mid to high are two 
// ahead of high are unknown .
// We check the element which is positioned at the middle iterator .
// if it is 1 , we do nothing , if it is zero , we swap the element at low and mid.
// If the element is two , we swap the elements at mid and high .
// We decrement the high value after swapping for two , increment only m if we encounter a 1
// We simply increment both l and mid if we encounter a zero
// if zero then low , if 2 then high . 
// The loop must not run when mid becomes more than high.

void sortColors(vector<int>& nums){
	int n = nums.size();
	int l = 0,m = 0,h = n - 1;
	while(m <= h){
		if(nums[m] == 0){
			swap(nums[l],nums[m]);
			l++;
			m++;
		}else if (nums[m] == 1){
			m++;
		}else{
			swap(nums[m] , nums[h]);
			h--;
		}
		// m++;
	}
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
	// sortColors1(nums);
	sortColors(nums);
	for(int i = 0;i < n;i++){
		cout<<nums[i]<<" ";
	}
}