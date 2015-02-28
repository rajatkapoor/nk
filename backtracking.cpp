#include <iostream>
using namespace std;

//Generate all string of n bits
// k is used to keep count of the length of the actual string 
// only use is to print the string in the for loop
// can be dropeed off in case we know the length already
int Binary(int *a,int n,int k)
{	
	if(n<1)
	{
		for(int i=0; i<k; i++)
			cout<<a[i];
		cout<<endl;
	}

	else
	{
		
		a[n-1] = 0;
		Binary(a,n-1,k);
		a[n-1] = 1;
		Binary(a,n-1,k);

	}
}

int main()
{
	int a[5];
	Binary(a,5,5);
}