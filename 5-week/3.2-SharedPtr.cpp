//
// Created by Anton Musatov on 30.12.2019.
//

#include <iostream>

struct Expression {
    virtual double evaluate() = 0;
    virtual ~Expression() = default;;
};

struct Number: Expression {

    explicit Number(double value) : value(value) {};
    double get_value()  { return value; };
    double evaluate() override { return value; };

    ~Number() override = default;;

private:
    double value;
};

struct BinaryOperation: Expression {

    BinaryOperation(Expression  *left, char op, Expression  *right) :
            left(left), op(op), right(right) {};

    double evaluate() override {
        switch (op) {
            case '+':
                return left->evaluate() + right->evaluate();
            case '-':
                return left->evaluate() - right->evaluate();
            case '*':
                return left->evaluate() * right->evaluate();
            case '/':
                return left->evaluate() / right->evaluate();
            default:
                break;
        }
        return 0;
    }

    Expression * get_left() { return left; };
    Expression * get_right() { return right; };
    char get_op()  { return op; };

    ~BinaryOperation() override {
        delete left;
        delete right;
    }

private:
    Expression  * left;
    Expression  * right;
    char op;
};

struct SharedPtr{
    explicit SharedPtr(Expression *ptr = nullptr):ptr_(ptr), cnt_(new size_t(0))
    {
        if (ptr_ != nullptr) cnt_ = new size_t(1);
    };

    SharedPtr(const SharedPtr& sp):ptr_(sp.ptr_), cnt_(sp.cnt_){
        if (sp.ptr_ != nullptr) ++*cnt_;
    };

    ~SharedPtr(){
        if (cnt_ && ( --* cnt_ == 0)) delete ptr_ , delete cnt_ ;
    };

    Expression * get() const {return ptr_;};
    size_t get_cnt() const {return *cnt_;};

    Expression* release(){
        Expression *newPtr = ptr_;
        ptr_ = nullptr;
        return newPtr;
    };

    void reset(Expression *ptr = nullptr){
        Expression *newPtr = ptr;
        if (cnt_ && ( --* cnt_ == 0)) delete ptr_ , delete cnt_;
        ptr_ = newPtr;
    };

    SharedPtr & operator=(const SharedPtr & sp){
        if (&sp != this){
            if (ptr_ != nullptr) --*cnt_;
            if (sp.ptr_ != nullptr) ++*sp.cnt_;
            ptr_ = sp.ptr_;
        }
        return *this;
    };

    Expression& operator*() const{
        return *ptr_;
    };

    Expression* operator->() const{
        return ptr_;
    };

private:
    Expression * ptr_;
    size_t * cnt_;
};

int main(){
    SharedPtr p1;
    SharedPtr p2(new Number(4));
    SharedPtr p3(new BinaryOperation(new Number(4.5),'+',new Number(5)));
    SharedPtr p4(p2);
    SharedPtr p5;
    p5 = p2;
    p5 = p4;
    p1 = p5;
    p3.reset(nullptr);
    p3 = p5;
    p5.reset(nullptr);
    SharedPtr p6;
    SharedPtr p7;
    p7 = p7;
    p7.reset(nullptr);
    p7.reset(new  Number(10));
    SharedPtr p8(new Number(11));
    p8.reset(nullptr);
}