#include "cProduct.h"
#include <fstream>

using namespace std;

cProduct::cProduct(int aLp, string aName, int aAmount, string aUnit, double aPrize, double aVat)
: mLp(aLp), mName(aName), mAmount(aAmount), mUnit(aUnit), mPrize(aPrize), mVat(aVat)
{cout<<"I am cProduct constructor"<<endl;}

cProduct::cProduct(cProduct* aProduct)
: mLp(aProduct->mLp), mName(aProduct->mName), mAmount(aProduct->mAmount), mUnit(aProduct->mUnit), mPrize(aProduct->mPrize), mVat(aProduct->mVat)
{cout<<"I am cProduct copy constructor"<<endl;}

cProduct::~cProduct()
{cout<<"I am cProduct destructor"<<endl;}

void cProduct::fill(void)
{
    cout<<"Lp = ";      cin>>mLp;
    cout<<"Name = ";    cin>>mName;
    cout<<"Amount = ";  cin>>mAmount;
    cout<<"Unit = ";    cin>>mUnit;
    cout<<"Prize = ";   cin>>mPrize;
    cout<<"Vat = ";     cin>>mVat;
}

void cProduct::show(void)
{
    cout<<"Lp = "<<mLp<<endl;
    cout<<"Name = "<<mName<<endl;
    cout<<"Amount = "<<mAmount<<endl;
    cout<<"Unit = "<<mUnit<<endl;
    cout<<"Prize = "<<mPrize<<endl;
    cout<<"Vat = "<<mVat<<endl;
}

int cProduct::getLp(void)
{
    return mLp;
}

void cProduct::setLp(int aLp)
{
    mLp = aLp;
}

void cProduct::import_to_txt(ofstream &File)
{
    File<<mLp<<endl;
    File<<mName<<endl;
    File<<mAmount<<endl;
    File<<mUnit<<endl;
    File<<mPrize<<endl;
    File<<mVat<<endl;
}
