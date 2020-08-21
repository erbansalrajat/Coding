#include<bits/stdc++.h>
using namespace std;
void merge(int *arr, int l, int m, int r)
{
	int i,j,k;
	int nl=m-l+1;
	int nr=r-m;
	vector<int> left(nl);
	vector<int> right(nr);
	for(int i=0;i<nl;i++)
	{
		left[i]=arr[l+i];
	}
	for(int j=0;j<nr;j++)
	{
		right[j]=arr[m+1+j];
	}
	i=0;
	j=0;
	k=l;
	while(i<nl&&j<nr)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
		k++;
	}
	 while (i < nl) 
	 { 
        arr[k] = left[i]; 
        i++; 
        k++; 
    } 
    while (j < nr) 
	{ 
        arr[k] = right[j]; 
        j++; 
        k++; 
    } 
}
void mergesort(int *arr, int l,int r)
{
	if(l<r)
	{
	    int left=l;
	    int right=r;
	    int middle=(l+r)/2;
	    mergesort(arr,left,middle);
	    mergesort(arr,middle+1,right);
	    merge(arr,left,middle,right);
    }
}
int main()
{
	int array[]={ 20,10,30,35,25,14,40,12,28 };
	int size=sizeof(array)/sizeof(array[0]);
	mergesort(array,0,size-1);
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
}
