#include <fstream>
#include "cVegetable.h"

using namespace std;

cVegetable::cVegetable(int aLp, string aName, int aAmount, string aUnit, double aPrize, double aVat, string aColor)
: cProduct(aLp, aName, aAmount, aUnit, aPrize, aVat), mColor(aColor)
{cout<<"I am cVegetable constructor"<<endl;}

cVegetable::cVegetable(cVegetable* aVegetable)
: cProduct(aVegetable), mColor(aVegetable->mColor)
{cout<<"I am cVegetable copy constructor"<<endl;}

cVegetable::~cVegetable()
{cout<<"I am cVegetable destructor"<<endl;}

void cVegetable::fill(void)
{
    cout<<"Type: Vegetable"<<endl;
    cProduct::fill();
    cout<<"Color = ";   cin>>mColor;
    cout<<endl;
}

void cVegetable::show()
{
    cout<<"Type: Vegetable"<<endl;
    cProduct::show();
    cout<<"Color = "<<mColor<<endl;
    cout<<endl;
}

cProduct* cVegetable::clone()
{
    cProduct* ptr = new cVegetable(this);
    return ptr;
}

void cVegetable::import_to_txt(ofstream &File)
{
    File<<"Vegetable"<<endl;
    cProduct::import_to_txt(File);
    File<<mColor<<endl;
    File<<endl;
}
