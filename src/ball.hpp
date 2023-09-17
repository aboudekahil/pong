#include <cstddef>
#include <raylib.h>

class Ball {
    public:
        Ball(float x, float y, size_t r, Color color)
            :x(x), y(y), r(r), color(color)
        {}

        Ball(Ball&& other) = default;
        Ball(const Ball& other) = default;
        Ball& operator=(Ball&&) = default;
        Ball& operator=(const Ball&) = default;

        inline Vector2 getTopLeftCoord() const{
            return {x, y};
        }

        inline Vector2 getCenterCoord() const{
            return {x - r / 2.f, y - r / 2.f};
        }

        inline float getX() const{
            return x;
        }

        inline float getY() const{
            return y;
        }

        inline size_t getRadius() const{
            return r;
        }

        inline Color getColor() const{
            return color;
        }

        inline Rectangle getBounds() const{
            return {x, y, (float) r, (float) r};
        }

        void setX(float x){
            this->x = x;
        }

        void setY(float y){
            this->y = y;
        }

    private:
        float x, y;
        size_t r;
        Color color;
};
