#include<bits/stdc++.h>
using namespace std;

bool insert(string a,string b){
	int i = 0;
	int j = 0;
	while (i < a.length() && j < b.length()){
		if(a[i] != b[j]){
			if(i != j){
				return false;
			}
			j++;
		}
		else{
			i++;j++;
		}
	}
	return true;
}

bool replace(string a, string b){
	bool difference = false;
	for (int i = 0;i < a.length();i++){
		if (a[i] != b[i]){
			if(difference){
				return false;
			}
			difference = true;
		}
	}
	return true;
}

bool oneeditaway(string a, string b){
	if(a.length() == b.length()){
		return replace(a,b);
	}
	else if(a.length()+1==b.length()){
        return insert(a,b);
    } else if(a.length()-1==b.length()){
        return insert(b,a);
    }
    return false;
}

int main(){
    string a,b;
    cout << "Enter two strings:\n";
    cin >> a >> b;
    if (oneeditaway(a,b)){
        cout << "One edit away" <<endl;
    } else {
        cout << "ERROR" <<endl;
    }
    return 0;
}
