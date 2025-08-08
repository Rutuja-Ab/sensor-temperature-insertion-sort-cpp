#include<iostream>
using namespace std;
class flight{
   double price;
string origin,des;
public:
void getdata(){
   cout<<"Enter the origin of flight:";
   cin>>origin;
   cout<<"\nEnter the destination of flight:";
   cin>>des;
   cout<<"\nEnter price:";
   cin>>price;
}


void showdata(){
   cout<<"Origin of flight:"<<origin<<endl;
   cout<<"Destination of flight:"<<des<<endl;
   cout<<"Price of flight:"<<price<<endl;
}


void merge (flight f[],int l,int m,int r){
int n1=(m-l)+1;
int n2=r-(m+1)+1;
flight left[n1],right[n2];
for(int i=0;i<n1;i++){
   left[i]=f[l+i];
}
for(int j=0;j<n2;j++){
   right[j]=f[m+1+j];
}
int i=0,j=0,k=l;
while(i<n1 && j<n2){
   if(left[i].price<=right[j].price){
       f[k]=left[i];
       i++;
   }
   else{
       f[k]=right[j];
       j++;
   }
   k++;
}
while(i<n1){
   f[k]=left[i];
   i++;
   k++;
}
while(j<n2){
  f[k]=right[j];
   j++;
   k++;
}
}
void mergesort(flight f[],int l,int r){
   if(l<r){
       int m=l+(r-l)/2;
       mergesort(f,l,m);
       mergesort(f,m+1,r);
       merge(f,l,m,r);
   }
}
};
int main(){
   int n;
   cout<<"Enter number of flights:"<<endl;
   cin>>n;
   flight f[n];
   cout<<"\n********Entering flight details********"<<endl;
   for(int i=0;i<n;i++){
       f[i].getdata();
   }
   cout<<"\n********Display flight details********"<<endl;
   for(int i=0;i<n;i++){
       f[i].showdata();
   }
   f[0].mergesort(f,0,n-1);
   cout<<"\n********Flights sorted according to their price********"<<endl;
   for(int i=0;i<n;i++){
       f[i].showdata();
   }
   return 0;
}