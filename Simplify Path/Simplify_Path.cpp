/************************************************************

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Corner Cases:

    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".

************************************************************/

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

class Solution {
public:
	std::string simplifyPath(std::string& path)
	{
		std::vector<std::string> pathVec;
		size_t pos_s = path.find("/");
		pos_s = path.find_first_not_of("/", pos_s);
		size_t pos_e = path.find_first_of("/", pos_s);
		while (pos_e != std::string::npos) {
			pathVec.push_back(path.substr(pos_s, pos_e-pos_s));
			pos_s = path.find_first_not_of("/", pos_e);
			pos_e = path.find_first_of("/", pos_s);
		}

		if (pos_s < path.size()) 
			pathVec.push_back(path.substr(pos_s));

		
		std::deque<std::string> ret;
		while (!pathVec.empty()) {
			if (pathVec.back() == ".") {
				pathVec.pop_back();
			} else if (pathVec.back() == "..") {
				int backtraceNum = 1;
				pathVec.pop_back();
				while (backtraceNum) {
					if (pathVec.empty()) break;

					if (pathVec.back() == "..") {
						pathVec.pop_back();
						++backtraceNum;
						continue;
					} else if (pathVec.back() == ".") {
						pathVec.pop_back();
						continue;
					}

					pathVec.pop_back();
					--backtraceNum;
				}

			} else {
				ret.push_front(pathVec.back());
				pathVec.pop_back();
			}
		}
		
		std::string pathRet("/");
		for (std::deque<std::string>::iterator iter = ret.begin();
				iter != ret.end(); ++iter)
		{
			pathRet += *iter;
			pathRet += "/";
		}

		if (!ret.empty()) pathRet.pop_back();

		return pathRet;
	}
	
};

int main()
{
	string path = "/home/foo/.ssh/../.ssh2/authorized_keys/";

	Solution solve;
	std::string ret = solve.simplifyPath(path);

	getchar();
	return 0;
}
