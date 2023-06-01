#include<stdexcept>

#pragma one

using ll = long long;
template<typename T>
class HashNode {
public:
    // member variables
    std::string key;
    T value;
    HashNode<T> *next;

    HashNode(const std::string& key, const T& value, HashNode<T> *next = nullptr) :
        key{key}, value{value}, next{next} {
            // empty constructor
        }

    // copy constructor
    HashNode(const HashNode<T>& node) : key{node.key}, value{node.value}, next{node.next} {
        // empty constructor body
    }

    ~HashNode() {
        // delete all the following hash nodes
        HashNode<T> *current{this}, *prevNode{nullptr};
        while (current != nullptr) {
            prevNode = current;
            current = current->next;
            delete prevNode;
        }

    }
};

template<typename T>
class HashMap {

    friend std::ostream& operator <<(std::ostream& out, const HashMap<T>& hash_map) {

        for (int i{0}; i < hash_map.N_buckets; i++) {
            HashNode<T> *currentNode{hash_map.arr[i]};
            std::cout << i << " -> ";
            while (currentNode != nullptr) {
                std::cout << "(" << currentNode->key << ", " << currentNode->value << ") ";
            }
            std::cout << "\n";
        }
        return out;

    }

public:
    // constructors
    HashMap(size_t N_Size = 1) : N_elements{0}, N_buckets{N_Size} {

        // initialize all the nodes to default values
        arr = new HashNode<T>*[N_buckets] {};
        for (int i{0}; i < N_buckets; i++) arr[i] = nullptr;
    }

    // utility methods of the hash map
    void insert(const std::string& key, const T& value) {

        while (load_factor() > MAX_LOAD_FACTOR) {
            rehash();
        }

        // first find the hash value of the given string key
        int bucket_index = hash(key);

        // check whether given key is already in the hash map and find the corresponding hash node
        HashNode<T> *currentNode{arr[bucket_index]};
        while (currentNode != nullptr) {
            if (currentNode->key == key) {
                currentNode->value = value;
                return;
            }
            currentNode = currentNode->next;
        }

        // add new key value pair to the corresponding bucket list
        HashNode<T> *firstNode{arr[bucket_index]};
        arr[bucket_index] = new HashNode<T>(key, value, firstNode); 
        N_elements++;
    } 

    ~HashMap() {
        // delete the array
        delete [] arr;
    }

private:
    // rehash the entire hash table with doubling array size;
    void rehash() {

        // get the current hash table array to temporary pointer
        HashNode<T> **temp_arr{arr};
        size_t prev_capacity{N_buckets};
        N_buckets  = (N_buckets * 2) % SIZE_MAX;

        if (N_buckets == prev_capacity) return;
        // create new arr with their default values
        arr = new HashNode<T>*[N_buckets];
        // rehash every value in the table and insert into the newly created array
        for (int i{0}; i < prev_capacity; i++) {
            HashNode<T> *currentNode{temp_arr[i]};
            while (currentNode != nullptr) {
                // get the new bucket imdex for current hash node key
                int bucket_index = hash(currentNode->key);
                HashNode<T> *firstNode{arr[bucket_index]};
                arr[bucket_index] = new HashNode<T>(currentNode->key, currentNode->value, firstNode);
                currentNode = currentNode->next;
            }
        }

        // delete previous arrray 
        delete [] temp_arr;

    }

    float load_factor() const {
        return (float) (N_elements + 1) / (float) N_buckets;
    }

    // private helper functions
    int hash(const std::string& key) const {
        const static int prime_number{31};
        int factor{prime_number};
        ll sum{0};

        for (const char& c : key) {
            sum += (factor * (int) c) % N_buckets;
            factor = (factor * prime_number) % INT16_MAX;
        }

        return sum % N_buckets;

    }

private:
    const size_t DEFAULT_BUCKETS_SIZE = 1; // default number of buckets in the hahs map array 
    const float MAX_LOAD_FACTOR = 0.5f; // maximum load factor the hash map can hold

    size_t N_elements; // numebr of elements in the current hash map
    size_t N_buckets; // number of buckets in the hash map
    HashNode<T> **arr; // array of HashNodes pointers to store bucket hash nodes

};