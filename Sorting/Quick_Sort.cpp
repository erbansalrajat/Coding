 #include<bits/stdc++.h>
using namespace std;
int partition(int array[], int start, int end)
{
	int pivot=array[end];
	int i=start-1;
	for(int j=start;j<=end-1;j++)
	{
		if(array[j]<pivot)
		{
			i++;
			swap(array[j],array[i]);		
		}
	}
	swap(array[i+1],array[end]);
	return (i+1);
}
void quicksort(int array[], int start, int end)
{
	if(start<end)
	{
		int pi = partition(array, start, end);
		//cout<<pi;
		quicksort(array,start,pi-1);
		quicksort(array,pi+1,end);
	}
}
int main()
{
	int array[]={ 20,10,30,35,25,14,40,12,28 };
	int size=sizeof(array)/sizeof(array[0]);
	quicksort(array,0,size-1);
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
}
