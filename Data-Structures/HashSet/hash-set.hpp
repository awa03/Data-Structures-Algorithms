#ifndef HASH_SET_HPP
#define HASH_SET_HPP

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <stdexcept>
#include <functional>

template<typename T>
class hash_set {
public:
    hash_set(size_t bucket_count = 16) : buckets(bucket_count), _size(0) {}

    void rehash() {
        size_t new_size = buckets.size() * 2;
        std::vector<std::list<T>> new_buckets(new_size);

        for (const auto& bucket : buckets) {
            for (const auto& entry : bucket) {
                size_t new_index = std::hash<T>()(entry) % new_size;
                new_buckets[new_index].push_back(entry);
            }
        }

        buckets = std::move(new_buckets);
    }

    void insert(const T& value) {
        if (_size > buckets.size() * 0.75) {
            rehash();
        }

        size_t index = hash(value);
        for (const auto& entry : buckets[index]) {
            if (entry == value) {
                return;  // Value already exists, no need to insert.
            }
        }

        buckets[index].push_back(value);
        ++_size;
    }

    bool remove(const T& value) {
        size_t index = hash(value);
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == value) {
                bucket.erase(it);
                --_size;
                return true;
            }
        }
        return false;
    }

    bool contains(const T& value) const {
        size_t index = hash(value);
        for (const auto& entry : buckets[index]) {
            if (entry == value) {
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
            for (const auto& entry : buckets[i]) {
                std::cout << entry << " ";
            }
            std::cout << "\n";
        }
    }

private:
    size_t hash(const T& value) const {
        return std::hash<T>{}(value) % buckets.size();
    }

    std::vector<std::list<T>> buckets;
    size_t _size;
};

#endif
