// https://leetcode.com/problems/flood-fill/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    typedef vector<vector<int>> GRAPH;
    int ROWS = 0, COLS = 0;
    int oldColor = 0, newColor = 0;
public:
    bool validDir(const int &nr, const int &nc){
        return 0 <= nr && nr < ROWS && 0 <= nc && nc < COLS;
    }
    void coloring(GRAPH &image, GRAPH &vis, int sr, int sc){
        if(!validDir(sr, sc))
            return;
        if(vis[sr][sc] || image[sr][sc] != oldColor)
            return;

        vis[sr][sc] = 1;
        image[sr][sc] = newColor;

        coloring(image, vis, sr-1, sc);
        coloring(image, vis, sr,   sc+1);
        coloring(image, vis, sr+1, sc);
        coloring(image, vis, sr,   sc-1);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int Color) {
        ROWS = (int)image.size();
        COLS = (int)image[0].size();
        oldColor = image[sr][sc];
        newColor = Color;

        GRAPH vis(ROWS, vector<int>(COLS, 0));
        coloring(image, vis, sr, sc);

        return image;

    }
};

int main(){


    return 0;
}
