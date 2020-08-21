#include<bits/stdc++.h>
using namespace std;
void insertionsort(int array[], int size)
{
	int i,j,key;
	for(i=1;i<size;i++)
	{
		key=array[i];
		j=i-1;
		while(j>=0 && array[j]>key)
		{
			array[j+1]=array[j];
			j=j-1;
		}
		array[j+1]=key;
	}
}
int main()
{
	int array[]={ 20,10,30,35,25,14,40,12,28 };
	int size=sizeof(array)/sizeof(array[0]);
	cout<<size<<endl;
	insertionsort(array,size);
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
}
