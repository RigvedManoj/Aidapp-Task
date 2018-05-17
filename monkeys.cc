#include <bits/stdc++.h>
using namespace std;
/* To do this in O(n) time that is with just one for loop,we have to find the max subarray which 
satisfies the given conditions (ie) sum<2000 and product<1000000.
For that find the first subaaray which exceeds these cases starting from first element.
Add next element while subtracting the first element from it, do this every time the conditions are overshot. 
*/
int main()
{
	int n,health=2000,damage=1000000;

	//To read value from file
	ifstream myReadFile;
 	myReadFile.open("input.txt");
    myReadFile >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    	myReadFile >> a[i];
	myReadFile.close();

	//Declaring Required Variables
	int sum=0,k=0,product=1,count=0,max=0,repcount=0;
	// Starting For Loop
	for(int i=0;i<n;i++)
	{
		//Add element to sum and multiply to product
		sum+=a[i];
		product*=a[i];

		//Check for overshoot
		if(sum<health && product<damage)
		{
			count++;
		}
		else
		{
			//if overshot subtract starting element from sum and divide from product
			sum-=a[k];
			product/=a[k];

			//check if the newly formed subarray satisfies conditions
			if(max==count && (sum<health && product<damage))
				repcount++;

			//setting max to count
			max=count;
			k++;
		}
	}
	cout<<max<<" "<<repcount<<endl;
} 