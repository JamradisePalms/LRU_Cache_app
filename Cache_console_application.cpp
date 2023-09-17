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
} Vitalik;




int main() {
    long long int size_of_cache, N;
    long long int value, count = 0;
    Vitalik Cache_table;

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

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
