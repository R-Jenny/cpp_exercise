#include <iostream>
#include <ctime>
using namespace std;
int factorial_result(int N)
{
    int result=0;
    if(N==0 or N==1)
    {
        result = 1;
        return result;
    }
    else
    {
        return factorial_result(N-1)*N;
    }
}

int main(){
    srand(time(0));
    int N= rand()%10;
    cout << N <<endl;
    int result = 0;
    for(int i=1;i<=N;i++)
    {
        result = result + factorial_result(i);
    }
    cout << result;

    return 0;
}