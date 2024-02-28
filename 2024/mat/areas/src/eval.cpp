#include "eval.hpp"
#include "apto.hpp"
#include "csv.hpp"
#include <vector>
#include <algorithm>

resultado eval(const double alvo, const double alvo_iden, std::ifstream& file) {
    auto aptos = read_aptos(file);
    std::vector<apto> construtora_a{};
    std::vector<apto> construtora_b{};

    std::copy_if(
        aptos.begin(), 
        aptos.end(), 
        std::back_inserter(construtora_a), // insere no final do vetor 
        [alvo](apto ap){ 
            return (ap.calc_diff(alvo) < 0) && (ap.cst == apto::construtora::A); 
        }
    );

    std::copy_if(
        aptos.begin(), 
        aptos.end(), 
        std::back_inserter(construtora_b), // insere no final do vetor 
        [alvo](apto ap){
            return (ap.calc_diff(alvo) < 0) && (ap.cst == apto::construtora::B);
        }
    );

    double iden_a {0};
    double iden_b {0};

    for (apto& ap_c_a: construtora_a) {
        iden_a += -(ap_c_a.calc_diff(alvo_iden)) * 6208;
    }

    for (apto& ap_c_b: construtora_b) {
        iden_b += -(ap_c_b.calc_diff(alvo_iden)) * 6208;
    }

    return resultado(construtora_a.size(), construtora_b.size(), iden_a, iden_b);
}