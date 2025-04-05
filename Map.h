//
// Created by Nj on 4/5/2025.
//

#ifndef THE_FLOOR_IS_LAVA_MAP_H
#define THE_FLOOR_IS_LAVA_MAP_H

#pragma once
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

class Map {
public:
    Map();


    bool loadFromFile(const std::string& tmxPath, const std::string& tilesetPath, int tileWidth, int tileHeight);


    void draw(sf::RenderWindow& window) const;

private:
    struct TileLayer {
        std::string name;
        std::vector<unsigned> gids;
        int width;
        int height;
    };

    std::vector<TileLayer> layers;
    sf::Texture tileset;

    int tileWidth;
    int tileHeight;
};


#endif // THE_FLOOR_IS_LAVA_MAP_H
