#include <iostream>

// Базовый шаблонный класс 'base' с двумя типами T1 и T2
template <typename T1, typename T2>
class base
{
public:
    T1 value1; // Переменная-член типа T1
    T2 value2; // Переменная-член типа T2

    // Конструктор для инициализации переменных-членов
    base(T1 v1, T2 v2) : value1(v1), value2(v2) {}

    // Функция для вывода значений переменных-членов
    void printValues() const
    {
        std::cout << "value1: " << value1 << ", value2: " << value2 << std::endl;
    }
};

// Производный шаблонный класс 'child' от 'base', добавляющий два новых типа T3 и T4
template <typename T1, typename T2, typename T3, typename T4>
class child : public base<T1, T2>
{
public:
    T3 value3; // Дополнительная переменная-член типа T3
    T4 value4; // Дополнительная переменная-член типа T4

    // Конструктор для инициализации переменных-членов
    child(T1 v1, T2 v2, T3 v3, T4 v4) : base<T1, T2>(v1, v2), value3(v3), value4(v4) {}

    // Функция для вывода значений всех переменных-членов
    void printValues() const
    {
        base<T1, T2>::printValues(); // Вызов функции из базового класса
        std::cout << "value3: " << value3 << ", value4: " << value4 << std::endl;
    }
};

// Производный шаблонный класс 'child2' от 'child', добавляющий два новых типа T5 и T6
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class child2 : public child<T1, T2, T3, T4>
{
public:
    T5 value5; // Дополнительная переменная-член типа T5
    T6 value6; // Дополнительная переменная-член типа T6

    // Конструктор для инициализации переменных-членов
    child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6) : child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {}

    // Функция для вывода значений всех переменных-членов
    void printValues() const
    {
        child<T1, T2, T3, T4>::printValues(); // Вызов функции из базового класса
        std::cout << "value5: " << value5 << ", value6: " << value6 << std::endl;
    }
};

// Главная функция для тестирования классов
int main()
{
    // Создание объекта класса 'child2' с разными типами данных
    child2<int, double, char, std::string, float, bool> obj(1, 2.5, 'A', "Hello", 3.14f, true);

    // Вывод значений переменных-членов объекта
    obj.printValues();

    return 0;
}