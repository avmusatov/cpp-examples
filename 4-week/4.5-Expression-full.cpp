//
// Created by Anton Musatov on 30.12.2019.
//

#include <iostream>

struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number &number) = 0;
    virtual void visitBinaryOperation(BinaryOperation &operation) = 0;
    virtual ~Visitor() = default;;
};

struct Expression {
    virtual void visit(Visitor &visitor) = 0;
    virtual double evaluate() = 0;
    virtual ~Expression() = default;;
};

struct Number: Expression {

    explicit Number(double value) : value(value) {};
    double get_value()  { return value; };
    double evaluate() override { return value; };
    void visit(Visitor &visitor) override { visitor.visitNumber(*this); };

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

    void visit(Visitor &visitor) override { visitor.visitBinaryOperation(*this); };

    ~BinaryOperation() override {
        delete left;
        delete right;
    }

private:
    Expression  * left;
    Expression  * right;
    char op;
};

struct PrintVisitor : Visitor {

    void visitNumber(Number  &number) override {
        std::cout << number.get_value();
    }

    void visitBinaryOperation(BinaryOperation &bop) override {
        std::cout << '(';
        bop.get_left()->visit(*this);
        std::cout <<' '<< bop.get_op() << ' ';
        bop.get_right()->visit(*this);
        std::cout << ')';
    }
};

//int main() {
//    Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
//    Expression * expr = new BinaryOperation(new Number(3), '+', sube);
//    PrintVisitor visitor;
//    expr->visit(visitor);
//}
