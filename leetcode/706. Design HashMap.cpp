// https://leetcode.com/problems/design-hashmap/

// Design a HashMap without using any built-in hash table libraries.
// To be specific, your design should include these functions:
// put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
// get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

// Example:
// MyHashMap hashMap = new MyHashMap();
// hashMap.put(1, 1);          
// hashMap.put(2, 2);         
// hashMap.get(1);            // returns 1
// hashMap.get(3);            // returns -1 (not found)
// hashMap.put(2, 1);          // update the existing value
// hashMap.get(2);            // returns 1 
// hashMap.remove(2);          // remove the mapping for 2
// hashMap.get(2);            // returns -1 (not found) 

// Note:
// All keys and values will be in the range of [0, 1000000].
// The number of operations will be in the range of [1, 10000].
// Please do not use the built-in HashMap library.

#include <iostream>
#include <array>

using namespace std;

#define CAP 10
typedef array<void*, CAP> memBlock;

class MyHashMap {
private:
    memBlock* data;
    int storage_capacity = 1000000;
    
    void** get_location(int key) {
        memBlock* current = data;
        int boundary = storage_capacity / 10;
        int index;
        
        while (boundary != 1) {
            index = key / boundary;
            if (current->at(index) == nullptr) {
                current->at(index) = new memBlock();
                ((memBlock*)current->at(index))->fill(nullptr);
            }
            current = (memBlock*)current->at(index);
            if (key >= boundary) {
                key -= index * boundary;
            }
            boundary = boundary / 10;
        }
        
        return &current->at(key);
    }
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        data = new memBlock();
        data->fill(nullptr);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        void** ptr = get_location(key);
        int* newInt = new int(value);
        *ptr = (void*)newInt;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        void** ptr = get_location(key);
        if (*ptr == nullptr)
            return -1;
        else
            return *(int*)*ptr;
    }
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        void** ptr = get_location(key);
        delete((int*)*ptr);
        *ptr = nullptr;
    }
};
