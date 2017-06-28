#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <cstring> 
#include <climits> 
#include <cstdio> 
using namespace std; 

class RF{
    private: 
        int count;
    public:
        RF(): count(0){}
        void addRef()
        {
            count++;
        }
        int decRef()
        {
            --count;
        }
};



template <typename T> class SP{
    private:
    T* pData;
    RF* ref;
    public: 
    SP(): pData(0), ref(0){
        ref = new RF();
        ref->addRef();
    }
    SP(T* pValue) : pData(pValue), ref(0){
        ref = new RF();
        ref->addRef();
    }
    ~SP(){
        if(ref->decRef() == 0)
        {
           delete pData;
           delete ref;
        }
    }
    
    SP(const SP<T>& obj) : pData(obj.pData), ref(obj.ref)
    {
         ref->addRef();
    }
    SP<T>& operator=(const SP<T>& obj)
    {
        if(this != &obj)
        {
            if(ref->decRef() == 0)
            {
                delete pData;
                delete ref;
            }
            ref = obj.ref;
            pData = obj.pData;
            ref->addRef();
        }
        return *this;
    }
    T& operator*()
    {
        return*pData;
    }
    T* operator->()
    {
        return pData;
    }
};

int main( )
{ 
    SP<int> p(new int(4));
    cout<<*p<<endl;
    {
        SP<int> q = p;
        cout<<*q<<endl;
    }
    cout<<*p<<endl;

}
