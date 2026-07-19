/*
* project   : https://github.com/Robin005cr/100_days_cpp_challenge
* file name : hashmap.cpp
* author    : Robin CR
* mail id   : robinchovallurraju@gmail.com
* LinkedIn  : https://www.linkedin.com/in/robin-cr/
* portfolio : https://robin005cr.github.io/
*
* Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
* Suggestions for improvements or better methods are always welcome and appreciated.
* I value constructive feedback and aim to continuously improve the quality of the work.
*
*/

// Key design decisions:

// Separate chaining (vector<list<pair<int,int>>>) rather than open addressing — simpler to implement correctly, and deletion doesn't require tombstones.
// Dynamic resizing at load factor 0.75 keeps average bucket length ~O(1), so get/put/remove stay amortized O(1).
// Structured bindings (auto& [k, v]) make bucket traversal readable — cleaner than .first/.second.
// get is const-correct since it doesn't mutate state.
#include <vector>
#include <list>
#include <utility>

class MyHashMap {
private:
    static const int INITIAL_BUCKETS = 16;
    std::vector<std::list<std::pair<int, int>>> buckets;
    int count;

    int hash(int key) const {
        return key % buckets.size();
    }

    void rehash() {
        std::vector<std::list<std::pair<int, int>>> old = std::move(buckets);
        buckets.assign(old.size() * 2, {});
        count = 0;
        for (auto& bucket : old) {
            for (auto& [k, v] : bucket) {
                put(k, v);
            }
        }
    }

public:
    MyHashMap() : buckets(INITIAL_BUCKETS), count(0) {}

    void put(int key, int value) {
        int idx = hash(key);
        for (auto& [k, v] : buckets[idx]) {
            if (k == key) {
                v = value;
                return;
            }
        }
        buckets[idx].emplace_back(key, value);
        count++;

        // load factor > 0.75 -> grow
        if (count > buckets.size() * 3 / 4) {
            rehash();
        }
    }

    int get(int key) const {
        int idx = key % buckets.size();
        for (const auto& [k, v] : buckets[idx]) {
            if (k == key) return v;
        }
        return -1; // not found
    }

    void remove(int key) {
        int idx = hash(key);
        auto& bucket = buckets[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                count--;
                return;
            }
        }
    }
};