#ifndef SERVICEMANAGE_H_INCLUDED
#define SERVICEMANAGE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "service.h"

using namespace std;

class servicemanage
{
public: 
	//constructor
	servicemanage();
	//destructor
	~servicemanage();

private:
	vector<service> list;
};
#endif //SERVICEMANAGE_H_INCLUDED