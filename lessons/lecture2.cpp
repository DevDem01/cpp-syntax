#include <iostream>

struct Vector
{
    float x, y;
};

Vector operator+(const Vector& p1, const Vector& p2) {

    return {p1.x + p2.x, p1.y + p2.y};

};

std::ostream& operator<<(std::ostream& stream, const Vector& p){

    stream << p.x << ',' << p.y << std::endl; // modiy the output stream, so cannot make it a const
    return stream;

};


int main() {

    Vector Position, speed;
    Position = {1.0f, 1.0f};
    speed = {0.5f, 1.5f};

    std::cout << Position;
    std::cout << speed;

    Vector NewPosition = Position + speed;

    std::cout << Position;
    std::cout << speed;
    std::cout << NewPosition;

    return 0;
}
