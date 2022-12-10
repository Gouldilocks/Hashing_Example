#include <iostream>
#include <string>
using namespace std;

size_t my_hash(string hashMe){
    size_t my_size = 0;
    for (int i = 0; i < hashMe.size(); i++) {
//        cout << "looking at character: " << hashMe[i] << ", and has value of " << int(hashMe[i]) << endl;
        my_size += hashMe[i];
    }
    return my_size;
}

int main() {
    // initialize the array where we will store the mapping
    string arr[1000];

    // this is the sample string we will map to an id
    string file("/data/set1/lord_of_the_rings_book_1.xlm");

    // initialize the hasher object from std::hash
    hash<string> hasher;
    // call the hash function to get the hash
    size_t hashed_size = hasher.operator()(file);

//    size_t hashed_size = my_hash(file);
    cout << hashed_size << endl;
    // make the hash only a number between 0-999
    hashed_size = hashed_size % 1000;

    // insert the string into the mapping array
    arr[hashed_size] = file;

    // print the unique id
    cout << hashed_size << endl;
    // print out the mapped string
    cout << arr[hashed_size] << endl;

    return 0;
}
