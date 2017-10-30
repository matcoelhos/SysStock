#include<cstdio>
#include<iostream>
#include "product.h"
#include "service.h"
#include "stockmanage.h"
#include "servicemanage.h"

using namespace std;

void insertProduct(stockmanage * SM)
{
    string name;
    float price;
    float cost;
    cout << "Type product name: ";
    cin >> name;
    cout << "Type product cost price: ";
    cin >> cost;
    cout << "Type product price: ";
    cin >> price;
    SM->insertprod(name, cost, price); 
    cout << endl;
}

void searchProduct(stockmanage * SM)
{
    product p;
    cout << "Type product name: ";
    string name;
    cin >> name;
    
    vector<int> pos = SM->findprod(name); 
    while (pos.size() > 0)
    {
        p = SM->getbypos(pos[0]);
        pos.erase(pos.begin());
        cout << "ID: " << p.ID 
        << ", NAME: " << p.NAME
        << ", COST: " << p.COST
        << ", PRICE: " << p.PRICE
        << ", STOCK: " << p.STOCK << endl << endl;
    }
}

void removeProduct(stockmanage * SM)
{
    cout << "Type product ID: ";
    int id;
    cin >> id;
    int pos = SM->findbyid(id);
    if (pos == -1)
    {
        cout << "NOT FOUND!" << endl;
    }
    else
    {
        SM->removeprod(pos);
    }
}

int main(int argc, char* argv[])
{
    stockmanage * StM;
    unsigned int op = 100000;
    while (op != 0)
    {
        StM = new stockmanage;
        cout << "------\tstock manager\t------" << endl;
        cout << "operations: " << endl;
        cout << "1 - insert new product" << endl;
        cout << "2 - search product on list" << endl;
        cout << "3 - remove product from list" << endl;
        cout << endl << "0 - quit" << endl;
        cout << endl << "Type desired operation: ";
        cin >> op;

        if (op == 1)
        {
            insertProduct(StM);
        }
        else if (op == 2)
        {
            searchProduct(StM);
        }
        else if (op == 3)
        {
            removeProduct(StM);
        }
        delete StM;
    }
    return 0;
}