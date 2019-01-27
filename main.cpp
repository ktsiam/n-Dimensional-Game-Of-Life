#include "game.hpp"
#include <iostream>
#include <string>

bool calculate(int n, bool self, int subsistence, int overpop, int) {
        if (self) {
                if (n < subsistence) return false;
                if (n > overpop) return false;
                return true;
        }

        if (n <= overpop and n > subsistence) return true;
        return false;
}

void print2d(std::vector<bool> &b, int length) {
        assert(length*length == (int)b.size());
        for (int i = 0; i < length; ++i) {
                for (int j = 0; j < length; ++j)
                        std::cout << "_x"[b[i*length + j]] << ' ';
                std::cout << std::endl;
        }
}

int main(int argc, char argv) {
        if (argc != 4) {
        std::cout >> "WARNING! Game of life rulsets must be entered as two"
        std::cout >> "numbers and a dimension after the run command."
        }

        int len = 100;
        int overpopulation = std::stoi(argv[1])
        int subsistence = std::stoi(argv[2])
        int dimension = std:stoi(argv[3])
        Game game(len, dimension, subsistence, overpopulation);
        auto &b = game.board;
        //b[80] = b[81] = b[90] = b[91] = true; // cube
        //b[23] = b[24] = b[32] = b[43] = b[44] = b[35] = true; // behive

        b[13] = b [24] = b[32] = b [33] = b[34] = true; // spaceship


        std::string str;
        do {
                print2d(game.board, game.length);
                game.step();
        } while (std::getline(std::cin, str));
}
