#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <cstring> 
#include <climits> 
#include <cstdio>
#include<memory>
using namespace std; 

int main( )
{ 
    shared_ptr<int> ptr1 (new int(10));
    weak_ptr<int> wkptr1 = ptr1;
    cout<<ptr1.use_count();

}
