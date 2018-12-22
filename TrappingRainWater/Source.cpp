/*Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//using dynamic programming approach


int trap(vector<int>& height)
{
	int s = height.size();

	vector<int> max_left(s), max_right(s);
	int ret = 0;

	//first element is first max from L
	max_left[0] = height[0];


	for (int i = 1; i < s; i++)
	{
		//get maximums for each index, L to R
		max_left[i] = max(height[i], max_left[i - 1]);
	}

	//first element is max from R
	max_right[s - 1] = height[s - 1];

	for (int j = s - 2; j >= 0; j--)
	{
		max_right[j] = max(height[j], max_right[j + 1]);
	}

	//get the difference for each element
	for (int i = 1; i < s - 1; i++)
	{
		ret += min(max_left[i], max_right[i]) - height[i];
	}
	
	return ret;
}
int main()
{
	vector<int> test = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	
	vector<int> test2 = { 5, 4, 1, 2 };

	

	cout << trap(test) << endl;
}