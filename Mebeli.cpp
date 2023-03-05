#include "Mebeli.h"
#include <iostream>
using namespace std;

Mebeli::Mebeli()
{
    //ctor
}

Mebeli::Mebeli(string name, int id, string color,int price, string material)
{
    this->name=name;
    this->id=id;
    this->color=color;
    this->price=price;
    this->material=material;
}

Mebeli::~Mebeli()
{
    //dtor
}

void Mebeli::print()
{
    cout<<id<<", "<<name<<", "<<price<<", "<<color<<", "<<material<<endl;
}

string Mebeli::getName()
{
    return name;
}

int Mebeli::getId()
{
    return id;
}

int Mebeli::getPrice()
{
    return price;
}
