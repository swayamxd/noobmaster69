#include<iostream>
using namespace std;
int main(){
	int abcde,fghij,tmp,used,n;//abcde is the first num, and fghij is 2nd num
	cin>>n;//input taken
	for(fghij=1234;fghij<=98765/n;fghij++){
		abcde=fghij*n;
		used=(fghij<10000);//used is a flag variable which stores 0 and 1 and has special purpose which will be discussed later in the code
	
		
	//check if abcde and fghij contains all the digits from 0 to 9
	/*
	    used variable in initialized with  _ _ _ _ _ _ _ _ _ 0 if fghij is 4 digit number i.e the first digit of fghij contains 0
	    					else with  _ _ _ _ _ _ _ _ _ 1 if fghij is 5 digit number(the blanks contains zeroes actually) */
		tmp=fghij;
		while(tmp)
		{
			used|=1<<(tmp%10);
			tmp=tmp/10;
		}
		/* in the above while loop used variable contains 1 in the positions of the digits.
				for example, if fghij = 62940 then used will have 1s in 6th,9th,4th,2nd and 0th positions
				so, used = 1001010101  */
		tmp=abcde;
		while(tmp)
		{
			used|=1<<(tmp%10);
			tmp=tmp/10;
		}
			/* in the above while loop 
				for example, if abcde = 13578 then used will have 1s in 1st,3rd,5th,7th and 8th positions
				previously used = 1001010101
				now after 2nd while loop
				used=1111111111.
				Now if used contains all 10 ones it means the two numbers abcde and fghij contains all digits from 0 to 9 without repeatations  */
		if(used==(1<<10)-1)//cheks if used is equl to 1111111111. if yes the prints the numbers
		 cout<<abcde<<" "<<fghij<<"\n";
	}
	
}
