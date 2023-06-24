#include <iostream>
#include <ctime>
using namespace std;
const int N= 10;
int main(){
    srand(time(0));
    int arr[N]={};
    for(int i=0;i<N;i++)
    {
        arr[i] = rand()%1000;
        cout << arr[i] <<" ";
    }
    cout << endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0; j<N-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int a= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]=a;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        
        cout << arr[i] <<" ";
    }
    cout << endl;
    
    return 0;
}