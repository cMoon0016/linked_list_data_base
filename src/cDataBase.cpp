#include "cDataBase.h"
#include <fstream>
#include <string>
#include "cVegetable.h"
#include "cProcessor.h"
#include "cMemory.h"

cDataBase::cDataBase()
{
    mFirst = nullptr; //because date base is empty at the beginning
    std::cout<<"I am cDataBase constructor"<<std::endl;
}

cDataBase::~cDataBase()
{
    std::cout<<"I am cDataBase destructor"<<std::endl;
    cNode* ptr = mFirst; //create auxiliary pointer on first element
    while( ptr != nullptr)
    {
        cNode* ptr2 = ptr; // create another auxiliary pointer
        ptr = (ptr->getNext()); // change first pointer to next element
        delete ptr2;
    }
}

void cDataBase::add(cProduct* aProduct)
{
    cProduct* ptr = aProduct->clone(); //create copy of aProduct argument which we want add to list
    cNode* newNode = new cNode(ptr);  //create new node with aProduct
    newNode->setNext(mFirst);        //set node pointer to next element on list (which previous was last element)
    mFirst = newNode;               //set date base pointer to new created node
}

void cDataBase::show()
{
    cNode* ptr = mFirst; // create auxiliary pointer
    while( ptr != nullptr)
    {
        (ptr->getProduct())->show(); // show product
        ptr = (ptr->getNext()); // change pointer to next element
    }
}

void cDataBase::import_to_txt()
{
    std::ofstream File;
    File.open("DataBase.txt");
    if(!File.is_open())
    {
        std::cout<<"Something's wrong. Cannot open file"<<std::endl;
        return;
    }

    cNode* ptr = mFirst;
    while( ptr != nullptr)
    {
        (ptr->getProduct())->import_to_txt(File);
        ptr = ptr->getNext();
    }
    File.close();
}

void cDataBase::export_from_txt(void)
{
    std::ifstream File;
    File.open("DataBase.txt");
    if(!File.is_open())
    {
        std::cout<<"Something's wrong. Cannot open .txt file"<<std::endl;
        return;
    }

    std::string line;
    int line_number = 0;
    char what_object;
    while( getline(File, line))
    {
        int mLp, mCount;
        std::string mName, mUnit, additionalS;
        double mPrize, mVat, additionalD;
        switch(line_number)
        {
            case 0:
                if(line == "Vegetable")
                    what_object = 'v';
                else if(line == "Processor")
                    what_object = 'p';
                else if(line == "Memory")
                    what_object = 'm';
                break;
            case 1:
                mLp = stoi(line); break;
            case 2:
                mName = line; break;
            case 3:
                mCount = stod(line); break;
            case 4:
                mUnit = line; break;
            case 5:
                mPrize = stod(line); break;
            case 6:
                mVat = stod(line); break;
            case 7:
                if(what_object == 'v')
                    additionalS = line;
                else if(what_object == 'p' || what_object == 'm')
                    additionalD = stod(line);
                break;
            case 8:
                if(what_object == 'v')
                {
                    cVegetable v(mLp, mName, mCount, mUnit, mPrize, mVat, additionalS);
                    add(&v);
                    line_number = -2;
                }
                else if(what_object == 'p' || what_object == 'm')
                {
                    additionalS = line;
                    if(what_object == 'p')
                    {
                        cProcessor p(mLp, mName, mCount, mUnit, mPrize, mVat, additionalD, additionalS);
                        add(&p);
                    }
                    else if(what_object == 'm')
                    {
                        cMemory m(mLp, mName, mCount, mUnit, mPrize, mVat, additionalD, additionalS);
                        add(&m);
                    }
                    line_number = -2;
                }
                break;
        }
        line_number++;
    }

    File.close();
}
