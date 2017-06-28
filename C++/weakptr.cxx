
#include "Header.h"

void main( )
{
	//Create a shared pointer
	shared_ptr<Test> sp1 = shared_ptr<Test> ( new Test(5) );

	//Create a weak pointer from the shared pointer
	weak_ptr<Test> wp1 = sp1;

	//Get the reference count of the shared pointer
	int nbReference = sp1.use_count();
	cout<<"Number of references of sp1 = "<<nbReference<<endl;

	//What happens to the weak ptr when the associated shared ptr is released.
	//lets see
	{
		shared_ptr<Test> sp2 = shared_ptr<Test> ( new Test(100) );
		 wp1 = sp2;		 

		 //sp2 is destroyed at the end of the scope. What is the state of wp1?
	}

	//Check the status of wp1 as the sp2 is expired
	if( wp1.expired() )
	{
		cout<<" Weak pointer wp1 is expired$$$$$$$$$$$$$$$$$$$"<<endl;
	}
	
	//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
	//NOTE::MEMORY LEAK CAUSED BY SHARED POINTERS IN CASE OF CYCLIC REFERENCES
	//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
	shared_ptr<B> spToB = shared_ptr<B>( new B() );
	shared_ptr<A> spToA = shared_ptr<A>( new A() );

	//After this the reference count of spToB and spToA is 2 but when the scope ends the
	//the reference count goes to 1 and not zero. So the memory leaks
	spToB->m_spToA = spToA;
	spToA->m_spToB = spToB;

	//-------------------------------------------------------------------------------------------
	//NOTE:Resources owned by spToB and spToA are never released.
	//-------------------------------------------------------------------------------------------

	//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
	//NOTE:: PROPER RELEASE OF MEMORY BY USING WEAK POINTERS
	//IN CASE OF CYCLIC REFERENCES
	//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
	//Releasing resources properly even in the case of cyclic reference with the
	//help of weak pointers.In this case, the shared resources spToC and spToD
	//calls the destructor of their resource
	shared_ptr<C> spToC = shared_ptr<C>( new C() );
	shared_ptr<D> spToD = shared_ptr<D>( new D() );
	spToC->m_wpToD = spToD;
	spToD->m_wpToC = spToC;

	//----------------------------------------------------------------------------------------------
	//NOTE:Resources owned by spToC and spToD are released properly.
	//-----------------------------------------------------------------------------------------------
	  
}