#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class WORKER {
private:
    string name;
    string position;
    int year;
    vector<string> subordinates;

public:
    WORKER(string n, string p, int y) {
        name = n;
        position = p;
        year = y;
    }

    void add_subordinate(string s) {
        subordinates.push_back(s);
    }

    void print_subordinates() {
        cout << "Subordinates of " << name << ":" << endl;
        for (string s : subordinates) {
            cout << "- " << s << endl;
        }
    }

    string get_position() const {
        return position;
    }

    int get_year() const {
        return year;
    }

    friend bool operator<(const WORKER& w1, const WORKER& w2);
    friend ostream& operator<<(ostream& os, const WORKER& w);
};

bool operator<(const WORKER& w1, const WORKER& w2) {
    return w1.position < w2.position;
}

ostream& operator<<(ostream& os, const WORKER& w) {
    os << w.name << " (" << w.position << ", " << w.year << ")";
    return os;
}


