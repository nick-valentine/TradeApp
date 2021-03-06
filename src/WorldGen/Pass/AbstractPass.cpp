#include "WorldGen/Pass/AbstractPass.hpp"

void AbstractPass::execute(World *world, boost::shared_ptr<Logger> logger)
{
    for (int i = 0; i < world->chunks.size(); ++i) {
        for (int j = 0; j < world->chunks[i].size(); ++j) {
            this->executeChunk(i, j, &world->chunks[i][j]);
        }
    }

}

void AbstractPass::executeChunk(int top, int left, WorldChunk *chunk) 
{
    for (int i = 0; i < chunk->tiles.size(); ++i) {
        for (int j = 0; j < chunk->tiles[i].size(); ++j) {
            this->doTile(
                i + (top * WorldChunk::getChunkHeight()), 
                j + (left * WorldChunk::getChunkWidth()), 
                &chunk->tiles[i][j],
                chunk
            );
        }
    }
}
