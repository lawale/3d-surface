// 3dSurface.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

int surfaceArea(vector < vector<int> > A, int Height, int Weight) {
	// Complete this function
	int total_front_side = 0;
	int left_side = 0;
	int right_side = 0;
	int front_side = 0;
	int back_side = 0;
	for (int index_i = 0; index_i < Height; index_i++)
	{
		front_side = A[index_i][0];
		back_side += A[index_i][Weight - 1];
		if (Height == 1)
		{
			for (int index_j = 0; index_j < Weight; index_j++)
			{
				left_side += A[index_i][index_j];
				right_side += A[index_i][index_j];
				if (index_j != 0)
				{
					front_side += abs(A[index_i][index_j] - A[index_i][index_j - 1]);
				}
			}
		}
		else
		{
			for (int index_j = 0; index_j < Weight; index_j++)
			{
				if (index_i == 0)
				{
					left_side += A[0][index_j];
				}
				else
				{
					if (A[index_i][index_j] > A[index_i - 1][index_j])
					{
						left_side += (A[index_i][index_j] - A[index_i - 1][index_j]);
					}
					else if (A[index_i][index_j] < A[index_i - 1][index_j])
					{
						left_side += (A[index_i - 1][index_j] - A[index_i][index_j]);
					}
					else
					{
						left_side += 0;
					}
					if (index_i == (Height - 1))
					{
						right_side += A[index_i][index_j];
					}
				}
			}
			for (int index_j = 1; index_j < Weight; index_j++)
			{
				if (A[index_i][index_j] > A[index_i][index_j - 1])
				{
					front_side += (A[index_i][index_j] - A[index_i][index_j - 1]);
				}
				else if (A[index_i][index_j] < A[index_i][index_j - 1])
				{
					front_side += (A[index_i][index_j - 1] - A[index_i][index_j]);
				}
			}
		}
		total_front_side += front_side;
	}
	int top_and_base = 0;
	for (int index_i = 0; index_i < Height; index_i++)
	{
		for (int index_j = 0; index_j < Weight; index_j++)
		{
			if (A[index_i][index_j] > 0)
			{
				top_and_base++;
			}
		}
	}
	top_and_base *= 2;
	int result = (top_and_base + right_side + left_side + back_side + total_front_side);
	/*cout << "top & base 18 --> " << top_and_base << " right 7 --> " << right_side << " left 13 --> "
		<< left_side << " back 11 --> " << back_side << " front 11 --> " << total_front_side << endl;*/
	return result;
}

int main() {
	int H;
	int W;
	cin >> H >> W;
	vector< vector<int> > A(H, vector<int>(W));
	for (int A_i = 0; A_i < H; A_i++) {
		for (int A_j = 0; A_j < W; A_j++) {
			cin >> A[A_i][A_j];
		}
	}
	int result = surfaceArea(A, H, W);
	cout << result << endl;
	return 0;
}

