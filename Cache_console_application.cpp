// Cache_console_application.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

typedef struct Lru_Cache {                    // Структура кэш-таблицы
    long long int size_of_cache;
    vector <long long int> cache_table;

    int find(int value) {
        int answ = 0;
        for (int i = 0; i < cache_table.size(); i++) {
            if (cache_table[i] == value) answ = 1;
        }
        if (cache_table.size() >= size_of_cache) {
            cache_table.push_back(value);
            cache_table.erase(cache_table.begin());
        }
        else {
            cache_table.push_back(value);
        }
        return answ;
    }
} LRU_Table;




int main() {
    long long int size_of_cache, N;
    long long int value, count = 0;
    LRU_Table Cache_table;                     // Создание кэш-таблицы

    cin >> size_of_cache >> N;                 // Считывание значений

    Cache_table.size_of_cache = size_of_cache; 

    for (int i = 0; i < N; i++) { 
        cin >> value;                          // Проход по циклу, считывание значений для таблицы        
        count += Cache_table.find(value);
    }

    cout << count;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

