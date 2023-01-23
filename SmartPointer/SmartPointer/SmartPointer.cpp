#include <iostream>
using namespace std;


void compute() {
    unique_ptr<int[]> data = make_unique<int[]>(1024);
    /* какой-то код...*/
}

int main() {

    unique_ptr<int> u1(new int);
    unique_ptr<int[]> u2(new int[50]);
    unique_ptr<string> u3 = make_unique<string>();

    compute();
    // после завершения функции data выходит из области действия 
    // и вызывается деструктор указателя, уничтожающий data

    shared_ptr<int> s1(new int);
    shared_ptr<string> s2 = make_shared<string>("mama-mia");
    shared_ptr<string> s3 = s2; // cуть shared_ptr в том, что может существовать много указателей на один объект и в классе есть изх счетчик


    // До C++17 не было простого способа соорудить std::shared_ptr, хранящий массив. 
    // До C++17 этот умный указатель по умолчанию всегда вызывает delete (а не delete[]) на своем ресурсе: 
    // вы можете создать обходной путь, используя кастомное удаление

    shared_ptr<int[]> s4(new int[16], [](int* i) {
        delete[] i; // Кастомное удаление лямда функцией (не работает при использовании make_shared.)
        });

    // Избегайте круговых ссылок типо и взаимозависимостей при сипользовании shared_ptr;

    // Вы можете создать weak_ptr только из shared_ptr или другого weak_ptr. Например:

    weak_ptr<string>  w1(s2);
    weak_ptr<string> w2(w1);

    // В приведенном выше примере p_weak1 и p_weak2 указывают на одни и те же динамические данные, принадлежащие p_shared, но счетчик ссылок не растет.

    return 0;
}
