#include<bits/stdc++.h>
using namespace std;
void bubblesort(int *array, int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-1-i;j++)
		{
			if(array[j]>array[j+1])
			{
				swap(array[j],array[j+1]);
			}
			else
			{
				continue;
			}
		}
	}
}
int main()
{
	int array[]={ 20,10,30,35,25,14,40,12,28 };
	int size=sizeof(array)/sizeof(array[0]);
	//cout<<size<<endl;
	bubblesort(array,size);
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
}
