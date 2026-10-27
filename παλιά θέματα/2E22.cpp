#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class purchase {

    private:
    map<string, int> price_list;
    map<string, int> quantity;
    int total;


    public:

    purchase() {total = 0;}

    void add_item(string item, int price) {
        if(price_list.find(item) == price_list.end()) {
            price_list[item] = price;
        }
        quantity[item]++;
        total += price;
        return;
    }

    

};