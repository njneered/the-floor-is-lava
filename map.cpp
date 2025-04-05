//
// Created by Nj on 4/5/2025.
//

#include "Map.h"
#include <tinyxml2.h>
#include <sstream>
#include <iostream>

using namespace tinyxml2;

Map::Map() : tileWidth(32), tileHeight(16) {}

bool Map::loadFromFile(const std::string& tmxPath, const std::string& tilesetPath, int tw, int th) {
    tileWidth = tw;
    tileHeight = th;

    // Load the tileset texture
    if (!tileset.loadFromFile(tilesetPath)) {
        std::cerr << "Failed to load tileset image: " << tilesetPath << "\n";
        return false;
    }

    XMLDocument doc;
    if (doc.LoadFile(tmxPath.c_str()) != XML_SUCCESS) {
        std::cerr << "Failed to load TMX map file: " << tmxPath << "\n";
        return false;
    }

    XMLElement* mapElement = doc.FirstChildElement("map");
    if (!mapElement) {
        std::cerr << "No <map> element found.\n";
        return false;
    }

    int width = mapElement->IntAttribute("width");
    int height = mapElement->IntAttribute("height");

    for (XMLElement* layerElem = mapElement->FirstChildElement("layer");
         layerElem != nullptr;
         layerElem = layerElem->NextSiblingElement("layer")) {

        const char* layerName = layerElem->Attribute("name");
        XMLElement* dataElem = layerElem->FirstChildElement("data");

        if (!dataElem || !dataElem->GetText()) {
            std::cerr << "Skipping layer with no data.\n";
            continue;
        }

        std::vector<unsigned> gids;
        std::stringstream ss(dataElem->GetText());
        std::string token;

        while (std::getline(ss, token, ',')) {
            token.erase(0, token.find_first_not_of(" \n\r\t"));
            token.erase(token.find_last_not_of(" \n\r\t") + 1);

            if (!token.empty()) {
                try {
                    gids.push_back(static_cast<unsigned>(std::stoi(token)));
                } catch (...) {
                    gids.push_back(0);
                }
            }
        }

        TileLayer layer;
        layer.name = (layerName != nullptr) ? layerName : "Unnamed";
        layer.gids = gids;
        layer.width = width;
        layer.height = height;

        layers.push_back(layer);
    }

    return true;
}

void Map::draw(sf::RenderWindow& window) const {
    sf::Sprite sprite;
    sprite.setTexture(tileset);

    int tilesPerRow = tileset.getSize().x / tileWidth;

    for (const auto& layer : layers) {
        for (int y = 0; y < layer.height; ++y) {
            for (int x = 0; x < layer.width; ++x) {
                int index = x + y * layer.width;
                unsigned gid = layer.gids[index];

                if (gid == 0) continue;

                int tx = (gid - 1) % tilesPerRow;
                int ty = (gid - 1) / tilesPerRow;

                sprite.setTextureRect(sf::IntRect(
                    tx * tileWidth,
                    ty * tileHeight,
                    tileWidth,
                    tileHeight
                ));

                float isoX = static_cast<float>((x - y) * (tileWidth / 2));
                float isoY = static_cast<float>((x + y) * (tileHeight / 2));

                sprite.setPosition(isoX, isoY);
                window.draw(sprite);
            }
        }
    }
}