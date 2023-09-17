// Cache_console_application.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
using namespace std;

typedef struct Lru_Cache {
    long long int size_of_cache;
    vector <long long int> cache_table;

    int find(int value) {
        int answ = 0;
        int index = -1;
        int tmp = -1;
        for (int i = 0; i < cache_table.size(); i++) {
            if (cache_table[i] == value) {
                answ = 1;
                index = i;
                tmp = cache_table[i];
                break;
            }
        }
    
        if (cache_table.size() >= size_of_cache) {
            if (index != -1) {
                for (int i = index; i < cache_table.size() - 1; i++) {
                    cache_table[i] = cache_table[i + 1];
                }
                cache_table[cache_table.size() - 1] = tmp;
                return answ;
            }
            else {
                cache_table.push_back(value);
                cache_table.erase(cache_table.begin());
            }
        }
        else {
            cache_table.push_back(value);
        }
        return answ;
    }
} LRU_Cache;




int main() {
    long long int size_of_cache, N;
    long long int value, count = 0;
    LRU_Cache Cache_table;

    cin >> size_of_cache >> N;

    Cache_table.size_of_cache = size_of_cache;

    for (int i = 0; i < N; i++) {
        cin >> value;
        count += Cache_table.find(value);
    }
    cout << count;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

