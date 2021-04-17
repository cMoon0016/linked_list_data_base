#ifndef CVEGETABLE_H
#define CVEGETABLE_H

#include <../cProduct.h>

class cVegetable : public cProduct
{
    private:
        std::string mColor;

    public:
        cVegetable(int = 0, std::string = "Not defined", int = 0, std::string = "Not defined", double = 0, double = 0, std::string mColor = "Not defined");
        cVegetable(cVegetable*);
        virtual ~cVegetable();
        void fill(void);
        void show(void);
        cProduct* clone();
        virtual void import_to_txt(std::ofstream &);
};

#endif // CVEGETABLE_H
