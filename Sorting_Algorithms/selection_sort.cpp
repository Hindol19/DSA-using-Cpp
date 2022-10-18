#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void selectionSort(int arr[], int len) {
    for(int i=0;i<len-1;i++) {
        int minIndex=i;
        for(int j=i+1;j<len;j++) {
            if(arr[minIndex]>arr[j])
                minIndex=j;
        }
        swap(arr,minIndex,i);
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
    selectionSort(arr,l);
    cout<<"Sorted array = ";
    print(arr,l);
}