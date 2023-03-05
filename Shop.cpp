#include "Shop.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

Shop::Shop()
{
//ctor
}

Shop::~Shop()
{
//dtor
}

void Shop::loadMebeli()
{
    //kak zagruziti infu iz faila .csv v vector mebeli
    ifstream fin;
    fin.open("mebeli.csv"); //otcrili fail cerez perem fin
    string mebeliStr; //ctobi procitati iz faila stroku s mebeliu
    while(!fin.eof())
    {
        getline(fin,mebeliStr);
        cout<<mebeliStr<<endl;
        Mebeli *newMebeli=createMebeli(mebeliStr); //metod sozd object i vozvr, "fabrica"
        mebeli.push_back(newMebeli);
    }
}

Mebeli * Shop::createMebeli(string mebeliStr)
{
    auto args=split(mebeliStr,',');
    return new Mebeli(args[0],stoi(args[1]),args[2],stoi(args[3]),args[4]);
}

vector<string> Shop::split(const string& s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
       tokens.push_back(token);
    }
    return tokens;
}

Mebeli* Shop::lineSearch(const string& name)
{
    int it_count=0;
    cout << " > Line Search: " << endl;
    for(int i=0;i<mebeli.size();i++)
    {
        it_count++;
        if(mebeli[i]->getName()==name)
        {
            cout << "Count of iterrations: " << it_count << endl;
            return mebeli[i];
        }
    }

    return nullptr;
}

Mebeli* Shop::binarySearch(int id)
{
    int it_count=0;
    cout << endl << " > Binary Search: " << endl;
    int l=0,r=mebeli.size()-1;
    while (l <= r)
        {
            it_count++;
            int m = l + (r - l) / 2; //nomer srednego elem

            // Check if x is present at mid
            if (mebeli[m]->getId() == id)
            {
                cout << "Count of iterrations: " << it_count << endl;
                return mebeli[m];
            }


            // If x greater, ignore left half
            if (mebeli[m]->getId() < id)
                l = m + 1;

            // If x is smaller, ignore right half
            else
            {
                r = m - 1;
            }

        }
    return nullptr;
}

Mebeli* Shop::interpSearch(int price)
{

    cout << " > Interpolation Search: " << endl;
    int left = 0; int right = mebeli.size() - 1; // ������� ����� � ������ �������. int it_count = 0; // ������� ��������.
    // ����� ������� �������, ������ ���� ������, ��� ����.
    // ���� ������ �������� � �������� ������������ ��������.

    int it_count=0;//iteratii
    while (left <= right && price >= mebeli[left]->getPrice() && price <= mebeli[right]->getPrice())
        {
                it_count++;
                if (left == right)
                 {
                    if (mebeli[left]->getPrice() ==price)
                    {
                        cout << "Count of iterrations: " << it_count << endl;
                        return mebeli[left];
                    }


                    return nullptr;
                 }
            // ������� ������� �� ������� �����������.
            int position = left + (((double)(right - left) / (mebeli[right]->getPrice()- mebeli[left]->getPrice()) )*(price - mebeli[left]->getPrice()));
                        //  ���� ��� ������ � �������.
            if (mebeli[position]->getPrice()==price)
                {
                    cout << "Count of iterrations: " << it_count << endl;

                    return mebeli[position];
                }
                        // nujnii element �������� ����� ������� �������.
                        if (mebeli[position]->getPrice()< price)
                        {
                            left = position + 1;
                        }

                        //  ���� �������� ����� ������� ��������.
            else
            {
                right = position - 1;
            }
        }
    // ���� price  �� ��� ������.
    return nullptr;
}

Mebeli* Shop::fiboSearch(int id)
{
    cout << endl << endl << " > FibonaccianSearch: " << endl;
    // �������������� ������ ���������
    int fm2 = 0; // m-2 ������� ������ ���������.
    int fm1 = 1; // m-1 ������� ������ ���������.
    int fmM = fm2 + fm1; // m �������� ������ ���������.
    int it_count = 0; // ���������� ���������.
    // ���� ����������� ����� ��������� ����� count
    while (fmM < mebeli.size()) {
    fm2 = fm1;
    fm1 = fmM;
    fmM = fm2 + fm1;
    }
    //int offs = mebeli.size()-1; // �����. ��� ������!!!
    int offs = -1;
    while (fmM > 1)
        {
            it_count++;
            // ���������, ���� ����� ��������� �� ��������� �������.
            //int i = mebeli.min(offs + fm2, mebeli.size() - 1);
            int i = min(offs + fm2, (int)mebeli.size() - 1);
            // ���� �������� ����� ������ ��� ������� ��������, �������� ��������� �� offs �� i
            if (mebeli[i]->getId() < id)
                {
                    fmM = fm1;
                    fm1 = fm2;
                    fm2 = fmM - fm1;
                    offs = i;
                }
            // ���� �������� ����� ������ ��� ������� ��������, �������� ��������� ����� i+1.
            else if (mebeli[i]->getId() > id) {
            fmM = fm2;
            fm1 = fm1 - fm2;
            fm2 = fmM - fm1;
            }
            // ���� �������� �������, ����������.
            else
            {
                cout << "Count of iterrations: " << it_count << endl;
                return mebeli[i];
            }
        }
    // ���������� ��������� ������� � ������ ���������.
    if (fm1 && mebeli[offs + 1]->getId() == id)
    {
        cout << "Count of iterrations: " << it_count << endl;
        return mebeli[offs + 1];
    }
    // ������� �� ��� ������.
    return nullptr;
}

Mebeli* Shop::binTree(const string& name)
{
    return nullptr;
}

void Shop::bubbleSortId()
{
    cout<<endl<<"Sortirovka"<<endl;
    Mebeli* temp;
    for (int i = 0; i < mebeli.size() - 1; i++)
        {
            for (int j = 0; j < mebeli.size()- i - 1; j++)
            {
                if (mebeli[j]->getId()> mebeli[j + 1]->getId())
                {
                // ������ �������� �������
                temp = mebeli[j];
                mebeli[j] = mebeli[j + 1];
                mebeli[j + 1] = temp;
                }
            }
        }
}

void Shop::bubbleSortPrice()
{
    Mebeli* temp;
    for (int i = 0; i < mebeli.size() - 1; i++)
        {
            for (int j = 0; j < mebeli.size()- i - 1; j++)
            {
                if (mebeli[j]->getPrice()> mebeli[j + 1]->getPrice())
                {
                // ������ �������� �������
                temp = mebeli[j];
                mebeli[j] = mebeli[j + 1];
                mebeli[j + 1] = temp;
                }
            }
        }
}

void Shop::printShop()
{
    for(int i=0;i<mebeli.size();i++)
    {
        mebeli[i]->print();
    }
}
