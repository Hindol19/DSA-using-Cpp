#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int start, int mid, int end)
{
	int M[end-start+1];
	int idx1=start;
	int idx2=mid+1;
	int t=0,i,j;
	while(idx1<=mid && idx2<=end)
	{
		if(a[idx1]<=a[idx2])
			M[t++]=a[idx1++];
		else
			M[t++]=a[idx2++];
	}
	while(idx1<=mid)
	{
		M[t++]=a[idx1++];
	}
	while(idx2<=end)
	{
		M[t++]=a[idx2++];
	}
	for(i=0,j=start;i<(end-start+1);i++,j++)
	{
		a[j]=M[i];
	}
}

void divide(int a[], int start, int end)
{
	int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		divide(a,start,mid);
		divide(a,mid+1,end);
		merge(a,start,mid,end);
	}
}

void print(int arr[], int len) {
    for(int i=0;i<len;i++)
        printf("%3d",arr[i]);
    cout<<endl;
}

int main() {
    int l;
    int arr[100];
    cout<<"Enter the length of array = ";
    cin>>l;
    for(int i=0;i<l;i++){
        printf("ARR[%d] = ",+i+1);
        cin>>arr[i];
    }
    cout<<"Original array = ";
    print(arr,l);
    divide(arr,0,l-1);
    cout<<"Sorted array = ";
    print(arr,l);
}