#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <cstring> 
#include <climits> 
#include <cstdio> 
#include <memory>
using namespace std; 

void fun3(unique_ptr<int> & ptr)
{
    int *a = ptr.release();
    cout<<*a<<endl;
}

int main( )
{ 
    shared_ptr<int>  p  = make_shared<int> ( int(100));
    cout<<*p<<endl;

    weak_ptr<int> p1 = p;
    auto sp2 = p1.lock();
    cout<<*sp2<<endl;
    shared_ptr<int> p2 = NULL;
    if(p2 == NULL)
    {   
        cout<<"it is null"<<endl;
    }
    p2 = make_shared<int>( int (200));
    int nRef = p1.use_count();
    cout<<nRef<<endl;
    //cout<<p1.unique()<<endl;
    cout<<p2.unique()<<endl;

    unique_ptr<int> up1 (new int (100));

    //unique_ptr<int> up2  = move(up1);


    vector< unique_ptr<int> > vptr;
    if(up1 != NULL)
        vptr.push_back(move(up1)); 
    if(up1 == NULL)
    {
        cout<<"up1 is null"<<endl;
    }
    unique_ptr<int> pp1 (new int (300));
    fun3(pp1);
    //cout<<*pp1<<endl;
    return 0;
}
