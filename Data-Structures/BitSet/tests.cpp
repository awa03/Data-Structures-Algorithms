#include "bit-set.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <chrono>

#define ASSERT_EQ(expected, actual, message) \
if ((expected) != (actual)) { \
  std::cerr << "\033[31mERROR | " << message << ": Expected [" << expected << "], but got [" << actual << "]\033[0m\n"; \
} else { \
  std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
}

int main() {
  // Test 1: Default Constructor
  try {
    Bitset bitset(10);
    ASSERT_EQ(10, bitset.size(), "Bitset size after initialization");
  } catch (const std::exception& e) {
    std::cerr << "\033[31mERROR | Default Constructor Test Failed: " << e.what() << "\033[0m\n";
  }

  // Test 2: Setting and Getting Bits
  try {
    Bitset bitset(10);
    bitset.set(3);
    bitset.set(7);
    ASSERT_EQ(true, bitset.get(3), "Bit at index 3 should be set to 1");
    ASSERT_EQ(true, bitset.get(7), "Bit at index 7 should be set to 1");
    ASSERT_EQ(false, bitset.get(0), "Bit at index 0 should be 0");
  } catch (const std::exception& e) {
    std::cerr << "\033[31mERROR | Setting and Getting Bits Test Failed: " << e.what() << "\033[0m\n";
  }

  // Test 3: Resetting Bits
  try {
    Bitset bitset(10);
    bitset.set(3);
    bitset.reset(3);
    ASSERT_EQ(false, bitset.get(3), "Bit at index 3 should be reset to 0");
  } catch (const std::exception& e) {
    std::cerr << "\033[31mERROR | Resetting Bits Test Failed: " << e.what() << "\033[0m\n";
  }

  // Test 4: Flipping Bits
  try {
    Bitset bitset(10);
    bitset.set(3);
    bitset.flip(3);
    ASSERT_EQ(false, bitset.get(3), "Bit at index 3 should be flipped to 0");
    bitset.flip(3);
    ASSERT_EQ(true, bitset.get(3), "Bit at index 3 should be flipped back to 1");
  } catch (const std::exception& e) {
    std::cerr << "\033[31mERROR | Flipping Bits Test Failed: " << e.what() << "\033[0m\n";
  }

  // Test 5: Out of Range Error
  try {
    Bitset bitset(10);
    bitset.set(15);  // Out of range
  } catch (const std::out_of_range& e) {
    std::cout << "\033[32mPASS | Out of Range Error Test: " << e.what() << "\033[0m\n";
  }

  // Test 6: Big Data Test using Bitset
  try {
    constexpr int BIG_DATA_SIZE = 100'000'000;
    auto start = std::chrono::high_resolution_clock::now();

    Bitset bitset(BIG_DATA_SIZE);
    for (int i = 0; i < BIG_DATA_SIZE; ++i) {
      bitset.set(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    ASSERT_EQ(BIG_DATA_SIZE, bitset.size(), "Bitset size after big data insertion");
    std::cout << "\033[32mPASS | Big Data Test: Successfully set " << BIG_DATA_SIZE << " bits in "
      << duration << "ms\033[0m\n";

    start = std::chrono::high_resolution_clock::now();

    bitset.flip();

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "\033[32mPASS | Big Data Test: Flip all " << BIG_DATA_SIZE << " bits in "
    << duration << "ms\033[0m\n";


    start = std::chrono::high_resolution_clock::now();

    bitset.reset();

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "\033[32mPASS | Big Data Test: Reset all " << BIG_DATA_SIZE << " bits in "
    << duration << "ms\033[0m\n";

  } catch (const std::exception& e) {
    std::cerr << "\033[31mERROR | Big Data Test Failed: " << e.what() << "\033[0m\n";
  }

  std::cout << "\033[32mAll tests completed.\033[0m\n";
  return 0;
}
