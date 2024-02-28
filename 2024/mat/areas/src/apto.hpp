#pragma once
#include <string>

class apto
{
public:
    // Defined classes
    enum class construtora: char {
        A = 'A',
        B = 'B'
    };

    // Members
    double area = {0};
    construtora cst = {construtora::A};
    

    apto(double area, construtora c) : area{area}, cst{c} {};
    apto(std::string&);

    double calc_diff(double tgt);
};
