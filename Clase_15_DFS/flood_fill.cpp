#include <iostream>
#include <vector>

using namespace std;

void fd(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[sr].size() || image[sr][sc] != oldColor) {
        return;
    }
    image[sr][sc] = newColor;
    fd(image, sr + 1, sc, oldColor, newColor);
    fd(image, sr - 1, sc, oldColor, newColor);
    fd(image, sr, sc + 1, oldColor, newColor);
    fd(image, sr, sc - 1, oldColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if (image[sr][sc] == newColor)return image;
    fd(image, sr, sc, image[sr][sc], newColor);
    return image;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> image = { {0,0,0},{0,0,0} };
    vector<vector<int>> image2 = floodFill(image, sr, sc, newColor);
    return 0;
}