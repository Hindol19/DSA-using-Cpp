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

void countingSort(int arr[],int len, int pow10) {
    int count[10]={0};
    int *outputArr=new int[len];
    for(int i=0;i<len;i++) {        //frequency 
        int digit=(arr[i]/pow10)%10;
        count[digit]++;
    }
    for(int i=1;i<10;i++) {     //relative address
        count[i]+=count[i-1];
    }
    for(int i=len-1;i>=0;i--) {     //placing elements in order
        int digit=(arr[i]/pow10)%10;
        int index=count[digit]-1;
        count[digit]--;
        outputArr[index]=arr[i];
    }
    for(int i=0;i<len;i++) {        //copy from output array to original array
        arr[i]=outputArr[i];
    }
}

void RadixSort(int arr[], int len){
    int maxEle=getMaximum(arr,len);
    int pow10=1;
    while (maxEle!=0)
    {
        countingSort(arr,len,pow10);
        pow10=pow10*10;
        maxEle=maxEle/10;
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
    RadixSort(arr,l);
    cout<<"Sorted array = ";
    print(arr,l);
}