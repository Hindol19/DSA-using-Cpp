#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int h)
{
	int id=l-1;
	int t,i;
	for(i=l; i<h;i++)
	{
		if(a[i]<a[h])
		{
			id++;
			t=a[id];
			a[id]=a[i];
			a[i]=t;
		}
	}
	id++;
	t=a[id];
	a[id]=a[h];
	a[h]=t;
	return id;
}

void quickSort(int a[], int l, int h)
{
	int p;
	if(l<h)
	{
		p=partition(a,l,h);
		quickSort(a,l,p-1);
		quickSort(a,p+1,h);
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
    quickSort(arr,0,l-1);
    cout<<"Sorted array = ";
    print(arr,l);
}