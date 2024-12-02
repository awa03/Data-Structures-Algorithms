
#ifndef BITSET_HPP
#define BITSET_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

class Bitset {
public:
    Bitset(size_t size) : bits(size, false) {}

    void set(size_t index) {
        if (index >= bits.size()) {
            throw std::out_of_range("Index out of range");
        }
        bits[index] = true;
    }

    void reset(size_t index) {
        if (index >= bits.size()) {
            throw std::out_of_range("Index out of range");
        }
        bits[index] = false;
    }

    void reset(){
      for(int i =0; i < bits.size(); i++){
        bits[i] = 0;
      }

    }

    void flip(size_t index) {
        if (index >= bits.size()) {
            throw std::out_of_range("Index out of range");
        }
        bits[index] = !bits[index];
    }

    void flip(){
      for(int i =0; i < bits.size(); i++){
        bits[i] = !bits[i];
      }
    }

    bool get(size_t index) const {
        if (index >= bits.size()) {
            throw std::out_of_range("Index out of range");
        }
        return bits[index];
    }

    void print() const {
        for (bool bit : bits) {
            std::cout << (bit ? '1' : '0');
        }
        std::cout << std::endl;
    }

    size_t size() const {
        return bits.size();
    }

private:
    std::vector<bool> bits;
};

#endif

