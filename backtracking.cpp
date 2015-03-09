#include <iostream>
using namespace std;

//Generate all string of n bits
// c is used to keep count of the length of the actual string 
// only use is to print the string in the for loop.
// The actual length of the string is passed through the recursion unchanged,
// using this variable c
// can be dropeed off in case we know the length already
int Binary(int *a,int n,int c)
{	
	int i;
	if(n<1)
	{
		//print array
		for(i=0; i<c; i++)
			cout<<a[i];
		cout<<endl;
	}
	else
	{
		a[n-1] = 1;
		Binary(a,n-1,c);
		a[n-1] = 0;
		Binary(a,n-1,c);
	}
}

// Generate all k-ary string of length n
int kary(int *a, int n, int k, int c)
{
	int i;
	if(n<1)
	{
		//print array
		for(i=0; i<c; i++)
			cout<<a[i];
		cout<<endl;
	}
	else
	{
		for(i=0; i<k; i++)
		{	
			a[n-1] = i;
			kary(a,n-1,k,c);
		}
	}
}
int main()
{
	int a[5];
	cout<<"Binary Strings\n";
	Binary(a,5,5);//binary string of length 5
	cout<<"K-ary Strings \n";
	kary(a,3,4,3);// prints allstring of length 3 containing 0,1,2,3
}