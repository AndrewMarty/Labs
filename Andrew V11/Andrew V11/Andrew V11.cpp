#include <iostream>
#include <queue>

using namespace std;

// Вывод элементов очереди в прямом порядке (от головы до хвоста)
template <typename T>
void printQueue(const queue<T>& que) {
    if (que.empty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    queue<T> tempQueue(que); // Создаем временную копию очереди

    cout << "Queue elements:" << endl;
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << endl;
        tempQueue.pop();
    }
}

// Определение количества элементов очереди до элемента с максимальным значением
template <typename T>
int countElementsAboveMax(const queue<T>& que) {
    if (que.empty())
        return 0;

    queue<T> tempQueue(que); // Создаем временную копию очереди

    T maxVal = tempQueue.front();
    tempQueue.pop();
    int count = 0;

    while (!tempQueue.empty()) {
        if (tempQueue.front() == maxVal)
            break;

        count++;
        tempQueue.pop();
    }

    return count;
}

// Преобразование очереди, удаляя четные отрицательные и нечетные положительные числа
void transformQueue(queue<int>& que) {
    if (que.empty())
        return;

    queue<int> tempQueue;

    while (!que.empty()) {
        int num = que.front();
        que.pop();

        if ((num % 2 == 0 && num < 0) || (num % 2 != 0 && num > 0))
            continue;

        tempQueue.push(num);
    }

    // Переносим элементы обратно в исходную очередь
    while (!tempQueue.empty()) {
        que.push(tempQueue.front());
        tempQueue.pop();
    }
}

int main() {
    // Создание очереди с числами в диапазоне от -50 до 50
    queue<int> numbersQueue;
    for (int i = -50; i <= 50; i++) {
        numbersQueue.push(i);
    }
    // Вывод элементов очереди
    printQueue(numbersQueue);
    // Определение количества элементов очереди до элемента с максимальным значением
    int countAboveMax = countElementsAboveMax(numbersQueue);
    cout << "Number of elements of the queue before the element with the maximum value: " << countAboveMax << endl;
    // Преобразование очереди, удаляя четные отрицательные и нечетные положительные числа
    transformQueue(numbersQueue);
    // Вывод элементов очереди после преобразования
    cout << "Queue after conversion:" << endl;
    printQueue(numbersQueue);
    // Удаление очереди
    while (!numbersQueue.empty()) {
        numbersQueue.pop();
    }
    return 0;
}