#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>

using namespace std;
typedef unsigned int uint;


class Solution {
public:
    void solve(vector<vector<char>>& board)
	{
		board_ = board;
		for (int i = 0; i < board_.size(); ++i)
		{
			bfs(i, 0);
			bfs(i, board_.size()-1);
		}

		for (int j = 0; j < board_.size(); ++j)
		{
			bfs(0, j);
			bfs(board_.size()-1, j);
		}

		for (uint i = 0; i < board_.size(); ++i) {
			for (uint j = 0; j < board_.size(); ++j) {
				if (board_[i][j] == 'O') {
					board_[i][j] = 'X';
				} else if (board_[i][j] == '#') {
					board_[i][j] = 'O';
				}
			}
		}
	
		board.swap(board_);
	}

	bool isValid(int i, int j) 
	{
		if (i >= board_.size() || j >= board_.size()
			|| i < 0 || j < 0) 
		{
			return false;
		}

		return true;
	}

	void bfs(int i, int j)
	{
		if (i >= board_.size() || j >= board_.size()
			|| i < 0 || j < 0) 
		{
			return;
		}

		if (board_[i][j] != 'O') return;

		board_[i][j] = '#';
		std::queue<std::pair<int, int>> nodeQue;
		std::pair<int, int> node(i, j);
		nodeQue.push(node);
		while (!nodeQue.empty())
		{
			std::pair<int, int> node = nodeQue.front();
			nodeQue.pop();

			if (isValid(i-1, j) && board_[i-1][j] == 'O') {
				board_[i-1][j] = '#';
				nodeQue.push(std::pair<int, int> (i-1, j));
			}

			if (isValid(i, j-1) && board_[i][j-1] == 'O') {
				board_[i][j-1] = '#';
				nodeQue.push(std::pair<int, int> (i, j-1));
			}

			if (isValid(i+1, j) && board_[i+1][j] == 'O') {
				board_[i+1][j] = '#';
				nodeQue.push(std::pair<int, int> (i+1, j));
			}

			if (isValid(i, j+1) && board_[i][j+1] == 'O') {
				board_[i][j+1] = '#';
				nodeQue.push(std::pair<int, int> (i, j+1));
			}
		}

	}

private:

	vector<vector<char>> board_;
};