#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class product
{
public:
	unsigned int ID;
	string NAME;
	float PRICE;
	float COST;
	unsigned int STOCK;   
};
#endif //PRODUCT_H_INCLUDED