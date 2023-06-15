#include <iostream>
#include <stack>
using namespace std;
// Функция для печати стека
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << '\t' << st.top();
        st.pop();
    }
    cout << '\n';
}

// Функция для поиска минимального и максимального элемента и их обмена
stack<int> swapMinMax(stack<int> st) {
    stack<int> temp;
    int min_val = numeric_limits<int>::max();
    int max_val = numeric_limits<int>::min();
    while (!st.empty()) {
        int val = st.top();
        min_val = min(min_val, val);
        max_val = max(max_val, abs(val));
        st.pop();
        temp.push(val);
    }

    // Заменить минимальный элемент на max_val и максимальный элемент на min_val
    st = temp;
    while (!temp.empty()) {
        temp.pop();
    }
    while (!st.empty()) {
        int val = st.top();
        if (val == min_val) {
            temp.push(max_val);
        }
        else if (abs(val) == max_val) {
            temp.push(min_val);
        }
        else {
            temp.push(val);
        }
        st.pop();
    }
    return temp;
}

// Функция для удаления всех неотрицательных чисел
stack<int> removeNonNegatives(stack<int> st) {
    stack<int> temp;
    while (!st.empty()) {
        int val = st.top();
        if (val < 0) {
            temp.push(val);
        }
        st.pop();
    }
    return temp;
}

void clearStack(stack<int>& st) {
    while (!st.empty()) {
        st.pop();
    }
}

int main() {
    stack<int> st;

    // Заполнение стека числами от -50 до 50
    for (int i = -50; i <= 50; ++i) {
        st.push(i);
    }

    cout << "Initial stack: " << endl;
    printStack(st);

    st = swapMinMax(st);

    cout << "After swapping min and max: " << endl;
    printStack(st);

    st = removeNonNegatives(st);

    cout << "After removing non-negatives: " << endl;
    printStack(st);
    clearStack(st);
    return 0;
}