#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int i=0,c,s,j,sum=0,ib=0;
	
	scanf("%d %d\n",&c,&s);
	int m[2*c];
	string str;
	getline(cin,str);
	stringstream ss(str);
	while(! ss.eof()){
		ss>>m[i];
		i++;
	}
	int d=2*c-s;
	for(j=0;j<i;j++)
		sum=sum+m[j];
	sum=sum/c;
	while(d!=0){
		m[i]=0;
		i++;
		d--;
	}
	int n=sizeof(m)/sizeof(m[0]);
	sort(m,m+n);
	for(i=0,j=(2*c)-1;i<j;i++,j--){
		if(m[i]==0)
		{
			printf("%d: %d\n",i,m[j]);
			ib=ib+abs(m[j]-sum);
		}
		else
		{
			printf("%d: %d %d\n",i,m[i],m[j]);
			ib=ib+abs(m[i]+m[j]-sum);
		}
	}
	printf("imbalance: %d",ib);

	return 0;
}

