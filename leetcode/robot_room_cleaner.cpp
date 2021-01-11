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

namespace std {
    template<>
    struct hash<std::pair<int, int> > {
        size_t operator()(const std::pair<int, int> &p) const {
            return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
        }
    };
}

class Solution {
private:
    unordered_set<pair<int, int>> visited;
    enum Direction {
        UP,
        RIGHT,
        DOWN,
        LEFT,
    };

    static const unordered_map<Direction, pair<int, int>> directionToShift;
    static const unordered_map<Direction, Direction> directionToDirection;

    void cleanRoomHelper(Robot& robot, Direction direction, const pair<int, int>& point) {
        visited.insert(point);
        robot.clean();

        for (size_t i = 0; i < 4; ++i) {
            auto shift = directionToShift.at(direction);
            auto newPoint = make_pair(point.first + shift.first, point.second + shift.second);

            if (visited.find(newPoint) == visited.end() && robot.move()) {
                cleanRoomHelper(robot, direction, newPoint);
            }

            robot.turnRight();
            direction = directionToDirection.at(direction);
        }

        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
public:
    void cleanRoom(Robot& robot) {
        cleanRoomHelper(robot, UP, {0, 0});
    }
};

const unordered_map<Solution::Direction, pair<int, int>> Solution::directionToShift = {
    {UP, {-1, 0}},
    {RIGHT, {0, 1}},
    {DOWN, {1, 0}},
    {LEFT, {0, -1}},
};

const unordered_map<Solution::Direction, Solution::Direction> Solution::directionToDirection = {
    {UP, RIGHT},
    {RIGHT, DOWN},
    {DOWN, LEFT},
    {LEFT, UP},
};

