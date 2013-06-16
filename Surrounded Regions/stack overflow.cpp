

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
typedef unsigned int uint;


class Solution {
public:
	void solve(vector<vector<char>>& board)
	{
		// board_ = board;
		for (uint i = 0; i < board_.size(); ++i)
		{
			for (uint j = 0; j < board_.size(); ++j)
			{
				if (board_[i][j] == 'O')
				{
					dfs(i, j);
				}
			}

			std::cout <<"i == " <<i <<'\n';
		}

		for (uint i = 0; i < board_.size(); ++i) {
			for (uint j = 0; j < board_.size(); ++j) {
				if (board_[i][j] == 'D') {
					board_[i][j] = 'X';
				} else if (board_[i][j] == '#') {
					board_[i][j] = 'O';
				}
			}
		}
	
		board.swap(board_);
	}

	bool dfs(uint i, uint j)
	{
		board_[i][j] = 'V';
		if (i == 0 || i == board_.size()-1) 
		{
			board_[i][j] = '#';
			return false;
		}

		if (j == 0 || j == board_.size()-1) 
		{
			board_[i][j] = '#';
			return false;
		}
		
		if (board_[i-1][j] == '#') { board_[i][j] = '#'; return false; }
		if ((board_[i-1][j] == 'O' || board_[i-1][j] == 'D') 
			&& dfs(i-1, j) == false) 
		{
			board_[i][j] = '#';
			return false;
		}

		if (board_[i][j-1] == '#') { board_[i][j] = '#'; return false; }
		if ((board_[i][j-1] == 'O' || board_[i][j-1] == 'D') 
			&& dfs(i, j-1) == false) 
		{
			board_[i][j] = '#';
			return false;
		}

		if (board_[i+1][j] == '#') { board_[i][j] = '#'; return false; }
		if ((board_[i+1][j] == 'O' || board_[i+1][j] == 'D') 
			&& dfs(i+1, j) == false) 
		{
			board_[i][j] = '#';
			return false;
		}

		if (board_[i][j+1] == '#') { board_[i][j] = '#'; return false; }
		if ((board_[i][j+1] == 'O' || board_[i][j+1] == 'D') 
			&& dfs(i, j+1) == false) 
		{
			board_[i][j] = '#';
			return false;
		}

			
		board_[i][j] = 'D';
		return true;
	}

	void init()
	{
		string str;
		ifstream inFile;
		inFile.open("a.txt");
		string line;
		while(getline(inFile,line)) {
			str += line;
		}

		int level = 0;
		size_t pos_s = str.find('#');
		while (pos_s != std::string::npos)
		{
			size_t pos_e = str.find('#', pos_s+1);
			if (pos_e != std::string::npos)
			{
				string cut = str.substr(pos_s+1, pos_e-pos_s-1);
				for (int i = 0; i < cut.size(); ++i) {
					board_.resize(level+1);
					board_[level].push_back(cut[i]);
				}
			}

			pos_s = str.find('#', pos_e+1);
			++level;
		}
	}

private:

	vector<vector<char>> board_;
};


int main()
{
	Solution solve;

	vector<vector<char>> board;

	solve.init();
	solve.solve(board);

	getchar();
	return 0;
}
