struct Vector2
{
    float x, y;

    Vector2(float x = 0, float y = 0) : x(x), y(y) {}

    Vector2 operator*(float scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }
};

struct Vector3
{
    float x, y, z;

    Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    Vector3 operator*(float scalar) const
    {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }
};
