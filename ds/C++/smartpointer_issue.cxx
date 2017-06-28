#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <cstring> 
#include <climits> 
#include <cstdio> 
using namespace std; 
//***************************************************************
class Test
{
public:
 Test(int a = 0 ) : m_a(a)
 {
 }
 ~Test( )
 {
  cout<<"Calling destructor"<<endl;
 }
public:
 int m_a;
};
 
 
//***************************************************************
void Fun(auto_ptr<Test> p1 )
{
 cout<<p1->m_a<<endl;
}
//***************************************************************
int main( )
{
 std::auto_ptr<Test> p( new Test[5] ); 
} 
