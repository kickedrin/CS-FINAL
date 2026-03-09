#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Record {
    int x;
    char ch;
    int y;
};

int main() {
    ifstream inFile("InputData.txt");

    if (!inFile.is_open()) {
        cout << "Unable to open the input file." << endl;
        return 1;
    }

    vector<Record> records;
    int x, y;
    char ch;
    int maxX = 0;
    int maxY = 0;

    // Read all records from the file
    while (inFile >> x >> ch >> y) {
        Record temp;
        temp.x = x;
        temp.ch = ch;
        temp.y = y;

        records.push_back(temp);

        // Find the maximum x and y values
        if (temp.x > maxX) {
            maxX = temp.x;
        }

        if (temp.y > maxY) {
            maxY = temp.y;
        }
    }

    inFile.close();

    // Create a 2D array initialized with spaces
    vector<vector<char>> grid(maxY + 1, vector<char>(maxX + 1, ' '));

    // Fill the 2D array with characters
    for (int i = 0; i < records.size(); i++) {
        grid[records[i].y][records[i].x] = records[i].ch;
    }

    // Print the completed array
    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            cout << grid[row][col];
        }
        cout << endl;
    }

    return 0;
}