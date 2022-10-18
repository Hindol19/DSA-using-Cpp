#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void bubbleSort(int arr[], int len) {
    for(int i=0;i<len-1;i++) {
        int flag=0;
        for(int j=0;j<len-1-i;j++) {
            if(arr[j]>arr[j+1]) {
                flag=1;
                swap(arr,j,j+1);
            }
        }
        if(flag==0)
            break;
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
    bubbleSort(arr,l);
    cout<<"Sorted array = ";
    print(arr,l);
}