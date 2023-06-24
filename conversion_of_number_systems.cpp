#include <iostream>
#include <ctime>
using namespace std;
//method#1
/*int main(){
    srand(time(0));
    int N= rand()%1000;
    cout << N <<endl;
    int N_2[10]= {};
    for(int i=0;i<10;i++)
    {
        if(N%2 == 0)
        {N_2[9-i] = 0;
        N = N/2;
        }
        else if(N%2 == 1)
        {
            N_2[9-i] = 1;
            N=(N-1)/2;
        }
    }
    for(int i=0;i<10;i++)
    {
        cout << N_2[i] <<" ";
    }
    
    return 0;
}*/
//method#2

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
int main()
{
    srand(time(0));
    int N= rand()%1000;
    cout << N << endl;
    int N_2[10]={};
    while(N != 0)
    {
    int i= find_left_closest_two_power(N);
    N_2[9-i]=1;
    N= N-power_result(2,i);
    }
    
    for(int i=0;i<10;i++)
    {
        cout << N_2[i];
    }

    

    return 0;
}
