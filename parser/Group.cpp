//
// Created by Anton Musatov on 16.01.2020.
//

#include "Group.h"

Group::Group(std::string name, std::string spec)
: name(name), spec(spec), head(Student()) {}

void Group::add_student(const std::string & name) {
    Student student(students.size(), name, this->name);
    students.push_back(student);
}

Student * Group::find_student(int id) {
    if (id >= 0 && id < students.size())
        return &students[id];
    else
        return nullptr;
}

void Group::set_head(int id){
    head = *find_student(id);
}

Student Group::get_head() const {return head;}

std::string Group::get_name() const {return name;}

std::string Group::get_spec() const {return spec;}

