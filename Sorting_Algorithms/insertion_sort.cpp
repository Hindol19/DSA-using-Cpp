#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int len) {
    for(int i=1;i<len;i++) {
        int j=i-1;
        int key=arr[i];
        //right shifting the sorted array to accomodate unsorted element
        while(j>=0 && key<arr[j]) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    insertionSort(arr,l);
    cout<<"Sorted array = ";
    print(arr,l);
}