// CPP program to convert string
// to char array
#include <iostream>
#include <string.h>

using namespace std;

// driver code
int main()
{
  string s;
  cout << "Enter the string" << endl;
	getline(cin,s);
	char p[s.length()];
	int i,j;
	for (i = 0; i < s.length(); i++) {
    if (s[i]==' '){

      p[i] = '%';
      p[i-1] = '2';
      p[i-2] = '0';
      cout << p[i];
      cout << p[i-1];
      cout << p[i-2];
    }
    else{
    p[i] = s[i];
    cout << p[i];
	}
  // cout << p[i];
}

	return 0;
}
