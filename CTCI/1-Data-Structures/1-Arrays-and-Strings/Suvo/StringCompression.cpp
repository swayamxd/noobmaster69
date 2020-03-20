#include<bits/stdc++.h>
using namespace std;

int main(){
	string a;
	cout << "Enter the string :"<< endl;
	cin >> a;
	cout << "Compressed String is : ";
	int flag = 1;
	for(int i=0;i<a.length();i++){
		if (a[i+1]==a[i]){
			flag++;
		}
		else{
			cout << a[i] << flag;
			flag = 1;
		}
	}
	return 0;
}
