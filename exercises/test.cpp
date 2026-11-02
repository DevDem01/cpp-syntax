#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using std::cin;
using std::cout;

class Item
{
private:
    std::string name;
    float price;
    int quantity;

public:
    Item() : price(0), quantity(0) {}
    Item(std::string n, float p, int q) : name(n), price(p), quantity(q) {}

    bool matchesName(const std::string &value) const
    {
        return name == value;
    }

    friend std::ostream &operator<<(std::ostream &os, const Item &i)
    {
        os << i.name << "|" << i.price << "|" << i.quantity << std::endl;
        return os;
    }
};

int main()
{
    std::vector<Item *> list;
    int n = 0;
    std::string name;
    float price;
    int qty;
    std::string search;
    std::cout << "Enter number of items";
    if (!(cin >> n) || n <= 0)
    {
        std::cerr << "Invalid input" << std::endl;
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter items name,price, and quantity " << "Item " << i + 1 << std::endl;
        if (!(cin >> name >> price >> qty))
        {
            cout << "Invalid input" << std::endl;
            for (Item *ptr : list)
            {
                delete ptr;
            }
        }
        else
        {
            list.push_back(new Item(name, price, qty));
        }
    }
    cout << "Enter fruit to seach for" << std::endl;
    cin >> search;
    if (std::find_if(list.begin(), list.end(), [&search](const Item *item)
                     { return item->matchesName(search); }) != list.end())
    {
       std::cout << "found";
    }
    else
    {
        std::cout << "Not found\n";
    }
    // for (const Item *item : list)
    // {
    //     cout << *item << std::endl;
    // }
}