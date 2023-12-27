#pragma once

namespace Interaction
{
    // A class whose instance is generated when 
    // the player triggers a tapping action
    class Tap
    {
    public:
        Tap() {};
        Tap(int x, int y, int button);
        int getPositionX() const;
        int getPositionY() const;
        int getButton() const;
    private:
        int positionX;
        int positionY;
        int button;

    };
}