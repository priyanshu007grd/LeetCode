/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
    set<pair<int,int>> vis;
    vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
public:

    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void bt(int row, int col, int d,Robot& robot)
    {
        for(int i=0;i<4;i++)
        {
            // robot.move() will take it to diff cell and we will wark diff cell vicited
            int dd = (d+i)%4;

            int r=row+dir[dd][0];
            int c=col+dir[dd][1];
\

            if (vis.find({r,c})==vis.end() && robot.move()) {
                vis.insert({r,c});
                robot.clean();
                bt(r, c, dd,robot);
                goBack(robot);
            }
            // turn the robot following chosen direction : clockwise
            robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) 
    {
        vis.clear();
        vis.insert({0,0});
        robot.clean();
        bt(0,0,0,robot);

    }
};