#include <iostream>
#include <vector>
using namespace std;

// Global variables to store the input
int H, W, n;
vector<pair<int, int>> rectangles;

// A 2D grid to mark used spaces on the material
bool used[10][10] = {false};

// Function to check if we can place a rectangle at (x, y)
bool canPlace(int x, int y, int h, int w) {
    if (x + h > H || y + w > W) return false; // Out of bounds
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (used[x + i][y + j]) return false; // Already used space
        }
    }
    return true;
}

// Function to mark or unmark a rectangle on the grid
void placeRectangle(int x, int y, int h, int w, bool place) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            used[x + i][y + j] = place;
        }
    }
}

// Backtracking function to try placing all rectangles
bool TRY(int k) {
    if (k == n) return true; // All rectangles placed

    int h = rectangles[k].first;
    int w = rectangles[k].second;

    // Try placing the rectangle in both orientations
    for (int x = 0; x < H; ++x) {
        for (int y = 0; y < W; ++y) {
            // Try placing the rectangle in original orientation
            if (canPlace(x, y, h, w)) {
                placeRectangle(x, y, h, w, true);
                if (TRY(k + 1)) return true; // Proceed to next rectangle
                placeRectangle(x, y, h, w, false); // Backtrack
            }
            // Try placing the rectangle in rotated orientation
            if (canPlace(x, y, w, h)) {
                placeRectangle(x, y, w, h, true);
                if (TRY(k + 1)) return true; // Proceed to next rectangle
                placeRectangle(x, y, w, h, false); // Backtrack
            }
        }
    }

    return false; // No valid placement found
}

int main() {
    cin >> H >> W >> n;
    rectangles.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> rectangles[i].first >> rectangles[i].second;
    }

    if (TRY(0)) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}
