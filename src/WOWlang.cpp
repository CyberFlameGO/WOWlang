// WOWlang.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>


void interpret(std::string input) {
	std::vector<int> memory { 0 };
	std::vector<int>::iterator mem_pos = memory.begin();
	std::stack<std::string::iterator> brac_open_pos;
	std::string::iterator prog_pos;
	int reg = 0;

	for (prog_pos = input.begin(); prog_pos < input.end() - 2; ++prog_pos) {
		if (*prog_pos == 'w') {
			if (*(++prog_pos) == 'o') {
				if (*(++prog_pos) == 'w') {
					(*mem_pos)--;
				}
				else if (*(prog_pos) == 'W') {
					if ((mem_pos != memory.end())&&(next(mem_pos) == memory.end())) {
						memory.push_back(0);
						mem_pos = memory.end() - 1;
					}
					else {
						mem_pos++;
					}
				}
				else if (*(prog_pos) == 'o') {
					if (*(++prog_pos) == 'w') {
						reg = *mem_pos;
					}
					else {
						prog_pos--;
					}
				}
				else {
					prog_pos--;
				}
			}
			else if (*(prog_pos) == 'O') {
				if (*(++prog_pos) == 'w') {
					std::cin >> *mem_pos;
				}
				else if (*(prog_pos) == 'W') {
					brac_open_pos.push(prog_pos + 1);
				}
				else {
					prog_pos--;
				}
			}
			else {
				prog_pos--;
			}
		}
		else if (*prog_pos == 'W') {
			if (*(++prog_pos) == 'o') {
				if (*(++prog_pos) == 'w') {
					mem_pos--;
				}
				else if (*(prog_pos) == 'W') {
					std::cout << (char)(*mem_pos);
				}
				else {
					prog_pos--;
				}
			}
			else if (*(prog_pos) == 'O') {
				if (*(++prog_pos) == 'w') {
					if (*mem_pos == 0) {
						prog_pos = input.begin() + input.find("wOW", ++prog_pos - input.begin());
					}
				}
				else if (*(prog_pos) == 'W') {
					(*mem_pos)++;
				}
				else {
					prog_pos--;
				}
			}
			else {
				prog_pos--;
			}
		}
	}
}

int main()
{
	interpret("");
}
