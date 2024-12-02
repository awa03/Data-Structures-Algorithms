
#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <stdexcept>
#include <functional>

template<typename T, typename K>
class hash_map {
public:
    hash_map(size_t bucket_count = 16) : buckets(bucket_count), _size(0) {}

    void rehash() {
        size_t new_size = buckets.size() * 2;
        std::vector<std::list<std::pair<T, K>>> new_buckets(new_size);

        for (const auto& bucket : buckets) {
            for (const auto& entry : bucket) {
                size_t new_index = std::hash<T>()(entry.first) % new_size;
                new_buckets[new_index].emplace_back(entry);
            }
        }

        buckets = std::move(new_buckets);
    }

    void insert(const T& key, const K& value) {
        if (_size > buckets.size() * 0.75) {
            rehash();
        }

        size_t index = hash(key);
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }

        buckets[index].emplace_back(key, value);
        ++_size;
    }

    bool remove(const T& key) {
        size_t index = hash(key);
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                --_size;
                return true;
            }
        }
        return false;
    }

    K& at(const T& key) {
        size_t index = hash(key);
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    const K& at(const T& key) const {
        size_t index = hash(key);
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    bool contains(const T& key) const {
        size_t index = hash(key);
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                return true;
            }
        }
        return false;
    }

    void clear() {
        for (auto& bucket : buckets) {
            bucket.clear();
        }
        _size = 0;
    }

    size_t size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

    void print() const {
        for (size_t i = 0; i < buckets.size(); ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& pair : buckets[i]) {
                std::cout << "{" << pair.first << ": " << pair.second << "} ";
            }
            std::cout << "\n";
        }
    }

private:
    size_t hash(const T& key) const {
        return std::hash<T>{}(key) % buckets.size();
    }

    std::vector<std::list<std::pair<T, K>>> buckets;
    size_t _size;
};

#endif

