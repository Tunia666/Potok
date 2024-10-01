// Potok.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>

using namespace std;

void func() { //фуе-я нового потока
    cout << "\tФункция запущена";
    cout << "\t Thread ID:" << this_thread::get_id() << endl;

    for (int i = 0; i < 10; i++) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "\t func итерация:" << i << endl;
    }
    cout << "\tФункция завершина";
}
/*
int main()
{   //основной поток
    setlocale(LC_ALL, "Ru");
    cout << "Main запущен\n";
    cout << "\t Thread ID:" << this_thread::get_id() << endl;
    thread t(func);
    t.detach();
    for (int i = 0; i < 5; i++) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "\tmain итерация:" << i << endl;
    }
    //t.join();

    cout << "\tmain завершен";
}

*/
/*
void Subtract(int a, int b) {
    int c = a - b;
    cout << "Результат вичитания: " << c << endl;
}
*/

int Subtract(int a, int b) {
    return a - b;

}

/*
int main() { //Передача параметров в функцию, выполняемую в другом потоке
    setlocale(LC_ALL, "Ru");
    thread t = thread(Subtract, 50,10);
    t.join();
}
*/

int main() { //Получение результата выполнения
    setlocale(LC_ALL, "Ru");
    int result = 0;
    thread t;
    t = thread([&result]() {
        result = Subtract(10, 50);
        }
    );
        
    t.join();
    cout << "Результат вичитания: " << result << endl;
}
