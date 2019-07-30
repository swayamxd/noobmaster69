*Readme will be updated once the program runs*

``` c++
# include<iostream>
# include<vector>
# include<algorithm>

using namespace std;

int main(){
	int testCases;
	cin >> testCases;
	// testCases = 1;
	for(int testCase=0;testCase<testCases;testCase++){
		int n,c,temp,mid;
		cin >> n >> c;
		
		vector<int> v;
		// n = 5;
		// c = 3;
		// v = {1,2,8,4,9};
		for(int stalls=0;stalls<n;stalls++){
			cin >> temp;
			v.push_back(temp);
		}
		
		// for (auto x:v) cout << x << " ";
		// cout << endl;
		sort(v.begin(),v.end());
		// for (auto x:v) cout << x << " ";
		// cout << endl;
		
		int low = 0;
		int high = n-1;
		int minimum = v[high] - v[low];

		for(int cow=2;cow<c;cow++){
			mid = low+(high-low)/2;

			// cout << v[low]<<", " << v[mid] <<", "<< v[high] <<", "<< minimum << endl;
			
			minimum = min( (v[mid] - v[low]) ,minimum);
			if(minimum == (v[mid] - v[low])){
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}
		cout << minimum << endl;
	}
	return 0;
}
```