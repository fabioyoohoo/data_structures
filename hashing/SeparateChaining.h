//
// Created by Frederick Hall on 2019-04-10.
//

#ifndef HASHING_SEPARATECHAINING_H
#define HASHING_SEPARATECHAINING_H

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
class SeparateChaining {
private:
    // Each index will hold a vector of Hashables
    vector<vector<Hashable>> hash_table;
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

    // record reads from looking through find
    int reads = 0;

public:
    // Constructor
    SeparateChaining(int table_size, function<string(Hashable)> get_key) {
        this->get_key = get_key;
        this->table_size = table_size;
        hash_table.resize(table_size);
        // Make sure each index has an empty vector
        for (int i = 0; i < table_size; ++i) {
            hash_table[i].clear();
        }
    }

    // Store an item
    vector<int> insert(Hashable item) {
        // declare return vector
        vector<int> data;

        // Get the key from the item
        string key = get_key(item);
        // If find returns nullopt, then I can insert
        if (!find(key)) {
            // Hash the key to get an index
            unsigned int index = horner_hash(key);
            // Store the item at that index in the hash_table
            hash_table[index].push_back(item);
        }
        data.push_back(reads);
        data.push_back(table_size);
        reads = 0;
        return data;
    }

    // Find an item
    optional<Hashable> find(string key)  {
        unsigned int index = horner_hash(key);
        // Check to see if the item is in the vector at that index
        for (int i = 0; i < hash_table[index].size(); ++i) {
            // increment reads
            ++reads;
            if (key == get_key(hash_table[index][i])) {
                // Found the item. Return it.
                return hash_table[index][i];
            }
        }
        // Search failed.
        return nullopt;
    }

    // Delete an item
    // Returns true if we can find and remove the item
    bool remove(string key) {
        unsigned int index = horner_hash(key);
        // Check to see if the item is in the vector at that index
        for (int i = 0; i < hash_table[index].size(); ++i) {
            if (key == get_key(hash_table[index][i])) {
                // Found the item. Remove it.
                // The vector erase method takes an iterator that points
                // to the object being erased.
                hash_table[index].erase(hash_table[index].begin() + i);
                return true;
            }
        }
        // Search failed.
        return false;
    }

    // Print the table
    void print_table() const {
        for (int i = 0; i < hash_table.size(); ++i) {
            cout << i << ": ";
            for (int j = 0; j < hash_table[i].size(); ++j) {
                cout << hash_table[i][j] << ", ";
            }
            cout << endl;
        }
    }
};



#endif //HASHING_SEPARATECHAINING_H
