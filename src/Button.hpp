#pragma once // search up what this does
#include <raylib.h>

class Button {

    public:

        Button();
        ~Button();
        void Draw(); // used to draw buttons 

    private:
        Texture2D texture;
        Vector2D position; // continue youtube vid maybe
};