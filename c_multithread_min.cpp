// a minimal multithread function implementation with file outputs and a timer
// Copyright (C) 2020 Logan Bier

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <thread>

using namespace std;
using namespace std::chrono;

unsigned long long x = 4; 
unsigned long long n = 38;
bool t = free;

void open_file_1(unsigned long long num_1)
{
	ifstream in_file("file_1.txt");
	if (!in_file)
		cerr << "no file\n";

    for (string line; getline(in_file, line); ) {
		cout << "\n" << line << "\n";
	}

    ofstream out_file("file_1.txt");
    out_file << num_1 << "\n" << "File 1 write complete.\n";
}

void open_file_2(unsigned long long num_1)
{
	ifstream in_file("file_2.txt");
	if (!in_file)
		cerr << "no file\n";

    for (string line; getline(in_file, line); ) {
		cout << "\n" << line << "\n";
	}

    ofstream out_file("file_2.txt");
    out_file << num_1 << "\n" << "File 2 write complete.\n";
}

const unsigned long long nth(unsigned long long x, unsigned long long n)
{
	while (t) {
		++x;
        if (x > 9876540) {
			open_file_1(x);
        	break;
        }
	}
}

const unsigned long long nth2(unsigned long long x, unsigned long long n)
{
	while (t) {
		++x;
        if (x > 500000) {
			open_file_2(x);
        	break;
        }
	}
}

// int main() {cout << nth(x, n) << "\n";}
int main() 
{
    auto t0 = high_resolution_clock::now();
    thread only(nth, x, n);
    thread only2(nth2, x, n);
    only.join();
    only2.join();
    auto t1 = high_resolution_clock::now();
    cout << "\n" << duration_cast<milliseconds>(t1-t0).count() << "ms\n";
}
