#include<iostream>
using namespace std;

// Whenever elements of the array are from 1 to N
void swap(int arr[], int i, int j) {
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void cyclicSort(int arr[], int len) {
    int i = 0;
        while (i < len) {
            if (arr[i] != i + 1) {
                swap(arr, i, arr[i]-1);
            } else
                i++;
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
    cyclicSort(arr,l);
    cout<<"Sorted array = ";
    print(arr,l);
}