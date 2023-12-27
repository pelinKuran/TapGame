#pragma once
#include "SDL.h"
namespace UI
{
    // A base class for the instances that are planned
    // to be represented in the UI. Any classes inherited from
    // UIElement can be shown on the UI by calling
    //the related method(s) of Scene
    class UIElement
    {
    public:
        UIElement();
        virtual void draw() const = 0;
        virtual void remove() const = 0;
        virtual void setDestXY(int x, int y) = 0;
        virtual bool getState() = 0;
        virtual void setState(bool state) const = 0;
        // Some related code for handling any sort of
        // UI and rendering operations.
        bool operator==(const UIElement& other) const;
        
    private:
        int id = 0;
        static int count;
    };
}