#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    void update(vector<vector<int>>& image,int i,int j,int org, int color,int m, int n)
    {
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return;
        }

        if(image[i][j]!=org || image[i][j]==color)
        {
            return;
        }

        image[i][j]=color;
        
        update(image,i-1,j,org,color,m,n);
        update(image,i+1,j,org,color,m,n);
        update(image,i,j-1,org,color,m,n);
        update(image,i,j+1,org,color,m,n);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org=image[sr][sc];
        int m=image.size();
        int n= (m>0) ? image[0].size() : 0;
        update(image,sr,sc,org,color,m,n);
        return image;
    }
};