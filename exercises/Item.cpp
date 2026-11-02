
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Item
{
private:
    string name;
    float price;
    int qty;

public:
    Item() : price(0), qty(0) {}

    Item(string n, float p, int q);

    friend ifstream& operator>>(ifstream& fis, Item& i);
    friend ofstream& operator<<(ofstream& fos, const Item& i);
    friend ostream& operator<<(ostream& os, const Item& i);
};

Item::Item(string n, float p, int q)
{
    name = n;
    price = p;
    qty = q;
}

// Write an Item to a file
ofstream& operator<<(ofstream& fos, const Item& i)
{
    fos << i.name << endl
        << i.price << endl
        << i.qty << endl;

    return fos;
}

// Read an Item from a file
ifstream& operator>>(ifstream& fis, Item& i)
{
    fis >> i.name >> i.price >> i.qty;
    return fis;
}

// Display an Item on the screen
ostream& operator<<(ostream& os, const Item& i)
{
    os << i.name << endl
       << i.price << endl
       << i.qty << endl;

    return os;
}

int main()
{
    int n;
    string name;
    float price;
    int qty;

    cout << "Enter number of Items: ";
    if (!(cin >> n) || n <= 0)
    {
        cerr << "Invalid number of items." << endl;
        return 1;
    }

    vector<Item*> list;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter item " << i + 1
             << " name, price and quantity: ";

        if (!(cin >> name >> price >> qty))
        {
            cerr << "Invalid item input." << endl;
            for (Item* ptr : list)
                delete ptr;
            return 1;
        }

        list.push_back(new Item(name, price, qty));
    }

    ofstream fos("Items.txt");

    if (!fos)
    {
        cerr << "Error opening output file." << endl;
    }
    else
    {
        for (auto itr = list.begin(); itr != list.end(); ++itr)
        {
            fos << **itr;
        }

        fos.close();

        ifstream fis("Items.txt");

        if (!fis)
        {
            cerr << "Error opening input file." << endl;
        }
        else
        {
            Item item;

            for (int i = 0; i < n; i++)
            {
                if (!(fis >> item))
                {
                    cerr << "Error reading item." << endl;
                    break;
                }

                cout << "Item " << i + 1 << endl
                     << item << endl;
            }

            fis.close();
        }
    }

    // Release dynamically allocated objects
    for (Item* ptr : list)
    {
        delete ptr;
    }

    return 0;
}
