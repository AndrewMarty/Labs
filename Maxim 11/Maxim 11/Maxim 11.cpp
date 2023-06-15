#include <iostream>
#include <queue>
using namespace std;
// Функция для печати очереди
void printQueue(queue<int> q) {
    while (!q.empty()) {
        std::cout << '\t' << q.front();
        q.pop();
    }
    std::cout << '\n';
}

// Функция для определения, сколько элементов находятся после максимального
int countAfterMax(queue<int> q) {
    int max_val = numeric_limits<int>::min();
    int max_pos = -1;
    int i = 0;

    queue<int> copy = q;
    while (!copy.empty()) {
        if (copy.front() > max_val) {
            max_val = copy.front();
            max_pos = i;
        }
        copy.pop();
        ++i;
    }

    return i - max_pos - 1;
}

// Функция для удаления четных положительных и нечетных отрицательных чисел
queue<int> filterQueue(queue<int> q) {
    queue<int> new_q;
    while (!q.empty()) {
        int val = q.front();
        if (!((val > 0 && val % 2 == 0) || (val < 0 && val % 2 != 0))) {
            new_q.push(val);
        }
        q.pop();
    }
    return new_q;
}

// Функция для сортировки очереди по модулю
queue<int> sortQueue(queue<int> q) {
    vector<int> temp;
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }
    sort(temp.begin(), temp.end(), [](int a, int b) {
        return abs(a) < abs(b);
        });

    for (int val : temp) {
        q.push(val);
    }
    return q;
}

// Функция для очистки очереди
void clearQueue(queue<int>& q) {
    while (!q.empty()) {
        q.pop();
    }
}

int main() {
    queue<int> q;

    // Заполнение очереди числами от -50 до 50
    for (int i = -50; i <= 50; ++i) {
        q.push(i);
    }

    cout << "Initial queue: " << std::endl;
    printQueue(q);

    int count = countAfterMax(q);
    cout << "Elements after max: " << count << endl;

    q = filterQueue(q);
    cout << "After filtering: " << endl;
    printQueue(q);

    q = sortQueue(q);
    cout << "After sorting: " << endl;
    printQueue(q);

    // Очистка очереди перед выходом из программы
    clearQueue(q);

    return 0;
}