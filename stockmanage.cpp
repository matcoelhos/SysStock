#include "stockmanage.h"

stockmanage::stockmanage()
{
    ifstream infile("data/products.dat");
    if (!infile)
    {
        ofstream o;
        o.open("data/products.dat");
        o.close();
    }
    else
    {
        string line;
        int counter = 0;
        while (getline(infile, line))
        {
            product p;
            istringstream i(line);
            i >> p.ID;
            i >> p.NAME;
            i >> p.PRICE;
            i >> p.COST;
            i >> p.STOCK;
            list.push_back(p);
            counter++;
        }
        cout << counter << " products loaded from list!" << endl;
    }
    infile.close();
}

stockmanage::~stockmanage()
{
    ofstream o;
    o.open("data/products.dat");
    for (int i = 0; i < list.size(); i++)
    {
        o << list[i].ID << "\t" 
        << list[i].NAME << "\t" 
        << list[i].PRICE << "\t"
        << list[i].COST << "\t" 
        << list[i].STOCK << endl;
    }
    o.close();
}

void stockmanage::insertprod(string name, float cost, float price)
{
    product p;
    string s = name;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    p.NAME = s;
    p.PRICE = price;
    p.COST = cost;
    p.STOCK = 0;

    if (list.size() == 0)
    {
        p.ID = 1;
    }
    else
    {
        p.ID = list[list.size()-1].ID + 1;
    }

    list.push_back(p);
}

void stockmanage::addstock(int pos, int quantity)
{
    list[pos].STOCK += quantity;
}

void stockmanage::removeprod(int pos)
{
    list.erase(list.begin()+pos);
}

bool find(string substr, string main)
{
    if (substr.size() > main.size())
    {
        return true;
    }
    else if (substr.size() == main.size())
    {
        return main.compare(substr);
    }
    else
    {
        string comp;
        for (int i = 0; i + substr.size() < main.size(); i++)
        {
            comp = main.substr(i,substr.size());
            if (!comp.compare(substr)) return false;
        }
    }
    return true;
}

vector<int> stockmanage::findprod(string name)
{
    vector<int> ans;
    int pos = 0;
    string s = name;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    while (pos < list.size())
    {
        if (!find(s,list[pos].NAME))
        {
            ans.push_back(pos);
        }
        pos++;
    }
    return ans;
}

int stockmanage::findbyid(int id)
{
    int pos = 0;
    while (pos < list.size())
    {
        if (list[pos].ID == id)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

product stockmanage::getbypos(int pos)
{
    product p = list[pos];
    return p;
}