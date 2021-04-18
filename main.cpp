#include <iostream>
#include <fstream>
#include "cProduct.h"
#include "include\cVegetable.h"
#include "include\cProcessor.h"
#include "include\cMemory.h"
#include "include\cNode.h"
#include "include\cDataBase.h"

using namespace std;

int main()
{
    cDataBase db; //creating database
    //creatings 3 object
    cVegetable v1(1, "Carrot", 20, "PLN", 2.3, 0.23, "Orange");
    cProcessor p1(2, "Ryzen 7", 2, "PLN", 700, 0.23, 3500, "AMD");
    cMemory m1(3, "CL19", 40, "PLN", 390, 0.23, 16, "GoodRam");
    cVegetable v2(4, "Cabbage", 50, "PLN", 7.5, 0.23, "Green");

    //adding to list
    db.add(&v1);
    db.add(&p1);
    db.add(&m1);
    //db.add(&v2);
    system("pause");

    //using fill method
    //v1.fill();

    //v1 on the list should not been changed
    db.show();

    //importing to .txt file
    db.import_to_txt();

    //exporting from .txt file
    db.export_from_txt();

    db.show();
    return 0;
}
