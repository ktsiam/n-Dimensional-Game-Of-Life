#include <vector>

struct Trinary {
        std::vector<int> num;

        Trinary(int dim);
        bool operator++(); // returns false if overflow
        int operator*(int base); // interprets num as of base
};

struct Game {

        int length; // how long each dimensions is
        int dimen;  // how many dimensions there are
        std::vector<bool> board;

        Game(int length_, int dimen_);

        void step();
};
