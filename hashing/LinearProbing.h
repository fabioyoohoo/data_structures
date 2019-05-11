//
// Created by Frederick Hall on 2019-04-05.
//

#ifndef HASHING_LINEARPROBING_H
#define HASHING_LINEARPROBING_H


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
class LinearProbing {
private:
    // Create a status
    enum status {EMPTY, FULL, REMOVED};
    struct hash_status {
        Hashable item;
        status condition;
    };

    // Each index will hold Hashable or nullopt
    vector<hash_status> hash_table;
    int table_size;
    int num_hash_items;

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
    // Find the next prime number
    int next_prime(int n) {
        if (n % 2 == 0) {
            ++n;
        }
        bool prime = false;
        while (!prime) {
            prime = true;
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    prime = false;
                }
            }
            n += 2;
        }
        return (n-2);
    }

    // Rehash to a larger size
    void rehash() {
        // Save a copy of the old table
        vector<hash_status> old_table = hash_table;
        // Increase the table size
        // Placeholder number
        table_size = next_prime(table_size * 2);
        // Empty the hash table
        hash_table.clear();
        // Resize to larger size
        hash_table.resize(table_size);
        // Reset the number of hash items
        num_hash_items = 0;
        // Re-insert all of the FULL hash items
        for (hash_status &hash_item : old_table) {
            if (hash_item.condition == FULL) {
                insert(hash_item.item);
            }
        }
    }


public:
    // Constructor
    LinearProbing(int table_size, function<string(Hashable)> get_key) {
        this->get_key = get_key;
        this->table_size = table_size;
        hash_table.resize(table_size);
        for (int i = 0; i < table_size; ++i) {
            hash_table[i].condition = EMPTY;
        }
        num_hash_items = 0;
    }

    // Store an item
    bool insert(Hashable item) {
        // Get the key from the item
        string key = get_key(item);
        // Call Find with key. If item already in table, do not insert
        if (find(key) != nullopt) {
            return false;
        }
        // Hash the key to get an index
        unsigned int index = horner_hash(key);
        unsigned int hash_index = index;
        // Store the item at that index in the hash_table
        // Keep probing while hash_table[index] is FULL
        while (hash_table[index].condition == FULL) {
            ++index;
            // If we reach the end of the table, go to the beginning
            if (index == table_size) {
                index = 0;
            }
            // Check if we've made a full loop of the table
            if (index == hash_index) {
                // There is no room for a new item
                return false;
            }
        }
        // We have found an index that is not FULL
        // Insert the item
        hash_table[index].item = item;
        hash_table[index].condition = FULL;
        ++num_hash_items;
        if (num_hash_items > (table_size / 2)) {
            rehash();
        }
        return true;
    }

    // Find an item
    optional<Hashable> find(string key) const {
        // Hash the key to get an index
        unsigned int index = horner_hash(key);
        unsigned int hash_index = index;
        // Keep probing until we find the item or
        // make a full loop of the hash_table or
        // find an empty index
        while (hash_table[index].condition != EMPTY) {
            // Check if we found the item
            if (hash_table[index].condition == FULL &&
                key == get_key(hash_table[index].item)) {
                // Search successful
                return hash_table[index].item;
            }
            ++index;
            // If we reach the end of the table, go to the beginning
            if (index == table_size) {
                index = 0;
            }
            // Check if we've made a full loop of the table
            if (index == hash_index) {
                // Search failed
                return nullopt;
            }
        }
        // Search failed
        return nullopt;
    }


    // Remove an item
    // Return true if we can find and remove the item
    bool remove(string key) {
        // Hash the key to get an index
        unsigned int index = horner_hash(key);
        unsigned int hash_index = index;
        // Keep probing until we find the item or
        // make a full loop of the hash_table or
        // find an empty index
        while (hash_table[index].condition != EMPTY) {
            // Check if we found the item
            if (hash_table[index].condition == FULL &&
                key == get_key(hash_table[index].item)) {
                // Found the item. Mark it as removed.
                hash_table[index].condition = REMOVED;
                return true;
            }
            ++index;
            // If we reach the end of the table, go to the beginning
            if (index == table_size) {
                index = 0;
            }
            // Check if we've made a full loop of the table
            if (index == hash_index) {
                // Search failed
                return false;
            }
        }
        // Search failed
        return false;
    }

    // Print the table
    void print_table() const {
        for (int i = 0; i < hash_table.size(); ++i) {
            cout << i << ": ";
            if (hash_table[i].condition == FULL) {
                cout << hash_table[i].item;
            } else if (hash_table[i].condition == REMOVED) {
                cout << "X";
            }
            cout << endl;
        }
    }
};



#endif //HASHING_LINEARPROBING_H
