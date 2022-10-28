#include<bits/stdc++.h>
using namespace std;

int getMaximum(int arr[], int len) {
    int maximum=arr[0];
    for(int i=1;i<len;i++) {
        if(arr[i]>maximum)
            maximum=arr[i];
    }
    return(maximum);
}

void countingSort(int arr[],int len) {
    int maxEle=getMaximum(arr,len);
    int *count=(int*)calloc(1+maxEle,sizeof(int));
    int *outputArr=(int*)calloc(len,sizeof(int));
    for(int i=0;i<len;i++) {        //freq of each numbers
        count[arr[i]]++;
    }
    for(int i=1;i<=maxEle;i++) {     //relative address
        count[i]+=count[i-1];
    }
    for(int i=len-1;i>=0;i--) {     //placing elements in order
        int index=count[arr[i]]-1;
        count[arr[i]]--;
        outputArr[index]=arr[i];
    }
    for(int i=0;i<len;i++) {        //copy from output array to original array
        arr[i]=outputArr[i];
    }
}

void print(int arr[], int len) {
    for(int i=0;i<len;i++)
        printf("%3d",arr[i]);
    cout<<endl;
}

int main() {
    int l;
    cout<<"Enter the length of array = ";
    cin>>l;
    int *arr=new int[l];
    for(int i=0;i<l;i++){
        printf("ARR[%d] = ",+i+1);
        cin>>arr[i];
    }
    cout<<"Original array = ";
    print(arr,l);
    countingSort(arr,l);
    cout<<"Sorted array = ";
    print(arr,l);
}