#include<iostream>
using namespace std;
class product{
   string name;
   int price;
   public:
   void getdata(){
       cout<<"Enter name of the product:"<<endl;
       cin>>name;
       cout<<"Enter price of the product:"<<endl;
       cin>>price;
   }
   void display(){
       cout<<"Product: "<<name<<" "<<"Price: "<<price<<endl;
   }


   void quick(product p[],int f,int l){
       int i,j;
       product pvt,temp;
       if(f<l){
           pvt=p[f];
           i=f+1;
           j=l;
           while(i<=j){
               while(i<j && p[i].price<=pvt.price){
                   i++;
           }
           while(p[j].price>pvt.price){
               j--;
           }
           if(i<j){
           swap(p[i],p[j]);}
           }
           swap(p[f],p[j]);
           quick(p,f,j-1);
           quick(p,j+1,l);
       }
       }
   void swap(product &a,product &b){
       product temp=a;
       a=b;
       b=temp;
   }
   };


int main(){
   int n,f=0;
   cout<<"Enter number of products:"<<endl;
   cin>>n;
   product p[n];
   for(int i=0;i<n;i++){
       p[i].getdata();
   }
   p[0].quick(p,f,n-1);
   cout<<"Produts sorted according to their prices:"<<endl;
   for(int i=0;i<n;i++){
       p[i].display();
   }
   return 0;
}

