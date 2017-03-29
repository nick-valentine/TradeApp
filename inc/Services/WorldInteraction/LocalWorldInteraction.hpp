#ifndef LOCAL_WORLD_INTERACTION
#define LOCAL_WORLD_INTERACTION

#include <string>

#include "GameObjects/World.hpp"
#include "Screen.hpp"
#include "Services/WorldInteraction/WorldInteractionInterface.hpp"

/**
 * Manager for non-networked world interaction.
 */
class LocalWorldInteraction : virtual public WorldInteractionInterface, protected World
{
public:
    LocalWorldInteraction(std::string worldName);

    void loadWorld();
    void draw(Screen &screen);
    void movePlayerToCoordinate(int y, int x);
protected:
    int playerX;
    int playerY;
};

#endif //LOCAL_WORLD_INTERACTION
