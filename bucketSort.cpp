#include <iostream>
#include <ctime>
using namespace std;
const int N =10;
int arr[N]={};
int arr_help[N]={};
int findLargest(int arr[]){
    int largest = arr[0];
    for(int i=0;i<N;i++)
    {
        largest=(largest>=arr[i])?largest:arr[i];
    }
    return largest;

}

int amount_of_radix(int n)
{   int amount = 0;
    if(n>0){
        while(n>=1)
        {
            amount++;
            n=n/10;

        }
    }
    else if(n==0)
    {amount=1;}
    return amount;
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

int get_kth_radix(int n,int k){
    int i=power_result(10,k);
    int j=power_result(10,k-1);
    
    return (n%i)/j;  
}

void swap(int &a, int &b){
    int m = a;
    a=b;
    b=m;

}

void cout_arr(int arr[],int size)
{
    for(int i=0;i<size;i++){
        cout<< arr[i]<<" ";
    }
}

void arr_copy(int arr1[],int arr2[],int size){
for(int i= 0;i<size;i++)
{
    arr1[i]=arr2[i];
}
}
int main(){
    srand(time(0));
    for(int i= 0;i<N;i++)
    {
        arr[i]= rand()%10000;
        cout << arr[i]<<" ";
        
    }
    cout << endl;
    int i= amount_of_radix(findLargest(arr));
    
    for(int j=1;j<=i;j++)
    {
        int arr_slice[10]={};
        for(int k=0;k<N;k++)
        {
            int a= get_kth_radix(arr[k],j);
            for(int l=a;l<10;l++)
            {
                arr_slice[l]++;
            }
        }
        cout_arr(arr_slice,10);
        cout<<endl;
        

        for(int k=N-1;k>=0;k--)
        {
            int a= get_kth_radix(arr[k],j);
            arr_help[arr_slice[a]-1]=arr[k];
            arr_slice[a]--;
        
        }
        //cout_arr(arr_slice,10);
        arr_copy(arr,arr_help,N);
        cout_arr(arr,N);
        cout <<endl;
    }
    return 0;
}
