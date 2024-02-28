#include "./apto.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <array>
#include <string_view>

apto::apto(std::string& csv_line) {
    std::string field{};
    std::vector<std::string> field_vec;
    std::istringstream stream {csv_line};
    const std::string_view separator { "," };

    while (std::getline(stream, field, ',')) {
        field_vec.push_back(field);
    }

    cst = field_vec[1] == "A" 
        ? apto::construtora::A 
        : apto::construtora::B;
    
    area = std::stod(field_vec[4]) 
        + std::stod(field_vec[5]) 
        + std::stod(field_vec[6]) 
        + std::stod(field_vec[7]);
};

double apto::calc_diff(double tgt) {
    return this->area - tgt;
}