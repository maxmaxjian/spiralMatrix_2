#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

namespace std {
    std::ostream & operator<<(std::ostream & os, const std::vector<int> & vec) {
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(os, " "));
	return os;
    }
}

class solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
	std::vector<std::vector<int>> mat(n, std::vector<int>(n));
	int i = 1;
	auto top = std::make_pair(0,0), bot = std::make_pair(n-1,n-1);
	while (top <= bot) {
	    i = fill(mat, top, bot, i);
	    top.first += 1;
	    top.second += 1;
	    bot.first -= 1;
	    bot.second -= 1;
	}
	return mat;
    }

private:
    int fill(std::vector<std::vector<int>> & mat, const std::pair<size_t,size_t> & topleft, const std::pair<size_t,size_t> & bottomright, int n) {
	if (topleft == bottomright)
	    mat[topleft.first][topleft.second] = n++;
	else {
	    int i = topleft.first, j = topleft.second;
	    for (; j < bottomright.second; j++)
		mat[i][j] = n++;
	    for (; i < bottomright.first; i++)
		mat[i][j] = n++;
	    for (; j > topleft.second; j--)
		mat[i][j] = n++;
	    for (; i > topleft.first; i--)
		mat[i][j] = n++;
	}
	return n;
    }
};

int main() {
    int num = 7;
    
    solution soln;
    auto mat = soln.generateMatrix(num);
    std::copy(mat.begin(), mat.end(), std::ostream_iterator<std::vector<int>>(std::cout, "\n"));
}
