#include <iostream>
using namespace std;

// Структура для узла списка
template <typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;
};

// Класс двунаправленного списка
template <typename T>
class List2 {
private:
    Node<T>* head; // Голова списка
    Node<T>* tail; // Хвост списка
public:
    List2() {
        head = nullptr;
        tail = nullptr;
    }
    // Добавление элемента в конец списка
    void append(const T& value) {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Удаление всех элементов на четных позициях
    void removeEvenPositions() {
        Node<T>* currentNode = head;
        int position = 1;

        while (currentNode != nullptr) {
            if (position % 2 == 0) {
                Node<T>* prevNode = currentNode->prev;
                Node<T>* nextNode = currentNode->next;

                if (prevNode != nullptr)
                    prevNode->next = nextNode;
                else
                    head = nextNode;

                if (nextNode != nullptr)
                    nextNode->prev = prevNode;
                else
                    tail = prevNode;

                delete currentNode;
                currentNode = nextNode;
            }
            else {
                currentNode = currentNode->next;
            }

            position++;
        }
    }

    // Вставка списка из заданной позиции
    void insertFromPosition(const List2<T>& otherList, int position) {
        Node<T>* currentNode = head;
        int currentPosition = 1;

        while (currentNode != nullptr && currentPosition != position) {
            currentNode = currentNode->next;
            currentPosition++;
        }

        if (currentNode == nullptr) {
            currentNode = tail;
        }

        for (Node<T>* otherNode = otherList.head; otherNode != nullptr; otherNode = otherNode->next) {
            Node<T>* newNode = new Node<T>;
            newNode->data = otherNode->data;

            newNode->prev = currentNode;
            newNode->next = currentNode->next;

            if (currentNode->next != nullptr)
                currentNode->next->prev = newNode;
            else
                tail = newNode;

            currentNode->next = newNode;
            currentNode = newNode;
        }
    }

    // Суммирование внутренних элементов (конкатенация в случае строк)
    T sumInternalElements() const {
        T sum;

        if (head == nullptr || head->next == nullptr) {
            sum = T();
        }
        else {
            sum = head->next->data;

            for (Node<T>* currentNode = head->next->next; currentNode != tail; currentNode = currentNode->next) {
                cout << currentNode->data << "adsadf" << endl;
                sum += currentNode->data;
            }
        }

        return sum;
    }

    // Сортировка элементов методом пузырька
    void bubbleSort() {
        if (head == nullptr || head->next == nullptr)
            return; 

        bool swapped;
        Node<T>* current;
        Node<T>* last = nullptr;

        do {
            swapped = false;
            current = head;

            while (current->next != last) {
                if (current->data > current->next->data) {
                    swap(current->data, current->next->data);
                    swapped = true;
                }

                current = current->next;
            }

            last = current;
        } while (swapped);
    }

    // Вывод списка на экран
    void display() const {
        Node<T>* currentNode = head;

        while (currentNode != nullptr) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }

        cout << endl;
    }
};
int main() {
    List2<int> myList;
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);
    myList.append(5);
    int sum = myList.sumInternalElements();
    cout << "Sum: " << sum << endl;
    myList.removeEvenPositions();
    myList.display(); 
    List2<int> otherList;
    otherList.append(10);
    otherList.append(20);
    otherList.append(30);
    myList.insertFromPosition(otherList, 2);
    myList.display();
    List2<string> stringList;
    stringList.append("Hello");
    stringList.append(", ");
    stringList.append("world!");
    List2<int> unsortedList;
    unsortedList.append(5);
    unsortedList.append(2);
    unsortedList.append(8);
    unsortedList.append(1);
    unsortedList.bubbleSort();
    unsortedList.display();
    return 0;
}