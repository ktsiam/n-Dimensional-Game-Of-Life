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
                        std::cout << "xo"[b[i*length + j]] << ' ';
                std::cout << std::endl;
        }
}

int main() {
        int len = 100;
        Game game(len, 2);
        auto &b = game.board;
        //b[4*len+4] = b[4*len+5] = b[5*len+4] = b[5*len+5] = true; // cube (len=10)
        //b[23] = b[24] = b[32] = b[43] = b[44] = b[35] = true; // behive (len=10)

        b[203] = b [304] = b[402] = b [403] = b[404] = true; // spaceship (len=100)
        
        
        std::string str;
        while(std::getline(std::cin, str)) {
                print2d(game.board, game.length);
                game.step();
        }
}
