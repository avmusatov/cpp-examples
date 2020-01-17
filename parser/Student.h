//
// Created by Anton Musatov on 16.01.2020.
//

#ifndef PARSER_STUDENT_H
#define PARSER_STUDENT_H

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Student{
public:
    Student();
    Student(int,const std::string &, const std::string &);

    void set_mark(int);

    int get_id() const;
    void set_id(const int);
    std::string get_name() const;
    std::string get_group() const;
    std::vector<int> get_marks() const;

    double average_mark() const;
private:
    int id;
    std::vector<int> marks;
    std::string name;
    std::string group;
};

#endif //PARSER_STUDENT_H
