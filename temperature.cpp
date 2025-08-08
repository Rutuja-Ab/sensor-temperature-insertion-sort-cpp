#include<iostream>
using namespace std;
void insertion(float arr[],int n){
   for(int i=1;i<n;i++){
       float key=arr[i];
       int j=i-1;
       while(j>=0 && arr[j]>key){
           arr[j+1]=arr[j];
           j--;
       }
       arr[j+1]=key;
   }
}
int main(){
   int n;
   cout<<"Enter number of readings:"<<endl;
   cin>>n;
   float arr[n];
   cout<<"Enter temperature readings:"<<endl;
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
   insertion(arr,n);
   cout<<"Sorted temperature readings:";
   for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
   }
   return 0;
}

