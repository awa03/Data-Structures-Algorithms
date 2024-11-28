#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <iostream>

template<typename T, typename K>
class hash_map{
public:

private:
  int hash(){

  }

  void init(){
    _size = 0; 
  }

  std::vector<std::pair<T, K>> map;
  int _size;
};

#endif
