//
// Created by Nj on 4/5/2025.
//

#include "Map.h"
#include <sstream>


using namespace tinyxml2;
using namespace std;


Map::Map() : tileWidth(32), tileHeight(16) {}


bool Map::loadFromFile(const std::string& tmxFilePath, int tw, int th) {
   tileWidth = tw;
   tileHeight = th;


   XMLDocument doc;
   if (doc.LoadFile(tmxFilePath.c_str()) != XML_SUCCESS) {
       cerr << "Failed to load TMX map file: " << tmxFilePath << "\n";
       return false;
   }


   XMLElement* mapElement = doc.FirstChildElement("map");
   if (mapElement == nullptr) {
       cerr << "No <map> element found.\n";
       return false;
   }


   int width = mapElement->IntAttribute("width");
   int height = mapElement->IntAttribute("height");


   if (!parseTilesets(mapElement)) return false;
   if (!parseLayers(mapElement, width, height)) return false;


   return true;
}


bool Map::parseTilesets(XMLElement* mapElement) {
   for (XMLElement* tilesetElem = mapElement->FirstChildElement("tileset");
        tilesetElem != nullptr;
        tilesetElem = tilesetElem->NextSiblingElement("tileset")) {


       int firstGID = tilesetElem->IntAttribute("firstgid");


       for (XMLElement* tileElem = tilesetElem->FirstChildElement("tile");
            tileElem != nullptr;
            tileElem = tileElem->NextSiblingElement("tile")) {


           int localID = tileElem->IntAttribute("id");
           int globalID = firstGID + localID;


           XMLElement* imageElem = tileElem->FirstChildElement("image");
           if (imageElem == nullptr) continue;


           const char* imagePath = imageElem->Attribute("source");
           if (imagePath == nullptr) continue;


           std::string fullPath = "sprites/" + std::string(imagePath);


           sf::Texture texture;
           if (!texture.loadFromFile(fullPath)) {
               cerr << "Failed to load tile image: " << fullPath << "\n";
               continue;
           }


           tileTextures[globalID] = texture;


           sf::Sprite sprite;
           sprite.setTexture(tileTextures[globalID]);
           tileSprites[globalID] = sprite;
       }
   }


   return true;
}


bool Map::parseLayers(XMLElement* mapElement, int width, int height) {
   for (XMLElement* layerElem = mapElement->FirstChildElement("layer");
        layerElem != nullptr;
        layerElem = layerElem->NextSiblingElement("layer")) {


       // Skip invisible layers (e.g. debugging, placeholders)
       bool visible = layerElem->BoolAttribute("visible", true);
       if (!visible) continue;


       const char* layerName = layerElem->Attribute("name");
       XMLElement* dataElem = layerElem->FirstChildElement("data");


       if (dataElem == nullptr || dataElem->GetText() == nullptr) {
           cerr << "Skipping layer with no data.\n";
           continue;
       }


       std::vector<unsigned> tileIDs;
       std::stringstream ss(dataElem->GetText());
       std::string token;


       while (std::getline(ss, token, ',')) {
           token.erase(0, token.find_first_not_of(" \n\r\t"));
           token.erase(token.find_last_not_of(" \n\r\t") + 1);


           if (!token.empty()) {
               try {
                   unsigned value = static_cast<unsigned>(stoi(token));
                   tileIDs.push_back(value);
               } catch (const invalid_argument& e) {
                   cerr << "Invalid tile ID: \"" << token << "\" (not a number)\n";
               } catch (const out_of_range& e) {
                   cerr << "Tile ID out of range: \"" << token << "\"\n";
               }
           }
       }


       TileLayer layer;
       layer.name = layerName ? layerName : "Unnamed";
       layer.tileIDs = tileIDs;
       layer.width = width;
       layer.height = height;


       cout << "Loaded layer \"" << layer.name << "\" with "
            << tileIDs.size() << " tiles (" << width << "x" << height
            << " = " << (width * height) << " expected)" << endl;


       layers.push_back(layer);
   }


   return true;
}


void Map::draw(sf::RenderWindow& window) const {
   for (const auto& layer : layers) {
       for (int y = 0; y < layer.height; ++y) {
           for (int x = 0; x < layer.width; ++x) {
               int index = x + y * layer.width;


               // ✅ Prevent crashes from bad tile data
               if (index >= layer.tileIDs.size()) continue;


               unsigned tileID = layer.tileIDs[index];
               if (tileID == 0) continue;


               if (tileSprites.find(tileID) == tileSprites.end()) {
                   std::cerr << "Missing sprite for tileID: " << tileID << "\n";
                   continue;
               }


               sf::Sprite sprite = tileSprites.at(tileID);


               float isoX = static_cast<float>((x - y) * (tileWidth / 2));
               float isoY = static_cast<float>((x + y) * (tileHeight / 2));


               sprite.setPosition(isoX, isoY);
               window.draw(sprite);
           }
       }
   }
}


int Map::getWidth() const {
   return layers.empty() ? 0 : layers[0].width;
}


int Map::getHeight() const {
   return layers.empty() ? 0 : layers[0].height;
}
