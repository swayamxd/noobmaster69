
#include<bits/stdc++.h>
using namespace std;

bool isPermutationPalindrome(string str)
{
    int count[128] = {0};
    for (int i = 0; i < str.length();  i++)
      if(str[i] != ' '){
        count[str[i]]++;
      }

    int odd = 0;
    for (int i = 0; i < 128; i++)
    {
        if (count[i] & 1)
            odd++;

        if (odd > 1)
            return false;
    }
    return true;
}

int main()
{
  string str;
  cout << "Enter the string" << endl;
  getline(cin,str);
  if (isPermutationPalindrome(str)){
      cout << "True" << endl;
  }
  else {
  	cout << "False"<< endl;
  }
  return 0;
}
