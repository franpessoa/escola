#pragma once
#include <fstream>

struct resultado {
    int const_a_n {0};
    int const_b_n {0};
    double const_a_iden {0.0};
    double const_b_iden {0.0};

    resultado(int a, int b, double ai, double bi) 
        : const_a_n{a}, 
        const_b_n{b}, 
        const_a_iden{ai}, 
        const_b_iden{bi} 
    {};
};



resultado eval(const double alvo, const double alvo_iden, std::ifstream& file);
