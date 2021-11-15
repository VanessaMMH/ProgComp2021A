#include <iostream>
#include <vector>

using namespace std;

void floodfill(vector<vector<int>> &image, int i, int j, int oldColor)
{
  int m = image.size();
  int n = image[0].size();

  if (i < 0 || j < 0 || i >= m || j >= n)
    return;
  if (image[i][j] == -1 || image[i][j] != oldColor)
    return;

  image[i][j] = -1;

  floodfill(image, i - 1, j, oldColor);
  floodfill(image, i + 1, j, oldColor);
  floodfill(image, i, j - 1, oldColor);
  floodfill(image, i, j + 1, oldColor);
}

class Solution
{
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
  {
    int m = image.size();
    int n = image[0].size();

    int oldColor = image[sr][sc];
    floodfill(image, sr, sc, oldColor);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (image[i][j] == -1)
          image[i][j] = newColor;
    return image;
  }
};