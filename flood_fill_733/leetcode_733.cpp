class Solution {
public:
    void func(vector<vector<int>> &image, int x, int y, int newColor){
        int prev = image[x][y];
        if(prev == newColor){
            return;
        }
        int n = image.size();
        int m = image[0].size();
        
        image[x][y] = newColor;
        if(x - 1 >= 0){
            if(image[x - 1][y] == prev){
                func(image, x - 1, y, newColor);
            }
        }
        if(x + 1 < n){
            if(image[x + 1][y] == prev){
                func(image, x + 1, y, newColor);
            }
        }
        if(y - 1 >= 0){
            if(image[x][y - 1] == prev){
                func(image, x, y - 1, newColor);
            }
        }
        if(y + 1 < m){
            if(image[x][y + 1] == prev){
                func(image, x, y + 1, newColor);
            }
        }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        func(image, sr, sc, color);
        return image;
    }
};