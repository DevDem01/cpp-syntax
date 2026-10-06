#include <iostream>

class Vector
{
    private:
    float x, y;
    // float* p = new float;

    public:
    Vector() {}
    Vector(float x, float y) {
        this->x = x;
        this->y = y;

    }
    // ~Vector() {
    //     delete p;
    // }

    Vector operator+(const Vector& p2) {

        return {x + p2.x, y + p2.y};

    };

    friend std::ostream& operator<<(std::ostream& stream, const Vector& p);
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
