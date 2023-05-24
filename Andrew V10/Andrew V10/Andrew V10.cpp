#include <iostream>
#include <stack>

using namespace std;

// Вывод элементов стека в том виде, в котором они расположены в стеке
template <typename T>
void printStack(const stack<T>& stk) {
    if (stk.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    stack<T> tempStack(stk); // Создаем временную копию стека

    cout << "Stack elements:" << endl;
    while (!tempStack.empty()) {
        cout << tempStack.top() << endl;
        tempStack.pop();
    }
}

// Определение количества элементов стека, начиная от вершины, до элемента с максимальным значением
template <typename T>
int countElementsAboveMax(const stack<T>& stk) {
    if (stk.empty())
        return 0;

    stack<T> tempStack(stk); // Создаем временную копию стека

    T maxVal = tempStack.top();
    tempStack.pop();
    int count = 0;

    while (!tempStack.empty()) {
        if (tempStack.top() == maxVal)
            break;

        count++;
        tempStack.pop();
    }

    return count;
}

// Преобразование стека, удаляя четные отрицательные и нечетные положительные числа
void transformStack(stack<int>& stk) {
    if (stk.empty())
        return;

    stack<int> tempStack;

    while (!stk.empty()) {
        int num = stk.top();
        stk.pop();

        if ((num % 2 == 0 && num < 0) || (num % 2 != 0 && num > 0))
            continue;

        tempStack.push(num);
    }

    // Переносим элементы обратно в исходный стек
    while (!tempStack.empty()) {
        stk.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    // Создание стека с числами в диапазоне от -50 до 50
    stack<int> numbersStack;
    for (int i = -50; i <= 50; i++) {
        numbersStack.push(i);
    }
    printStack(numbersStack);
    int countAboveMax = countElementsAboveMax(numbersStack);
    cout << "Number of stack elements up to the element with the maximum value: " << countAboveMax << endl;
    transformStack(numbersStack);
    cout << "Stack after conversion:" << endl;
    printStack(numbersStack);
    while (!numbersStack.empty()) {
        numbersStack.pop();
    }
    return 0;
}