#include "game.hpp"
#include <iostream>
#include <string>

bool calculate(int n, bool self, int) {
        if (self) {
                if (n < 2) return false;
                if (n > 3) return false;
                return true;
        }

        if (n == 3) return true;
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

int main() {
        int len = 10;
        Game game(len, 2);
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
