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

		return findMedianSortedArrays_impl(a, 0, a.size()-1, b, 0, b.size()-1);
	}

	double findMedianSortedArrays_impl(std::vector<int>& a, int as, int ae, std::vector<int>& b, int bs, int be)
	{
		if (as+1 >= ae || bs+1 >= be) {
			vector<int> vec;
			while (as <= ae && bs <= be) {
				if (a[as] <= b[bs]) vec.push_back(a[as++]);
				else vec.push_back(b[bs++]);
			}

			while (as <= ae) vec.push_back(a[as++]);
			while (bs <= be) vec.push_back(b[bs++]);

			return vec.size()%2? vec[vec.size()/2]: (vec[vec.size()/2-1]+vec[vec.size()/2])/2.0;
		}

		int medianA = (ae + as)/2;
		int medianB = (be + bs)/2;
		if (a[medianA] <= b[medianB]) {
			int diff = 0;
			if ((ae+1-as)%2 == 0 && (be+1-bs)%2 == 0) {
				diff = std::min(medianA-as, be-medianB-1);
			} else if ((ae+1-as)%2 && (be+1-bs)%2) {
				diff = std::min(medianA-as, be-medianB);
			} else {
				diff = std::min(medianA-as+1, be-medianB);
			}

			return findMedianSortedArrays_impl(a, as+diff, ae, b, bs, be-diff);

		} else {
			int diff = 0;
			if ((ae+1-as)%2 == 0 && (be+1-bs)%2 == 0) {
				diff = std::min(ae-medianA-1, medianB-bs);
			} else if ((ae+1-as)%2 && (be+1-bs)%2) {
				diff = std::min(ae-medianA, medianB-bs);
			} else {
				diff = std::min(ae-medianA, medianB-bs+1);
			}

			return findMedianSortedArrays_impl(a, as, ae-diff, b, bs+diff, be);

		}
	}

	double getMedian(std::vector<int>& vec)
	{
		int n = vec.size();
		return (n%2)? vec[n/2]: (vec[n/2-1] + vec[n/2]) / 2.0;
	}
};
