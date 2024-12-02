#include "trie.hpp"
#include <iostream>
#include <vector>
#include <string>

#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected [" << expected << "], but got [" << actual << "]\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }

void test_default_constructor() {
    trie t;
    ASSERT_EQ(0, t.size(), "Trie should be empty after default construction");
}

void test_insert_and_find() {
    trie t;
    ASSERT_EQ(true, t.insert("cat"), "Inserting 'cat' should return true");
    ASSERT_EQ(true, t.find("cat"), "'cat' should be found in the trie");

    // Insert a duplicate word 'cat'
    ASSERT_EQ(false, t.insert("cat"), "Inserting duplicate 'cat' should return false");
    ASSERT_EQ(true, t.find("cat"), "'cat' should still be found after duplicate insertion attempt");

    // Try inserting 'car' and check if it's inserted successfully
    ASSERT_EQ(true, t.insert("car"), "Inserting 'car' should return true");
    ASSERT_EQ(true, t.find("car"), "'car' should be found in the trie");

    // Try inserting a word that shares a prefix but is not a duplicate
    ASSERT_EQ(true, t.insert("cart"), "Inserting 'cart' should return true");
    ASSERT_EQ(true, t.find("cart"), "'cart' should be found in the trie");

    // Insert a word with common prefix ('ca'), but it is not inserted as a word itself
    ASSERT_EQ(true, t.insert("ca"), "Inserting 'ca' as a full word should return true");
    ASSERT_EQ(true, t.find("ca"), "'ca' should be found in the trie");
}

void test_remove() {
    trie t;
    t.insert("cat");
    t.insert("car");
    t.insert("cart");

    // Remove "car" and check its effects
    ASSERT_EQ(true, t.remove("car"), "Removing 'car' should return true");
    ASSERT_EQ(false, t.find("car"), "'car' should not be found after removal");

    // "cat" and "cart" should still be in the trie
    ASSERT_EQ(true, t.find("cat"), "'cat' should still be found after removing 'car'");
    ASSERT_EQ(true, t.find("cart"), "'cart' should still be found after removing 'car'");

    // Remove a non-existent word "dog"
    ASSERT_EQ(false, t.remove("dog"), "Removing non-existent 'dog' should return false");
}

void test_bulk_insert() {
    trie t;
    std::vector<std::string> words = {"apple", "banana", "grape", "cherry", "date"};
    
    // Insert all words
    for (const auto& word : words) {
        ASSERT_EQ(true, t.insert(word), "Inserting '" + word + "' should return true");
    }

    // Size of trie should match the number of unique words inserted
    ASSERT_EQ(words.size(), t.size(), "Trie size should match number of unique words inserted");

    // Try inserting duplicate words and ensure they are not inserted
    for (const auto& word : words) {
        ASSERT_EQ(false, t.insert(word), "Inserting duplicate '" + word + "' should return false");
    }

    // Verify each word can be found
    for (const auto& word : words) {
        ASSERT_EQ(true, t.find(word), "Finding '" + word + "' should return true");
    }
}

void test_prefix_and_partial_matches() {
    trie t;
    t.insert("apple");

    // Find complete word "apple"
    ASSERT_EQ(true, t.find("apple"), "'apple' should be found");

    // "app" is a prefix but not a complete word by default
    ASSERT_EQ(false, t.find("app"), "'app' should not be found (prefix only)");

    // Now insert "app" explicitly
    t.insert("app");
    ASSERT_EQ(true, t.find("app"), "'app' should be found after explicit insertion");

    // Test prefix 'ap' to confirm it won't be found as a complete word
    ASSERT_EQ(false, t.find("ap"), "'ap' should not be found as a complete word");
}

void test_large_data_handling() {
    trie t;
    // Insert 1,000 words to avoid potential memory issues
    for (int i = 0; i < 1000; ++i) {
        t.insert("word" + std::to_string(i));
    }

    // Trie size should match the number of unique words inserted
    ASSERT_EQ(1000, t.size(), "Trie size should be 1,000 after inserting 1,000 words");

    // Check that a word that was not inserted is not found
    ASSERT_EQ(false, t.find("word1000"), "'word1000' should not be found (not inserted)");

    // Check a word that was inserted (word999)
    ASSERT_EQ(true, t.find("word999"), "'word999' should be found");

    // Ensure duplicate insertions do not affect trie size
    for (int i = 0; i < 1000; ++i) {
        ASSERT_EQ(false, t.insert("word" + std::to_string(i)), "Inserting duplicate 'word" + std::to_string(i) + "' should return false");
    }
}

int main() {
    test_default_constructor();
    test_insert_and_find();
    test_remove();
    test_bulk_insert();
    test_prefix_and_partial_matches();
    test_large_data_handling();

    std::cout << "\033[32mAll trie tests completed.\033[0m\n";
    return 0;
}
