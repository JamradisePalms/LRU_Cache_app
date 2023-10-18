#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

template <typename T, typename T_size>
typedef struct Cache{

    T_size size_of_cache; // размер кэша
    vector <T> cache_table; // массив с индексами
    
    int find_value(T value){

        auto hit = find(cache_table.begin(), cache_table.end(), value); // индекс нового элемента в массиве

        if (cache_table.size() < size_of_cache){ // если кэш ещё не заполнен
            if (hit != cache_table.end()){ // новый элемент есть в кэше -> перезаписываем его в конец
                cache_table.erase(hit);
                cache_table.push_back(value);
                return 1;
            }
            cache_table.push_back(value); // нового элемента нет в кэше -> записываем его в конец
            return 0;
        }
        else{ // если кэш уже забит
            if (hit == cache_table.end()){ // нового элемента в кэше нет -> удалям первый элемент (самый старый) и записываем новый в конец
                cache_table.push_back(value);
                cache_table.erase(cache_table.begin());
                return 0;
            }
            else{ // новый элемент в кэше есть -> перезаписываем его в конец
                cache_table.erase(hit);
                cache_table.push_back(value);
               return 1;
           }
       }
    }
}; 
