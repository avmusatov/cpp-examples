//
// Created by Anton Musatov on 16.01.2020.
//

#ifndef PARSER_DEAN_H
#define PARSER_DEAN_H

#include "Group.h"
#include <string>
#include <vector>
#include <istream>
#include <fstream>
#include <iostream>
#include <sstream>

class Dean{
public:
    Dean(){};
    Dean(Group);

    void add_group(const Group & );
    void set_marks(std::string, int, const std::vector<int>&);

    std::vector<Group> get_groups() const;
    Group * find_group(std::string);

private:
    std::vector<Group> groups;
};
#endif //PARSER_DEAN_H
