/*There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& n, vector<int>& m)
{
	vector<int> nm;

	nm.reserve(n.size() + m.size());
	nm.insert(nm.end(), n.begin(), n.end());
	nm.insert(nm.end(), m.begin(), m.end());
	sort(nm.begin(), nm.end());

	if (nm.size() % 2 == 1) 
	{
		return nm[(nm.size() / 2)];
	}
	else
	{
		cout << (nm.size() / 2) << endl;
		cout << ((nm.size() / 2) - 1) << endl;

		double ret = (nm[(nm.size() / 2)] + nm[((nm.size() / 2) - 1)]) /(double) 2;
		return ret;
	}
	
}
int main()
{
	vector<int> n = { 1, 2 };
	vector<int> m = { 3, 4 };

	double bloop = findMedianSortedArrays(n, m);

	cout << bloop;
}