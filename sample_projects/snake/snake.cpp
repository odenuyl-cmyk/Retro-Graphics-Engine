#include <engine.h>
#include <deque>
#include <unordered_set>
#include <random>

using namespace std;

struct Point {
    int x;
    int y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

struct PointHash {
    size_t operator()(const Point& p) const {
        return (p.x * 73856093) ^ (p.y * 19349663);
    }
};

Point randomApple(const unordered_set<Point, PointHash>& occupied) {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(0, 24);

    Point apple;

    do {
        apple.x = dist(gen);
        apple.y = dist(gen)%22;
    } while (occupied.contains(apple)); // C++20

    return apple;
}

int main() {
    Window::init(1000, "Snake Game");
    Window::frameRate(140);

    deque<Point> points;
    unordered_set<Point, PointHash> pointsSet;

    enum direction { UP, DOWN, LEFT, RIGHT };
    direction dir = RIGHT;
    bool dirSelected = false;

    float step = 0.04;
    direction prevMove = RIGHT;

    points.push_back({8, 10});
    pointsSet.insert({8, 10});
    points.push_back({9, 10});
    pointsSet.insert({9, 10});
    points.push_back({10, 10});
    pointsSet.insert({10, 10});

    Point apple = randomApple(pointsSet);


    int x = 10;
    int y = 10;

    int counter = 0;

    while (!Window::shouldClose()) {
        Window::beginFrame();


        if (Input::keyHeld(Key::W) && dir != DOWN && prevMove != DOWN) {
            dir = UP;
        } if (Input::keyHeld(Key::A) && dir != RIGHT && prevMove != RIGHT) {
            dir = LEFT;
        } if (Input::keyHeld(Key::S) && dir != UP && prevMove != UP) {
            dir = DOWN;
        } if (Input::keyHeld(Key::D) && dir != LEFT && prevMove != LEFT) {
            dir = RIGHT;
        }

        if (counter % 20 == 0) {
            if (dir == UP) {
                y -= 1;
                prevMove = UP;
            } else if (dir == DOWN) {
                y += 1;
                prevMove = DOWN;
            } else if (dir == LEFT) {
                x -= 1;
                prevMove = LEFT;
            } else if (dir == RIGHT) {
                x += 1;
                prevMove = RIGHT;
            }
            if (x < 0 || x >= 25) {
                break;
            }
            if (y < 0 || y >= 23) {
                break;
            }
            points.push_back({x, y});
            pointsSet.insert({x, y});

            if (x == apple.x && y == apple.y) {
                apple = randomApple(pointsSet);
            } else {
                pointsSet.erase(points.front());
                points.pop_front();
            }

            if (pointsSet.size() != points.size()) {
                break;
            }
        }

        for (int j = 0; j < 23; j++) {
            for (int i = 0; i < 13; i++) {
                drawRect(i*0.08 + 0.04*(j%2), j*0.04, .04, .04, rgb(25, 25, 25, 255));
            }
        }

        for (Point p : points) {
            drawRect(p.x*step, p.y*step, step, step, RED);
        }
        
        drawRect(apple.x*step, apple.y*step, step, step, GREEN);
        string scoreText = "Score: " + to_string(points.size() - 3);
        string resettext = "Resets: " + to_string(0);
        drawText("Eat apples to grow!", 0.25, 0.95, 20, YELLOW);
        drawText(scoreText, 0.59, 0.95, 20, VIOLET);
        drawText(resettext, 0.86, 0.95, 20, INDIGO);


        Window::endFrame();
        counter++;
    }

    Window::closeWindow();

    return counter;
}