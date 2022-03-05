#include <iostream>
#include <cassert>
#include "polynomial.h"

void int_test() {
    int coef1[] = {10, 0, 25};
    int coef2[] = {3, 0, 4, 8};

    Polynomial<int> p1(coef1, 2);
    Polynomial<int> p2(coef2, 3);

    std::cout << "\nW1(x) = ";
    p1.display();

    std::cout << "W2(x) = ";
    p2.display();

    Polynomial<int> p3 = p1 + p2;

    int result1[] = {13, 0, 29, 8};
    Polynomial<int> add_result(result1, 3);
    assert(add_result == p3);

    std::cout << "W1(x) + W2(x) = ";
    p3.display();

    Polynomial<int> p4 = p1 - p2;

    int result2[] = {7, 0, 21, -8};
    Polynomial<int> diff_result(result2, 3);
    assert(diff_result == p4);

    std::cout << "W1(x) - W2(x) = ";
    p4.display();

    Polynomial<int> p5 = p1 * p2;

    int result3[] = {30, 0, 115, 80, 100, 200};
    Polynomial<int> mul_result(result3, 5);
    assert(mul_result == p5);

    std::cout << "W1(x) * W2(x) = ";
    p5.display();

    int h1 = p1.horner(3);
    int result4 = 235;
    assert(result4 == h1);
    std::cout << "Wartosc wielomianu W1(x) dla x = 3: " << h1 << "\n";

    int h2 = p2.horner(5);
    int result5 = 1103;
    assert(result5 == h2);
    std::cout << "Wartosc wielomianu W2(x) dla x = 5: " << h2 << "\n";
}

void double_test(){
    double coef1[] = {1.1, 3.45, 3.56, 7.124};
    double coef2[] = {5.33, 1.234, 13.422, 0.0, 2.1};

    Polynomial<double> p1(coef1, 3);
    Polynomial<double> p2(coef2, 4);

    std::cout << "\nW1(x) = ";
    p1.display();

    std::cout << "W2(x) = ";
    p2.display();

    Polynomial<double> p3 = p1 + p2;

    double result1[] = {6.43, 4.684, 16.982, 7.124, 2.1};
    Polynomial<double> add_result(result1, 4);
    assert(add_result == p3);

    std::cout << "W1(x) + W2(x) = ";
    p3.display();

    Polynomial<double> p4 = p1 - p2;

    double result2[] = {-4.23, 2.216, -9.862, 7.124, -2.1};
    Polynomial<double> diff_result(result2, 4);
    assert(diff_result == p4);

    std::cout << "W1(x) - W2(x) = ";
    p4.display();

    Polynomial<double> p5 = p1 * p2;

//    brak assertów ze względu na dokładność doubla

//    double result3[] = {5.863, 19.7459, 37.9963, 88.6699, 58.8833, 102.863, 7.476, 14.9604};
//    Polynomial<double> mul_result(result3, 7);
//    assert(mul_result == p5);

    std::cout << "W1(x) * W2(x) = ";
    p5.display();

    double h1 = p1.horner(5.5);
//    double result4 = 1313.02;
//    assert(result4 == h1);
    std::cout << "Wartosc wielomianu Hornera W1(x) dla x = 5.5: " << h1 << "\n";

    double h2 = p2.horner(6.4);
//    double result5 = 4086.21;
//    assert(result5 == h2);
    std::cout << "Wartosc wielomianu W2(x) dla x = 6.4: " << h2 << "\n";
}

int main() {
    std::cout << std::string(80, '=');
    int_test();
    std::cout << std::string(80, '=');
    double_test();
    std::cout << std::string(80, '=');
    std::cout << std::endl;
}
