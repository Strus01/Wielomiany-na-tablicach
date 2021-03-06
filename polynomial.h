#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <cstdlib>
#include <algorithm>

template<typename T>
class Polynomial {
    T *coefficients;
    int n;
public:

    Polynomial();

    // podaj stopień wielomianu
    explicit Polynomial(int _n);

    // indeks tablicy odpowiada potędze x dla danego współczynnika, _n to stopień wielomianu
    Polynomial(T *_coefficients, int _n);

    Polynomial(const Polynomial &other);

    ~Polynomial();

    Polynomial &operator=(const Polynomial &other);

    Polynomial operator+(const Polynomial &other);

    Polynomial operator-(const Polynomial &other);

    Polynomial operator*(const Polynomial &other);

    bool operator==(const Polynomial &other) const;

    bool operator!=(const Polynomial &other) const;

    bool isZero();

    T horner(T x);

    void display();

};

template<typename T>
Polynomial<T>::Polynomial() {
    n = 1;
    coefficients = new T[n];
}

template<typename T>
Polynomial<T>::Polynomial(int _n) : n(_n) {
    coefficients = new T[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        coefficients[i] = T();
    }
}

template<typename T>
Polynomial<T>::Polynomial(T *_coefficients, int _n) : n(_n) {
    coefficients = new T[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        coefficients[i] = _coefficients[i];
    }
}

template<typename T>
Polynomial<T>::Polynomial(const Polynomial &other) : n(other.n){
    if (this != &other) {
        coefficients = new T[n + 1];
        std::copy(other.coefficients, other.coefficients + n + 1, coefficients);
    }
}

template<typename T>
Polynomial<T>::~Polynomial() {
    n = 0;
    delete[] coefficients;
}

template<typename T>
Polynomial<T> &Polynomial<T>::operator=(const Polynomial &other) {
    if (this != &other) {
        delete[] coefficients;
        n = other.n;
        coefficients = new T[other.n + 1];
        for (int i = 0; i < other.n + 1; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }
    return *this;
}

template<typename T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial &other) {
    int n1 = this->n;
    int n2 = other.n;
    int higher;
    n1 > n2 ? higher = n1 : higher = n2;
    T coef[higher + 1];
    Polynomial<T> result(coef, higher);

    if (n1 == n2) {
        for (int i = 0; i < other.n + 1; ++i) {
            result.coefficients[i] = this->coefficients[i] + other.coefficients[i];
        }
    } else if (n1 != n2) {
        if (n1 > n2) {
            for (int i = n2; i < n1 + 1; ++i) {
                result.coefficients[i] = this->coefficients[i];
            }
            for (int i = 0; i < n2 + 1; ++i) {
                result.coefficients[i] = this->coefficients[i] + other.coefficients[i];
            }
        } else if (n1 < n2) {
            for (int i = n1; i < n2 + 1; ++i) {
                result.coefficients[i] = other.coefficients[i];
            }
            for (int i = 0; i < n1 + 1; ++i) {
                result.coefficients[i] = this->coefficients[i] + other.coefficients[i];
            }
        }
    }
    return result;
}

template<typename T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial &other) {
    int n1 = this->n;
    int n2 = other.n;
    int higher;
    n1 > n2 ? higher = n1 : higher = n2;
    T coef[higher + 1];
    Polynomial<T> result(coef, higher);

    if (n1 == n2) {
        for (int i = 0; i < other.n + 1; ++i) {
            result.coefficients[i] = this->coefficients[i] - other.coefficients[i];
        }
    } else if (n1 != n2) {
        if (n1 > n2) {
            for (int i = n2; i < n1 + 1; ++i) {
                result.coefficients[i] = this->coefficients[i];
            }
            for (int i = 0; i < n2 + 1; ++i) {
                result.coefficients[i] = this->coefficients[i] - other.coefficients[i];
            }
        } else if (n1 < n2) {
            for (int i = n1; i < n2 + 1; ++i) {
                result.coefficients[i] = -other.coefficients[i];
            }
            for (int i = 0; i < n1 + 1; ++i) {
                result.coefficients[i] = this->coefficients[i] - other.coefficients[i];
            }
        }
    }
    return result;
}

template<typename T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial &other) {
    int n1 = this->n;
    int n2 = other.n;
    int result_n = n1 + n2;

    Polynomial<T> result(result_n);

    for (int i = 0; i < n1 + 1; ++i) {
        for (int j = 0; j < n2 + 1; ++j) {
            result.coefficients[i + j] += this->coefficients[i] * other.coefficients[j];
        }
    }
    return result;
}

template<typename T>
bool Polynomial<T>::operator==(const Polynomial &other) const {
    auto p = *this;
    Polynomial<T> polynomial = p - other;

    if (polynomial.isZero()) {
        return true;
    }

    return false;
}

template<typename T>
bool Polynomial<T>::operator!=(const Polynomial &other) const {
    auto p = *this;
    Polynomial<T> polynomial = p - other;

    if (!polynomial.isZero()) {
        return true;
    }

    return false;
}

template<typename T>
bool Polynomial<T>::isZero() {
    for (int i = 0; i < n + 1; ++i) {
        if (this -> coefficients[i] != 0) {
            return false;
        }
    }
    return true;
}

template<typename T>
T Polynomial<T>::horner(T x) {
    T result = 0;
    for (int i = n; i >= 0; --i) {
        result = result * x + coefficients[i];
    }
    return result;
}

template<typename T>
void Polynomial<T>::display() {

    for (int i = n; i >= 0; --i) {
        if (coefficients[i] != 0) {
            if (i != 0 && i != 1 && i != n) {
                if (coefficients[i] > 0) {
                    std::cout << " + ";
                } else if (coefficients[i] < 0) {
                    std::cout << " - ";
                }
                std::cout << abs(coefficients[i]) << "x^" << i;
            } else if (i == 0) {
                if (coefficients[i] > 0) {
                    std::cout << " + ";
                } else if (coefficients[i] < 0) {
                    std::cout << " - ";
                }
                std::cout << abs(coefficients[i]);
            } else if (i == 1) {
                if (coefficients[i] > 0) {
                    std::cout << " + ";
                } else if (coefficients[i] < 0) {
                    std::cout << " - ";
                }
                std::cout << abs(coefficients[i]) << "x";
            } else if (i == n) {
                std::cout << coefficients[i] << "x^" << i;
            }
        }

    }

    std::cout << std::endl;
}


#endif //POLYNOMIAL_H
