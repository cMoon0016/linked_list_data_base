#include "cMemory.h"
#include <fstream>
using namespace std;

cMemory::cMemory(int aLp, string aName, int aAmount, string aUnit, double aPrize, double aVat, double aCapacity, string aMaker)
: cProduct(aLp, aName, aAmount, aUnit, aPrize, aVat), mCapacity(aCapacity), mMaker(aMaker)
{cout<<"I am cMemory constructor"<<endl;}

cMemory::cMemory(cMemory* aMemory)
: cProduct(aMemory), mCapacity(aMemory->mCapacity), mMaker(aMemory->mMaker)
{cout<<"I am cMemory copy constructor"<<endl;}

cMemory::~cMemory()
{cout<<"I am cMemory destructor"<<endl;}

void cMemory::fill(void)
{
    cout<<"Type: Memory"<<endl;
    cProduct::fill();
    cout<<"Capacity = ";    cin>>mCapacity;
    cout<<"Maker = ";       cin>>mMaker;
    cout<<endl;
}

void cMemory::show(void)
{
    cout<<"Type: Memory"<<endl;
    cProduct::show();
    cout<<"Capacity = "<<mCapacity<<endl;
    cout<<"Maker = "<<mMaker<<endl;
    cout<<endl;
}

cProduct* cMemory::clone()
{
    cProduct* ptr = new cMemory(this);
    return ptr;
}

void cMemory::import_to_txt(ofstream &File)
{
    File<<"Memory"<<endl;
    cProduct::import_to_txt(File);
    File<<mCapacity<<endl;
    File<<mMaker<<endl;
    File<<endl;
}
