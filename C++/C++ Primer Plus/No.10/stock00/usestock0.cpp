//usestck0.cpp -- the client program
//compile with stock00.cpp
#include <iostream>
#include "stock00.h"

int mian()
{
    Stock fiuffy_the_cat;
    fiuffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fiuffy_the_cat.show();
    fiuffy_the_cat.buy(15, 18.125);
    fiuffy_the_cat.show();
    fiuffy_the_cat.sell(400, 20.00);
    fiuffy_the_cat.show();
    fiuffy_the_cat.buy(300000, 40.125);
    fiuffy_the_cat.show();
    fiuffy_the_cat.sell(300000, 0.125);
    fiuffy_the_cat.show();
    return 0;
}

