#include <fstream>
#include "cProcessor.h"

using namespace std;

cProcessor::cProcessor(int aLp, string aName, int aAmount, string aUnit, double aPrize, double aVat, double aClockRate, string aMaker)
: cProduct(aLp, aName, aAmount, aUnit, aPrize, aVat), mClockRate(aClockRate), mMaker(aMaker)
{cout<<"I am cProcessor constructor"<<endl;}

cProcessor::cProcessor(cProcessor* aProcessor)
: cProduct(aProcessor), mClockRate(aProcessor->mClockRate), mMaker(aProcessor->mMaker)
{cout<<"I am cProcessor copy constructor"<<endl;}

cProcessor::~cProcessor()
{cout<<"I am cProcessor destructor"<<endl;}

void cProcessor::fill(void)
{
    cout<<"Type: Processor"<<endl;
    cProduct::fill();
    cout<<"Clock rate = ";  cin>>mClockRate;
    cout<<"Maker = ";       cin>>mMaker;
    cout<<endl;
}

void cProcessor::show(void)
{
    cout<<"Type: Processor"<<endl;
    cProduct::show();
    cout<<"Clock rate = "<<mClockRate<<endl;
    cout<<"Maker = "<<mMaker<<endl;
    cout<<endl;
}

cProduct* cProcessor::clone()
{
    cProduct* ptr = new cProcessor(this);
    return ptr;
}

void cProcessor::import_to_txt(ofstream &File)
{
    File<<"Processor"<<endl;
    cProduct::import_to_txt(File);
    File<<mClockRate<<endl;
    File<<mMaker<<endl;
    File<<endl;
}
