#include <iostream>
#include <string>

using namespace std;

// Структура для комплексных чисел
struct ComplexNumber {
    double real;
    double imag;

    ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {}

    ComplexNumber operator+(const ComplexNumber& other) {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    ComplexNumber operator-(const ComplexNumber& other) {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    ComplexNumber operator*(const ComplexNumber& other) {
        return ComplexNumber(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }

    ComplexNumber operator/(const ComplexNumber& other) {
        double denom = other.real * other.real + other.imag * other.imag;
        return ComplexNumber((real * other.real + imag * other.imag) / denom,
            (imag * other.real - real * other.imag) / denom);
    }

    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

// Структура для автомобиля
struct Car {
    double length;          // Длина
    double clearance;       // Клиренс
    double engineVolume;    // Объем двигателя
    double power;           // Мощность
    double wheelDiameter;   // Диаметр колес
    string color;           // Цвет
    string transmissionType; // Тип коробки передач

    Car(double len = 0, double cle = 0, double vol = 0, double pow = 0, double dia = 0, string col = "", string trans = "")
        : length(len), clearance(cle), engineVolume(vol), power(pow), wheelDiameter(dia), color(col), transmissionType(trans) {
    }

    void setValues(double len, double cle, double vol, double pow, double dia, string col, string trans) {
        length = len;
        clearance = cle;
        engineVolume = vol;
        power = pow;
        wheelDiameter = dia;
        color = col;
        transmissionType = trans;
    }

    void displayValues() {
        cout << "Длина: " << length << " м" << endl;
        cout << "Клиренс: " << clearance << " см" << endl;
        cout << "Объем двигателя: " << engineVolume << " л" << endl;
        cout << "Мощность двигателя: " << power << " л.с." << endl;
        cout << "Диаметр колес: " << wheelDiameter << " дюйм" << endl;
        cout << "Цвет: " << color << endl;
        cout << "Тип коробки передач: " << transmissionType << endl;
    }

    bool isPowerful(double threshold) {
        return power > threshold;
    }
};

int main() {
    // Работа с комплексными числами
    setlocale(LC_ALL, "ru");
    ComplexNumber z1(2, 3);
    ComplexNumber z2(4, -5);

    cout << "Значения комплексных чисел:" << endl;
    cout << "z1: ";
    z1.display();
    cout << "z2: ";
    z2.display();

    cout << "\nСумма: ";
    (z1 + z2).display();

    cout << "Разность: ";
    (z1 - z2).display();

    cout << "Умножение: ";
    (z1 * z2).display();

    cout << "Деление: ";
    (z1 / z2).display();

    cout << "\n\n--- Данные автомобиля ---\n" << endl;

    // Работа с автомобилем
    Car car;
    car.setValues(4.5, 15, 2.0, 150, 17, "Красный", "Автомат");

    cout << "Данные автомобиля:" << endl;
    car.displayValues();

    double powerThreshold = 130;
    cout << "\nАвтомобиль мощнее " << powerThreshold << " л.с.: "
        << (car.isPowerful(powerThreshold) ? "Да" : "Нет") << endl;

    return 0;
}
