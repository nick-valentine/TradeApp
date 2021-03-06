#ifndef TYPE_PASS_HPP
#define TYPE_PASS_HPP

#include <string>
#include <vector>

#include "WorldGen/Pass/AbstractPass.hpp"

#include "WorldGen/NoiseFunc.hpp"
#include "Services/Logger/Logger.hpp"

class TypePass : public AbstractPass
{
public:
    void init();
    void doTile(int i, int j, Tile *tile, WorldChunk *chunk);

    AbstractPass *clone();

    std::string getName();
private:
    static const int veryLargeMultiplyer = 1000000;
    const static std::string name;

    static constexpr float typeNoiseSpread = 20.0;

    int typeMap(Tile *tile, float tileInput);

    NoiseFunc typeNoise;
};

#endif //ELEVATION_PASS_HPP
