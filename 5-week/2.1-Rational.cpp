//
// Created by Anton Musatov on 29.12.2019.
//
#include <iostream>
#include <algorithm>
#include <string>

class Rational {
public:
    Rational():numerator_(0), denominator_(1)
    {};

    Rational(int num = 0, int den = 1) :
    numerator_(num), denominator_(den) {
        reduce_fraction();
    };

    Rational(const Rational & rational):
            numerator_(rational.numerator_), denominator_(rational.denominator_) {
        reduce_fraction();
    };


    void add(Rational rational) {

        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
        reduce_fraction();
    }

    void sub(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
        reduce_fraction();
    }

    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
        reduce_fraction();
    }

    void div(Rational rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
        reduce_fraction();
    }

    void neg() {
        numerator_ = -numerator_;
    }

    int get_numerator(){
        return numerator_;
    }

    int get_denominator(){
        return denominator_;
    }

    void print_rational(){
        size_t lenNum = std::to_string(numerator_).length(),
                lenDen = std::to_string(denominator_).length();

        int integralPart = numerator_ / denominator_,
                newNumerator = numerator_ % denominator_;

        if (numerator_ > denominator_ and newNumerator != 0){

            std::cout << std::string(std::to_string(integralPart).length(),' ') << newNumerator << std::endl;
            std::cout << integralPart << std::string(lenNum, '_') << std::endl;
            std::cout << std::string(std::to_string(integralPart).length(), ' ');
            std::cout << denominator_ << std::endl;

        } else if (numerator_ < denominator_){
            std::cout << numerator_ << std::endl;
            std::cout << std::string(lenNum, '_') << std::endl;
            std::cout << denominator_ << std::endl;
        } else {
            std::cout << integralPart << std::endl;
        }
    }

    double to_double() const {
        return numerator_ / (double) denominator_;
    }

    // Operators += -= *= /=
    Rational & operator +=( Rational r){
        add(r);
        return *this;
    }

    Rational & operator -= (Rational r){
        sub(r);
        return *this;
    }

    Rational & operator *= (Rational r){
        mul(r);
        return *this;
    }

    Rational & operator /= (Rational r){
        div(r);
        return *this;
    }

    Rational operator -() const {
        Rational tmp(numerator_, denominator_);
        tmp.neg();
        return tmp;
    }

private:
    int numerator_;
    int denominator_;

    void reduce_fraction(){
        int gcd = std::__gcd(abs(numerator_), abs(denominator_));
        if (gcd != 0){
            numerator_ /= gcd;
            denominator_ /= gcd;
        }
    }

};

// Binary + - * /
Rational operator +(Rational r1, Rational r2){
    return r1 += r2;
}

Rational operator -(Rational r1, Rational r2){
    return r1 -= r2;
}

Rational operator *(Rational r1, Rational r2){
    return r1 *= r2;
}

Rational operator /(Rational r1, Rational r2){
    return r1 /= r2;
}

//Operators of comparison == != < > <= >=

bool operator==(Rational r1, Rational r2){
    return r1.get_numerator() == r2.get_numerator() && r1.get_denominator() == r2.get_denominator();
}

bool operator!= (Rational r1, Rational r2){
    return !(r1 == r2);
}

bool operator< (Rational r1, Rational r2){
    Rational tmp = r1 - r2;
    return tmp.get_numerator() < 0;
}

bool operator> (Rational r1, Rational r2){
    return r2 < r1;
}

bool operator<= (Rational r1, Rational r2){
    return !(r1 > r2);
}

bool operator>= (Rational r1, Rational r2){
    return !(r1 < r2);
}

//int main(){
//    Rational r(2);
//    Rational r1(46432,2452);
//    Rational r2(1,2);
//    Rational r3(1,2);
//    Rational r4 = 10 + r3;
//    //r1.reduce_fraction();
//    //std::cout << r1.get_numerator() << ' ' << r1.get_denominator();
//    r4.print_rational();
//    bool check = r2 < r1;
//    std::cout << check;
//}