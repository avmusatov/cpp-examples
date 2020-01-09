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
        switch (op)
        {
            case '+': return left->evaluate() + right->evaluate();
            case '-': return left->evaluate() - right->evaluate();
            case '*': return left->evaluate() * right->evaluate();
            case '/': return left->evaluate() / right->evaluate();
            default:
                break;
        }
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

struct ScopedPtr{
     ScopedPtr(const ScopedPtr&) = delete;
     explicit ScopedPtr(Expression *ptr = nullptr):ptr_(ptr){};

     ~ScopedPtr(){
         delete ptr_;
     };
     Expression* get() const{return ptr_;};

     Expression* release(){
         Expression *newPtr = ptr_;
         ptr_ = nullptr;
         return newPtr;
     };

     void reset(Expression *ptr = nullptr){
         delete ptr_;
         ptr_ = ptr;
     };

     ScopedPtr& operator = (const ScopedPtr&) = delete;

     Expression& operator*() const{
        return *ptr_;
     };

     Expression* operator->() const{
         return ptr_;
     };

private:
    Expression *ptr_;
};


