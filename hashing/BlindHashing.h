//
// Created by fabioyoohoo on 2019-04-10.
//

#ifndef HASHING_BLINDHASHING_H
#define HASHING_BLINDHASHING_H

#include <experimental/optional>
#include <iostream>
#include <functional>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::experimental::nullopt;
using std::experimental::optional;
using std::function;
using std::string;
using std::vector;


template<typename Hashable>
class BlindHashing {
private:
    // Each index will hold a Hashable or nullopt
    vector<optional<Hashable>> hash_table;
    int table_size;
    // Store the function to get a string key from a Hashable
    // We are assuming the keys are unique for each Hashable
    function<string(Hashable)> get_key;
    // Hashing method
    unsigned int horner_hash(string key) const {
        unsigned long hash_val = 0;
        for (char digit : key) {
            hash_val = hash_val * 37 + digit;
        }
        return hash_val % table_size;
    }

public:
    // Constructor
    BlindHashing(int table_size, function<string(Hashable)> get_key) {
        this->get_key = get_key;
        this->table_size = table_size;
        hash_table.resize(table_size);
        for (int i = 0; i < table_size; ++i) {
            hash_table[i] = nullopt;
        }
    }

    // Store an item
    void insert(Hashable item) {
        // Get the key from the item
        string key = get_key(item);
        // Hash the key to get an index
        unsigned int index = horner_hash(key);
        // Store the item at that index in the hash_table
        hash_table[index] = item;
    }

    // Find an item
    optional<Hashable> find(string key) const {
        unsigned int index = horner_hash(key);
        // Check to see if the item is at that index
        if (hash_table[index] && key == get_key(*hash_table[index])) {
            // Found the item. Return it.
            return hash_table[index];
        } else {
            // Search failed
            return nullopt;
        }
    }

    // Delete an item
    // Returns true if we can find and remove the item
    bool remove(string key) {
        unsigned int index = horner_hash(key);
        // Check to see if the item is at that index
        if (hash_table[index] && key == get_key(*hash_table[index])) {
            // Found item. Remove it.
            hash_table[index] = nullopt;
            return true;
        } else {
            // Search failed
            return false;
        }
    }

    // Print the table
    void print_table() const {
        for (int i = 0; i < hash_table.size(); i++) {
            cout << i << ": ";
            if (hash_table[i]) {
                // Use the * to access the Hashable from the optional
                cout << *hash_table[i];
            }
            cout << endl;
        }
    }
};


#endif //HASHING_BLINDHASHING_H
