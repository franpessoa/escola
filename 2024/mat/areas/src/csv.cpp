#include "csv.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>

std::vector<apto> read_aptos(std::ifstream& file) {
    std::vector<apto> result {};
    std::string line {};

    // get and ignore first line
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (!(file.bad() || file.fail())) {
            result.push_back(apto(line));
        } else {
            throw std::runtime_error("arquivo inválido");
        }
    };

    return std::move(result);
}