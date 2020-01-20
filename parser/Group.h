//
// Created by Anton Musatov on 16.01.2020.
//

#ifndef PARSER_GROUP_H
#define PARSER_GROUP_H

#include "Student.h"
#include <string>
#include <vector>
#include <iostream>

class Group{
public:
    Group(const std::string &, const std::string &);

    void add_student(const std::string &);
    void expel_student(const std::string &);
    void expel_student(const int);
    void set_head(int);
    void set_spec(const std::string &);

    Student * find_student(int );
    Student * find_student(const std::string &);

    Student get_head() const;
    std::string get_name() const;
    std::string get_spec() const;
    size_t get_size() const;
    void print_group() const;

    double average_group() const;

private:
    std::string name;
    std::vector<Student> students;
    Student head;
    std::string spec;
    size_t size;
};
#endif //PARSER_GROUP_H
