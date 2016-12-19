#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <cstring> 
#include <climits> 
#include <cstdio> 
using namespace std; 

void counting(int arr[], int size)
{
    int count[10] = {0};
    int output[size];
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++; 
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }
    for (int i = size-1; i >=0; i--) 
    {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < size; i++)
    {
        cout<<output[i]<<"\t";
    }
    cout<<endl;
}

int main( )
{ 
    int arr[] = {1,2,6,4,9};
    counting(arr, sizeof(arr)/sizeof(int));
}
