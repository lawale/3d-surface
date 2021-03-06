﻿// 3dSurface.cpp : Defines the entry point for the console application.
//
#include <bits/stdc++.h>
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

vector<string> split_string(string);
int surfaceArea(vector < vector<int> > A) {
	// Complete this function
	int Height = A.size();
	int Weight = A[0].size();
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

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string HW_temp;
	getline(cin, HW_temp);

	vector<string> HW = split_string(HW_temp);

	int H = stoi(HW[0]);

	int W = stoi(HW[1]);

	vector<vector<int>> A(H);
	for (int i = 0; i < H; i++) {
		A[i].resize(W);

		for (int j = 0; j < W; j++) {
			cin >> A[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int result = surfaceArea(A);

	fout << result << "\n";

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}

