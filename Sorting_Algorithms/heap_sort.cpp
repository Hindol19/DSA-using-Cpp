#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int n) {
	for(int i=1;i<=n;i++) {
		printf("%3d",arr[i]);
	}
	cout<<endl;
}

void adjustHeap(int arr[],int i, int n) {
	int j=2*i;
	int key=arr[i];
	while(j<=n) {
		if(j<n && arr[j]<arr[j+1])
			j++;
		if(arr[j]<key)
			break;
		arr[j/2]=arr[j];
		j=j*2;
	}
	arr[j/2]=key;
}

void createHeap(int arr[], int n) {
	for(int i=n/2;i>=1;i--)
		adjustHeap(arr,i,n);
}

void heapSort(int arr[], int n) {
	createHeap(arr,n);
	for(int i=n;i>=2;i--) {
		int temp=arr[1];
		arr[1]=arr[i];
		arr[i]=temp;
		adjustHeap(arr,1,i-1);
	}
}

int main() {
	int n;
	cout<<"Enter the size = ";
	cin>>n;
	int *arr=new int[n+1];
	for(int i=1;i<=n;i++) {
		printf("ARR[%d] = ",i);
		cin>>arr[i];
	}
	cout<<"Original Array = ";
	display(arr,n);
	heapSort(arr,n);
	cout<<"Sorted Array = ";
	display(arr,n);
}