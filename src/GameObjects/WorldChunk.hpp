#ifndef WORLDCHUNK_HPP
#define WORLDCHUNK_HPP

#include <algorithm>
#include <curses.h>
#include <map>
#include <math.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>

#include "Globals.hpp"
#include "ConfigLoader.hpp"
#include "GameObjects/AbstractGameObject.hpp"
#include "GameObjects/City.hpp"
#include "GameObjects/Tile.hpp"
#include "Globals.hpp"
#include "Window/Window.hpp"
#include "WorldGen/NoiseFunc.hpp"

class WorldChunk : public AbstractGameObject
{
public:
    WorldChunk();
    WorldChunk(unsigned int top, unsigned int left);
    WorldChunk(std::stringstream *ss);
    static void configure();

    static void setMaxYX(unsigned int y, unsigned int x);

    /**
     * The stringstream structure expected into this is
     * ObjectName objectData1, objectData2, ...
     * ObjectName objectData1, objectData2, ...
     * MAP
     * 1 2 3 4 2 3 1 2 3  1 ...
     */
    void fromStringStream(std::stringstream *ss);
    void toStringStream(std::stringstream *ss);

    void generateChunk();

    void draw(Window::window_ptr window, int offsetTop, int offsetLeft);

    City getCity(int y, int x);

    static unsigned int getChunkWidth();
    static unsigned int getChunkHeight();
    static unsigned int setChunkWidth (unsigned int w);
    static unsigned int setChunkHeight(unsigned int h);
    static int getMaxCitiesPerChunk();

    std::vector<City> cities;
    std::vector< std::vector<Tile> > tiles;
private:
    static const std::string CityMarker;
    static const std::string MapMarker;
    static const int maxViewDistance = 10;
    static const bool cullingEnabled = true;

    static bool configured;
    static unsigned int chunk_height;
    static unsigned int chunk_width;

    //screen dimension maximums
    static int maxX;
    static int maxY;

    enum READ_STATE {
        object = 0,
        map = 1
    };

    //@todo: replace with more powerful class
    bool doCullTile(int playerY, int playerX, int tileY, int tileX, int localTileI, int localTileJ);

    static std::map<std::string, void (*)(WorldChunk *self, std::stringstream *ss)> factoryMap; 

    //factory methods
    static void spawnCity(WorldChunk *self, std::stringstream *ss);

    void organizeTiles(std::vector<Tile> tiles);

//    float elevationMap(float input, float skew);

    unsigned int top;
    unsigned int left;
};


#endif //WORLDCHUNK_HPP
