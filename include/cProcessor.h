#ifndef CPROCESSOR_H
#define CPROCESSOR_H

#include <../cProduct.h>


class cProcessor : public cProduct
{
    private:
        double mClockRate;
        std::string mMaker;

    public:
        cProcessor* mType;
        cProcessor(int = 0, std::string = "Not defined", int = 0, std::string = "Not defined", double = 0, double = 0, double = 0, std::string = "Not defined");
        cProcessor(cProcessor*);
        virtual ~cProcessor();
        void fill(void);
        void show(void);
        cProduct* clone();
        virtual void import_to_txt(std::ofstream &);
};

#endif // CPROCESSOR_H
