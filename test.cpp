#include <iostream>
#include <cassert>
#include "cache.hpp"


class Tcase{
  int size_of_cache;
  vector <int> cache_t;
  int res_of_test;
public:
  Tcase(int, vector <int>, int);

  int get_sizeof_cache() {return size_of_cache;}
  vector <int> get_cache_t() {return cache_t;}
  int get_res_of_test() {return res_of_test;}
};


Tcase::Tcase(int size_of_cache_, vector <int> cache_t_, int res_of_test_){
  size_of_cache = size_of_cache_;
  cache_t = cache_t_;
  res_of_test = res_of_test_;
}


int test_func(Tcase test){
  Cache <long long int, long long int> cache_table;
  cache_table.size_of_cache = test.get_sizeof_cache();
  auto value = test.get_cache_t();
  int count = 0;
  int l = value.size();
  for(int i = 0; i < l; i++){
    count += cache_table.find_value(value[i]);
  }
  return count;
}


int main(void){
  // документация по doxygen
    vector <Tcase> test_cases = {Tcase(2, {1, 2, 3, 2, 1}, 1),
                                 Tcase(3, {1, 1, 1, 1, 1, 1}, 5),
                                 Tcase(2, {1, 3, 2, 4, 2}, 1),
                                 Tcase(4, {1, 3, 4, 5, 3, 5}, 2),
                                 Tcase(5, {1, 2, 3, 4, 5, 5, 3, 1}, 3)};

    int len = test_cases.size();
    for(int i = 0; i < len; i++){
      assert(test_func(test_cases[i]) == test_cases[i].get_res_of_test());
    } 

    std::cout << "All tests passed" << std::endl;

    return 0;    
}
