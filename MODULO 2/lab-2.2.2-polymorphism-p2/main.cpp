#include <iostream>
#include <string>
#include <cmath>

class Piece {
protected:
    char start_col = 'b';
    int start_row = 1;

public:
    virtual ~Piece() {}

    virtual bool check_move(char dest_col, int dest_row) = 0;
};

class Man : public Piece {
public:
    bool check_move(char dest_col, int dest_row) override
    {
        int row_diff = dest_row - start_row;
        int col_diff = dest_col - start_col;

        bool forward_one = (row_diff == 1);
        bool diagonal_one = (std::abs(col_diff) == 1);

        return forward_one && diagonal_one;
    }
};

class King : public Piece {
public:
    bool check_move(char dest_col, int dest_row) override 
    {
        int row_diff_abs = std::abs(dest_row - start_row);
        int col_diff_abs = std::abs(dest_col - start_col);

        bool is_diagonal = (row_diff_abs == col_diff_abs);
        bool has_moved = (row_diff_abs > 0);

        return is_diagonal && has_moved;
    }
};

int main() 
{
	std::cout << std::boolalpha;

	std::unique_ptr<Piece> piece;

	piece = std::make_unique<Man>();
	std::cout << piece->check_move('c', 2) << std::endl;

	piece = std::make_unique<King>();
	std::cout << piece->check_move('d', 3) << std::endl;

	piece = std::make_unique<Man>();
	std::cout << piece->check_move('d', 3) << std::endl;

    return EXIT_SUCCESS;
}