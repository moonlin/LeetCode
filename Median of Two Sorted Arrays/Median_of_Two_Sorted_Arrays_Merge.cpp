/**********************************

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).

**********************************/

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		std::vector<int> a(A, A + m);
		std::vector<int> b(B, B + n);
		if (m == 0) return getMedian(b);
		if (n == 0) return getMedian(a);

		return findMedianSortedArrays_impl(a, b);
	}

	double findMedianSortedArrays_impl(std::vector<int>& a, std::vector<int>& b)
	{
		uint i = 0;
		uint j = 0;
		std::vector<int> vec;
		while (i < a.size() && j < b.size()) {
			if (a[i] <= b[j]) vec.push_back(a[i++]);
			else vec.push_back(b[j++]);
		}

		while (i < a.size()) vec.push_back(a[i++]);
		while (j < b.size()) vec.push_back(b[j++]);

		return getMedian(vec);
	}

	double getMedian(std::vector<int>& vec)
	{
		int n = vec.size();
		return (n%2)? vec[n/2]: (vec[n/2-1] + vec[n/2]) / 2.0;
	}
};
