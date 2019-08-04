/*

Question :

Starting from coordinate (0,0)
step 1: turn right and go a distance of 	10
step 2: turn upwards and go a distance of 	20
step 3: turn left and go a distance of 		30
step 4: turn downwards and go a distance of 40
step 5: turn right and go a distance of 	50
and so on upto n th turn

Given the value of n ( 2 < n < 1000 ), find out the final coordinate.

example 1:
Input 
3
Output
20,-20

example 2:
Input 
4
Output
-20,-20

*/

#include<iostream>
#include <time.h>
using namespace std;

void naive(int n){

	// time complexity O(n)

	clock_t t; 
    t = clock();
	int i,x=0,y=0;

	for (i=1;i<n+1;i++){
		if(i%4==1) {
			x+=i*10;
			// cout << i << " = " << x << " , " << y << " , x+" << i*10 << " , 1" << endl;
		}
		else if(i%4==2) {
			y+=i*10;
			// cout << i << " = " << x << " , " << y << " , y+" << i*10 << " , 2" << endl;
		}
		else if(i%4==3) {
			x-=i*10;
			// cout << i << " = " << x << " , " << y << " , x-" << i*10 << " , 3" << endl;
		}
		else if(i%4==0) {
			y-=i*10;
			// cout << i << " = " << x << " , " << y << " , y-" << i*10 << " , 4" << endl;
		}
	}
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
	cout << n << " = (" << x << "," << y << ")" << endl;
	cout << "naive approach took " << time_taken << " seconds to execute" << endl;
	return;
}

void formula(int n){

	// time complexity O(1)

	clock_t t; 
    t = clock();
    int x,y;

    if (n%4==1){
    	x = ((n+(4-n%4)) /2*10 )-10;
    	y = (-1)*(((n+(4-n%4)) /2*10 )-20);
    }
	else if(n%4==2) {
		x = ((n+(4-n%4)) /2*10 )-10;
    	y = ((n+(4-n%4)) /2*10 );
	}
	else if(n%4==3) {
		x = (-1)*( (n+(4-n%4)) /2*10 );
    	y = ( (n+(4-n%4)) /2*10 );
	}
	else if(n%4==0) {
		x = (-1)*( n/2*10 );
    	y = (-1)*( n/2*10 );
	}
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
	cout << n << " = (" << x << "," << y << ")" << endl;
	cout << "formula approach took " << time_taken << " seconds to execute" << endl;
	return;
}

int main(){
	int n;
	cout << "Enter number of turns: ";
	cin >> n;
	formula(n);
	naive(n);
	return 0;
}