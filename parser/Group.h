//
// Created by Anton Musatov on 16.01.2020.
//

#ifndef PARSER_GROUP_H
#define PARSER_GROUP_H

#include "Student.h"
#include <string>
#include <vector>

class Group{
public:
    Group(std::string name, std::string spec);

    void add_student(const std::string & name);
    void set_head(int id);

    Student * find_student(int id);
    Student get_head() const;
    std::string get_name() const;
    std::string get_spec() const;

private:
    std::string name;
    std::vector<Student> students;
    Student head;
    std::string spec;
};
#endif //PARSER_GROUP_H
