#pragma once

#include <cstddef>
#include <raylib.h>

class Paddle {
    public:
        Paddle(float x, float y, size_t width, size_t height, Color color)
            :x(x), y(y), width(width), height(height), color(color){
            }

        Paddle(Paddle&& other) = default;
        Paddle(const Paddle& other) = default;
        Paddle& operator=(const Paddle& other) = default;
        Paddle& operator=(Paddle&& other) = default;

        inline Rectangle getBounds() const{
            return {x, y, (float) width, (float) height};
        }

        inline Vector2 getTopLeftCoord() const{
            return {x, y};
        }

        inline Vector2 getCenterCoord() const{
            return {x - width / 2.f, y - height / 2.f};
        }

        inline float getX() const{
            return x;
        }

        inline float getY() const{
            return y;
        }


        inline size_t getWidth() const{
            return width;
        }

        inline size_t getHeight() const{
            return height;
        }

        inline Color getColor() const{
            return color;
        }
 
        void setX(float x){
            this->x = x;
        }

        void setY(float y){
            this->y = y;
        }

    private:
        float x, y;
        size_t width, height;
        Color color;
};

