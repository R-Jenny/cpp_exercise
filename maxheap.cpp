#include <iostream>
#include <ctime>
using namespace std;
const int N =10;

int arr[N]= {};
void swap(int &a, int &b){
    int m = a;
    a=b;
    b=m;

}
void heapinsert(int arr[],int i){
    while(arr[i]>arr[(i-1)/2] && i> 0)
    {
        swap(arr[i],arr[(i-1)/2]);
        i=(i-1)/2;
    }
    
}
void heapify(int arr[],int i,int heapsize){
    
    while(2*i+1<heapsize){    
        int &max= (2*i+2<heapsize && arr[2*i+2]>arr[2*i+1])?arr[2*i+2]:arr[2*i+1];
        int left =2*i+1,right= 2*i+2;
        int max_index = (2*i+2<heapsize && arr[2*i+2]>arr[2*i+1])?right:left;
        if(arr[i]<max)
        {
            swap(arr[i],max);
            //i=(2*i+2<heapsize && arr[2*i+2]>arr[2*i+1])?(2*i+2):(2*i+1);
            i=max_index;


        }
        else
        {
	   break;
	}
    }
            
    
}
int power_result(int base, int power)
{
    int result =1;
    while(power >0)
    {
        result = result*base;
        power--;
    }

    return result;
}
int find_left_closest_two_power(int N)
{
    int i=0;
    while(power_result(2,i)<= N)

    {
        i++;
    }
    return i-1;

}
void heap_cout(int arr[],int heapsize){
    int i= find_left_closest_two_power(heapsize);
    for(int j=0;j<=i;j++)
    {
        for(int k=power_result(2,j)-1;k<=power_result(2,j+1)-2 && k<=heapsize-1;k++)
        {
            cout<< arr[k] <<" ";
        }
        cout<< endl;
    }
}
int main(){
    int heapsize = N;
    srand(time(0));
    for(int i=0;i<N;i++)
    {
        arr[i]= rand()%10000;
        
    }
    heap_cout(arr,heapsize);

    int i= find_left_closest_two_power(heapsize);
    for(int j=i-1;j>=0;j--)
    {
        for(int k=power_result(2,j)-1;k<=power_result(2,j+1)-2;k++)
        {heapify(arr,k,heapsize);
        heap_cout(arr,heapsize);
        }

    }
    cout<<endl;
    while(heapsize >0)
    {
        
        swap(arr[0],arr[heapsize-1]);
        heapify(arr,0,--heapsize);
        heap_cout(arr,heapsize);
        
    }
    cout<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<arr[i]<<" ";

    }
    return 0;
}
