#include "BlindHashing.h"
#include "Crime.h"
#include "LinearProbing.h"
#include "QuadraticProbing.h"
#include "QuadraticFreddieHash.h"
#include "SeparateChaining.h"
#include "SeparateChainingFreddieHash.h"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;


string get_crime_id(Crime cri);
string get_crime_name(Crime cri);


int main() {

    // 1. Store objects in a vector:
    vector<Crime> crimes;
    getCrimesFromFile("../CRIME_DATA_Random.csv", crimes);

    // 2. Insert your objects into two hash tables:
    // 3. Calculate for each hash table:

    // a. Record # of Reads
    vector<vector<int>> separate_chaining_reads;
    vector<vector<int>> quadratic_probing_reads;
    vector<vector<int>> separate_chaining_fh_reads;
    vector<vector<int>> quadratic_fh_reads;


    // b. Hash tables of 5 different prime numbers
    vector<int> prime_numbers = {1453, 2017, 2647, 3803, 4201};
    //vector<int> prime_numbers_test = {5, 7, 11, 13, 17};

    // SEPARATE CHAINING
    cout << "SEPARATE CHAINING" << endl;
    for (int prime : prime_numbers) {
        SeparateChaining<Crime> hash_table_sc(prime, get_crime_id);
        // counter
        int n = 0;
        for (Crime &cri : crimes) {
            vector<int> data;
            // push back: reads, table size, prime
            data = hash_table_sc.insert(cri);
            data.push_back(prime);

            // increase counter and push back
            ++n;
            data.push_back(n);

            separate_chaining_reads.push_back(data);
            data.clear();
        }
    }

    // QUADRATIC PROBING
    cout << "Quadratic Probing" << endl;
    for (int prime : prime_numbers) {
        QuadraticProbing<Crime> hash_table_qp(prime, get_crime_id);
        int n = 0;
        for (Crime &cri : crimes) {
            vector<int> data;
            data = hash_table_qp.insert(cri);
            data.push_back(prime);

            // increase counter and push back
            ++n;
            data.push_back(n);

            quadratic_probing_reads.push_back(data);
            data.clear();
        }
    }

    // c. Change hash function and get_key function
    // create 2 new classes and run them as above
    cout << "Quadratic Probing Freddie Hash" << endl;
    for (int prime : prime_numbers) {
        QuadraticFreddieHash<Crime> hash_table_qpfh(prime, get_crime_name);
        int n = 0;
        for (Crime &cri : crimes) {
            vector<int> data;
            data = hash_table_qpfh.insert(cri);
            data.push_back(prime);
            // increase counter and push back
            ++n;
            data.push_back(n);

            quadratic_fh_reads.push_back(data);
            data.clear();
        }
    }

    cout << "Separate Chaining Freddie Hash" << endl;
    for (int prime : prime_numbers) {
        SeparateChainingFreddieHash<Crime> hash_table_scfh(prime, get_crime_name);
        int n = 0;
        for (Crime &cri : crimes) {
            vector<int> data;
            data = hash_table_scfh.insert(cri);
            data.push_back(prime);
            // increase counter and push back
            ++n;
            data.push_back(n);
            separate_chaining_fh_reads.push_back(data);
            data.clear();
        }
    }

    // Output above vectors to three separate csv files
    ofstream fileOut;

    // Header for time files
    vector<string> timeHeader = {"reads, size, prime, n"};

    // create/open quadratic file
    fileOut.open ("../data/quadratic.csv");
    // populate headers in file
    for (string name : timeHeader) {
        fileOut << name;
        fileOut << ",";
    }
    fileOut << "\n";
    // insert data
    for (vector<int> row : quadratic_probing_reads) {
        for (int point : row) {
            fileOut << point;
            fileOut << ",";
        }
        fileOut << "\n";
    }
    // close file
    fileOut.close();

    // create/open quadratic with freddie hash & get crime name key file
    fileOut.open ("../data/quadratic_fh.csv");
    // populate headers in file
    for (string name : timeHeader) {
        fileOut << name;
        fileOut << ",";
    }
    fileOut << "\n";
    // insert data
    for (vector<int> row : quadratic_fh_reads) {
        for (int point : row) {
            fileOut << point;
            fileOut << ",";
        }
        fileOut << "\n";
    }
    // close file
    fileOut.close();

    // create/open separate chaining file
    fileOut.open ("../data/chaining.csv");
    // populate headers in file
    for (string name : timeHeader) {
        fileOut << name;
        fileOut << ",";
    }
    fileOut << "\n";
    // insert data
    for (vector<int> row : separate_chaining_reads) {
        for (int point : row) {
            fileOut << point;
            fileOut << ",";
        }
        fileOut << "\n";
    }
    // close file
    fileOut.close();

    // create/open separate chaining with freddie hash & get crime name key file
    fileOut.open ("../data/chaining_fh.csv");
    // populate headers in file
    for (string name : timeHeader) {
        fileOut << name;
        fileOut << ",";
    }
    fileOut << "\n";
    // insert data
    for (vector<int> row : separate_chaining_fh_reads) {
        for (int point : row) {
            fileOut << point;
            fileOut << ",";
        }
        fileOut << "\n";
    }
    // close file
    fileOut.close();


    return 0;
}


string get_crime_id(Crime cri) {
    return cri.getIncidentID();
}

string get_crime_name(Crime cri) {
    return cri.getOffense();
}