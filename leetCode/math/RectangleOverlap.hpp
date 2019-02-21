//https://leetcode.com/problems/rectangle-overlap/
namespace my {
    struct Point {
        int x, y;
    };

    struct Rect {
        Point bottomLeft, topRight;
        Rect(const vector<int>& rec) {
            bottomLeft.x = rec[0];
            bottomLeft.y = rec[1];
            topRight.x = rec[2];
            topRight.y = rec[3];
        }

        inline bool isInside(const Rect & rect) {
            return rect.bottomLeft.x <= bottomLeft.x
                and rect.bottomLeft.y <= bottomLeft.y
                and rect.topRight.x >= topRight.x
                and rect.topRight.y >= topRight.y;
        }
        
        inline bool intersect(const Rect & rect) {
            return !this->notIntersect(rect);
        }
        
        inline bool notIntersect(const Rect & rect) {
            return bottomLeft.y >= rect.topRight.y
                || rect.bottomLeft.y >= topRight.y
                || topRight.x <= rect.bottomLeft.x
                || rect.topRight.x <= bottomLeft.x
                || bottomLeft.x >= rect.topRight.x
                || rect.bottomLeft.x >= topRight.x
                || bottomLeft.y >= rect.topRight.y;
        }
    };    
};

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        my::Rect rect1(rec1), rect2(rec2);
        return rect1.intersect(rect2);
    }
};
