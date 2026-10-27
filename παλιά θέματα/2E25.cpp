#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

enum table_status {freee, taken};

class restaurant {
    private:
    vector<table_status> tables;
    int free__tables, total__tables;

    public:
    restaurant(int total_tables) {
        free__tables = total_tables;
        total__tables = total_tables;
        tables.resize(total_tables + 1);
        for(int i = 1; i <= total_tables; ++i) {
            tables[i] = freee;
        }
    }

    ~restaurant() {
        tables.clear();
    }

    int free_tables() const {
        return free__tables;
    }

    int find_table() {
        if(free__tables == 0) throw logic_error("there are not any free tables");
        for (int i = 1; i <= tables.size(); ++i){
            if (tables[i] == freee) {
                tables[i] = taken;
                free__tables--;
                return i;
            }
        }
    }

    void release_table (int i) {
        if (i <=0 || i > total__tables) throw out_of_range("invalid number of tables");
        if (tables[i] == freee) throw logic_error("this table is already free");
        tables[i] = freee;
        free__tables++;
        return;
    }


};