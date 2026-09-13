
#include <iostream>
struct Student
{
    int ID;
    char grade;
    float gpa;
};
struct Vector
{
    float x, y;
};
Vector operator+(Vector p1, Vector p2)
{
    return {p1.x + p2.x, p1.y + p2.y};
};
std::ostream &operator<<(std::ostream &stream, Vector p)
{
    stream << p.x << ',' << p.y << std::endl;
    return stream;
};
int main()
{
    Student s1, s2;
    s1.ID = 1001;
    s1.grade = 'A';
    s1.gpa = 3.9f;
    s2 = {1002, 'B', 3.0f};
    // s2 = {};
    std::cout << s1.ID << ',' << s1.grade << ',' << s1.gpa << std::endl;
    std::cout << s2.ID << ',' << s2.grade << ',' << s2.gpa << std::endl;
    Vector Position, speed;
    Position = {1.0f, 1.0f};
    speed = {0.5f, 1.5f};
    Vector NewPosition = Position + speed;
    std::cout << Position.x << ',' << Position.y << std::endl;

    std::cout << speed.x << ',' << speed.y << std::endl;
    std::cout << NewPosition.x << ',' << NewPosition.y << std::endl;
    std::cout << Position;
    std::cout << speed;
    std::cout << NewPosition;
    return 0;
}
