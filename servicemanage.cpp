#include "servicemanage.h"

servicemanage::servicemanage()
{
    ifstream infile("data/services.dat");
    if (!infile)
    {
        ofstream o;
        o.open("data/services.dat");
        o.close();
    }
    else
    {
        string line;
        while (getline(infile, line))
        {
            service p;
            istringstream i(line);
            i >> p.ID;
            i >> p.NAME;
            i >> p.PRICE;

            list.push_back(p);
        }
    }
    infile.close();
}

servicemanage::~servicemanage()
{
    ofstream o;
    o.open("data/services.dat");
    for (int i = 0; i < list.size(); i++)
    {
        o << list[i].ID << "\t" 
        << list[i].NAME << "\t" 
        << list[i].PRICE << endl;
    }
    o.close();
}
