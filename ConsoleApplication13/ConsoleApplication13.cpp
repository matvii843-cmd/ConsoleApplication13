#include <iostream>
#include <ctime>

using namespace std;

class Array {
private:
    long* arr;
    int size;

public:

    // Конструктор за замовчуванням
    Array() {
        size = 0;
        arr = nullptr;
    }

    // Конструктор з розміром
    Array(int size) {
        this->size = size;

        arr = new long[size];

        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    // Конструктор копіювання
    Array(const Array& other) {
        size = other.size;

        arr = new long[size];

        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Деструктор
    ~Array() {
        delete[] arr;
    }

    // Заповнення випадковими числами
    void FillRandom() {
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100;
        }
    }

    // Заповнення з клавіатури
    void FillKeyboard() {
        for (int i = 0; i < size; i++) {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
    }

    // Виведення масиву
    void Print() {
        if (size == 0) {
            cout << "Масив порожній!" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Додавання елемента
    void Add(long value) {
        long* temp = new long[size + 1];

        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        temp[size] = value;

        delete[] arr;
        arr = temp;

        size++;
    }

    // Видалення по індексу
    void RemoveAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Невірний індекс!" << endl;
            return;
        }

        long* temp = new long[size - 1];

        int j = 0;

        for (int i = 0; i < size; i++) {
            if (i != index) {
                temp[j++] = arr[i];
            }
        }

        delete[] arr;
        arr = temp;

        size--;
    }

    // Видалення по значенню
    void RemoveValue(long value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                RemoveAt(i);
                return;
            }
        }

        cout << "Елемент не знайдено!" << endl;
    }

    // Сортування по зростанню
    void SortAscending() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] > arr[j]) {
                    long temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    // Сортування по спаданню
    void SortDescending() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] < arr[j]) {
                    long temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    // Мінімум
    long Min() {
        if (size == 0)
            return 0;

        long min = arr[0];

        for (int i = 1; i < size; i++) {
            if (arr[i] < min)
                min = arr[i];
        }

        return min;
    }

    // Максимум
    long Max() {
        if (size == 0)
            return 0;

        long max = arr[0];

        for (int i = 1; i < size; i++) {
            if (arr[i] > max)
                max = arr[i];
        }

        return max;
    }

    // Середнє арифметичне
    double Average() {
        if (size == 0)
            return 0;

        long sum = 0;

        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }

        return (double)sum / size;
    }

    // Перевантаження []
    long& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Помилка! Невірний індекс." << endl;
            exit(1);
        }

        return arr[index];
    }

    // Перевантаження ()
    void operator()(long value) {
        for (int i = 0; i < size; i++) {
            arr[i] += value;
        }
    }

    int GetSize() {
        return size;
    }
};

int main() {

    srand(time(0));

    Array arr1(10);

    arr1.FillRandom();

    cout << "Початковий масив:" << endl;
    arr1.Print();

    arr1.Add(150);

    cout << "\nПісля додавання 150:" << endl;
    arr1.Print();

    arr1.RemoveAt(2);

    cout << "\nПісля видалення елемента з індексом 2:" << endl;
    arr1.Print();

    arr1.SortAscending();

    cout << "\nСортування по зростанню:" << endl;
    arr1.Print();

    arr1.SortDescending();

    cout << "\nСортування по спаданню:" << endl;
    arr1.Print();

    cout << "\nМінімум: " << arr1.Min() << endl;
    cout << "Максимум: " << arr1.Max() << endl;
    cout << "Середнє: " << arr1.Average() << endl;

    cout << "\nПеревірка конструктора копіювання:" << endl;

    Array arr2 = arr1;

    arr2.Print();

    cout << "\nПеревантаження []:" << endl;
    cout << "Елемент arr1[3] = " << arr1[3] << endl;

    arr1[3] = 999;

    cout << "Після зміни arr1[3] = 999:" << endl;
    arr1.Print();

    cout << "\nПеревантаження ():" << endl;

    arr1(10);

    cout << "Після arr1(10):" << endl;
    arr1.Print();

    return 0;
}