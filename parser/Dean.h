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
#include <cstdlib>

class Dean{
public:
    Dean(){};
    Dean(Group);
    Dean(const std::string &);

    void add_group(const Group & );
    void set_marks(const std::string &, int, const std::vector<int>&);
    void set_random_marks(const std::string &, int);

    std::vector<Group> get_groups() const;
    Group * find_group(const std::string &);

    static std::vector<std::string> split(const std::string &, char);
    void fill(const std::string &);
private:
    std::vector<Group> groups;
};
#endif //PARSER_DEAN_H
