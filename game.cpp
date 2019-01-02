#include "game.hpp"

extern bool calculate(int neighbours, bool self, int dimen);

int pow(int base, int exp) {
        if (!exp) return 1;
        return base * pow(base, exp-1);
}

Trinary::Trinary(int dim) {
        for (int i = 0; i < dim; ++i)
                num.push_back(-1);
}

bool Trinary::operator++() {
        for (int &d : num) {
                if (d == 1)
                        d = -1;
                else {
                        d ++;
                        return true; // increment
                }
        }
        return false; // overflow
}

int Trinary::operator*(int base) {
        int result = 0;
        int factor = 1;
        for (int d : num) {
                result += d * factor;
                factor *= base;
        }
        return result;
}

Game::Game(int length_, int dimen_) :
        length(length_), dimen(dimen_), board(pow(length, dimen)) {}

void Game::step() {
        const std::vector<bool> copy = board;
        int size = board.size();
        
        Trinary counter(dimen);
        for (int i = 0; i < size; ++i) {

                int neighbours = 0;
                
                do {
                        int idx = i + counter*length;
                        idx = (idx + size) % size;

                        // ignoring self
                        if (idx != i and copy[idx]) neighbours++;
                        
                } while (++ counter); // until overflow
                
                board[i] = calculate(neighbours, copy[i], dimen);
        }
}
