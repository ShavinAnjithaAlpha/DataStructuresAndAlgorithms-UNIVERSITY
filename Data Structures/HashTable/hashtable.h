#include<stdexcept>

#pragma one

template<typename T>
class HashNode {
public:
    // member variables
    std::string key;
    T value;
    HashNode<T> *next;

    HashNode(cons std::string& key, const T& value, HashNode<T> *next = nullptr) :
        key{key}, value{value}, next{next} {
            // empty constructor
        }

    // copy constructor
    HashNode(const HashNode<T>& node) : key{node.key}, value{node.value}, next{node.next} {
        // empty constructor body
    }
};

template<typename T>
class HashMap {
    // constructors
    HashMap(size_t N_size = DEFAULT_BICKETS_SIZE) : N_elements{0}, N_buckets{N_Size} {

        // initialize all the nodes to default values
        arr = new hashNode<T>[N_buckets] {};
    }

private:
    // private helper functions
    int hash(const std::string& key) const {
        const static int prime_number{31};

        


    }

private:
    const static size_t DEFAULT_BUCKETS_SIZE = 1; // default number of buckets in the hahs map array 

    size_t N_elements; // numebr of elements in the current hash map
    size_t N_buckets; // number of buckets in the hash map
    HashNode<T> **arr; // array of HashNodes pointers to store bucket hash nodes

};