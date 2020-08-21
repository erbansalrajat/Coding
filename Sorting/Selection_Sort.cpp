#include<bits/stdc++.h>
using namespace std;
void selectionsort(int arr[], int size)
{
	int mini;
	int min=INT_MAX;
	for(int i=0;i<size;i++)
	{
		mini=i;
		for(int j=i+1;j<size;j++)
		{
			if(arr[j]<arr[mini])
			{
				mini=j;
			}
		}
		swap(arr[i],arr[mini]);
	}
}
int main()
{
	int array[]={ 20,10,30,35,25,14,40,12,28 };
	int size=sizeof(array)/sizeof(array[0]);
	cout<<size<<endl;
	selectionsort(array,size);
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
}
