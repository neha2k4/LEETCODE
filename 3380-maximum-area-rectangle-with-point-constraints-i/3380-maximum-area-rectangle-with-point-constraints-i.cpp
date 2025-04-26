class Solution {
public:
    // Helper function to calculate the maximum rectangle area given four points
    int get(vector<pair<int, int>>& points) {
        int maxArea = -1;
        for (int i = 0; i < points.size() - 3; i++) {
            // Check if these points can form a rectangle:
            // - First and second points have the same x-coordinate
            // - Third and fourth points have the same x-coordinate
            // - First and third points have the same y-coordinate
            // - Second and fourth points have the same y-coordinate
            if (points[i].first == points[i + 1].first &&
                points[i + 2].first == points[i + 3].first &&
                points[i].second == points[i + 2].second &&
                points[i + 1].second == points[i + 3].second) {
                // Calculate the area of the rectangle
                int area = (points[i + 2].first - points[i].first) * 
                           (points[i + 1].second - points[i].second);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }

    int maxRectangleArea(vector<vector<int>>& points) {
        int maxArea = -1;
        int n = points.size();

        // Sort the points by their x-coordinates and then by y-coordinates
        sort(points.begin(), points.end());

        // Iterate over the points to find all potential rectangles
        for (int i = 0; i < n - 3; i++) {
            vector<pair<int, int>> rectanglePoints;

            // Add the first two points of the rectangle
            rectanglePoints.push_back({points[i][0], points[i][1]});
            rectanglePoints.push_back({points[i + 1][0], points[i + 1][1]});

            // Find the next two points that complete the rectangle
            int j = i + 2;
            while (j < n - 2) {
                // Skip points that don't align with the y-coordinates of the rectangle
                if (points[j][1] > points[i + 1][1] || points[j][1] < points[i][1]) {
                    j++;
                } else {
                    break;
                }
            }

            // Add the potential third and fourth points
            if (j < n - 1) {
                rectanglePoints.push_back({points[j][0], points[j][1]});
                rectanglePoints.push_back({points[j + 1][0], points[j + 1][1]});

                // Calculate the maximum area for this set of points
                maxArea = max(maxArea, get(rectanglePoints));
            }
        }

        return maxArea;
    }
};