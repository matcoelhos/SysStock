#ifndef STOCKMANAGE_H_INCLUDED
#define STOCKMANAGE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "product.h"

using namespace std;

class stockmanage
{
public: 
	//constructor
	stockmanage();
	//destructor
	~stockmanage();
	//insert product in the list
	void insertprod(string name, float cost, float price);
	//adds number of elements in stock
	void addstock(int pos, int quantity);
	//remove product from list by name
	void removeprod(int pos);
	//find position in table by name
	vector<int> findprod(string name);
	//find position in table by ID
	int findbyid(int id);
	//get product by position
	product getbypos(int pos);
private:
	vector<product> list;
};
#endif //STOCKMANAGE_H_INCLUDED