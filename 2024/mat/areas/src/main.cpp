#include "apto.hpp"
#include "csv.hpp"
#include "eval.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <istream>
#include <algorithm>
#include <fmt/core.h>


static constexpr double ALVO = 53;
static constexpr double ALVO_MARGEM = ALVO * 0.95;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Providencia pelo menos um arquivo" << std::endl;
        return -1;
    }

    fmt::println(" -> Teste 1");
    fmt::println("alvo: {:.2f}m² alvo iden. : {:.2f}m²", ALVO_MARGEM, ALVO_MARGEM);
    std::ifstream file_1 {std::string(argv[1]).c_str()};
    resultado e1 = eval(ALVO_MARGEM, ALVO_MARGEM, file_1);
    fmt::println("resultados:");
    fmt::println("construtora A: {} apto. R${:.2f} iden.", e1.const_a_n, e1.const_a_iden);
    fmt::println("construtora B: {} apto. R${:.2f} iden.", e1.const_b_n, e1.const_b_iden);


    fmt::println(" -> Teste 2");
    fmt::println("alvo: {:.2f}m² alvo iden. : {:.2f}m²", ALVO_MARGEM, ALVO);
    std::ifstream file_2 {std::string(argv[1]).c_str()};
    resultado e2 = eval(ALVO_MARGEM, ALVO, file_2);
    fmt::println("resultados:");
    fmt::println("construtora A: {} apto. R${:.2f} iden.", e2.const_a_n, e2.const_a_iden);
    fmt::println("construtora B: {} apto. R${:.2f} iden.", e2.const_b_n, e2.const_b_iden);

}
