#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <cstring> 
#include <climits> 
#include <cstdio>
#include <algorithm>
using namespace std; 
void counting(int arr[], int size, int base)
{
    int count[10] = {0};
    int output[size];
    for (int i = 0; i < size; i++)
    {
        count[(arr[i]/base)%10]++; 
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }
    for (int i = size-1; i >=0; i--) 
    {
        output[count[(arr[i]/base)%10]-1] = arr[i];
        count[(arr[i]/base)%10]--;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void radix(int arr[], int size)
{
    int num  = *std::max_element(arr, arr+size);
    for(int c = 1; num/c >0; c *= 10)
    {
        counting(arr, size, c);
    }
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"\t";
    }
}
int main( )
{ 
    int arr[] = {11,24,66,24,29};
    radix(arr, sizeof(arr)/sizeof(int));
}
