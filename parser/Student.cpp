//
// Created by Anton Musatov on 16.01.2020.
//

#include "Student.h"

Student::Student():id(-1), name(""), group(""){}

Student::Student(int id, const std::string & name,const std::string & group)
: name(name), group(group), id(id) {}

int Student::get_id() { return id;};

std::string Student::get_name() const {
    return name;
}

std::string Student::get_group() const {
    return group;
}

std::vector<int> Student::get_marks() const {return marks;}

void Student::set_mark(int mark){
    marks.push_back(mark);
}