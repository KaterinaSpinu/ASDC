#include <iostream>
#include "Shop.h"
using namespace std;

int main()
{
Shop shopMeb; //magazin mebeli, vnutri vector mebeli
shopMeb.loadMebeli();

//lineinii poisk
string name;
cout <<endl << " > Line Search: " << endl;
cout<<"Input name : ";
getline(cin,name); //ctob vivodilo s probelom
Mebeli* findedMebeli=shopMeb.lineSearch(name);
if(findedMebeli!=nullptr)
{
    findedMebeli->print();
}
else{
    cout<<"Not found"<<endl;
}

cout<<"Press something to start sorting";
getchar();

shopMeb.bubbleSortId();
shopMeb.printShop(); //dannie otsortir

cout<<"Press something to start binary search";
getchar();
//Binarnii poisk
int id;
cout << endl << " > Binary Search: " << endl;
cout<<"Input id : ";
cin>>id;
findedMebeli=shopMeb.binarySearch(id);
if(findedMebeli!=nullptr)
{
    findedMebeli->print();
}
else{
    cout<<"Not found"<<endl;
}

cout<<"Press something to start bubble sort by price";
getchar();

shopMeb.bubbleSortPrice();
shopMeb.printShop(); //dannie otsortir

cout<<"Press something to start Interpolation search";
getchar();
//Interpol poisk
int price;
cout << endl << " > Interpolation Search: " << endl;
cout<<"Input price : ";
cin>>price;
findedMebeli=shopMeb.interpSearch(price);
if(findedMebeli!=nullptr)
{
    findedMebeli->print();
}
else{
    cout<<"Not found"<<endl;
}

cout<<"Press something to start bubble sort by id ";
getchar();

shopMeb.bubbleSortId();
shopMeb.printShop(); //dannie otsortir
//Metod Fibonacci poisk

cout<<"Fibo search Input id : ";
cin>>id;
findedMebeli=shopMeb.fiboSearch(id);
if(findedMebeli!=nullptr)
{
    findedMebeli->print();
}
else{
    cout<<"Not found"<<endl;
}

cout<<"Press something to exit";
getchar();
getchar();
return 0;
}




