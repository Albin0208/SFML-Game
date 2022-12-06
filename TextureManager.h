//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_TEXTUREMANAGER_H
#define TDP005_TEXTUREMANAGER_H

#include <map>
#include "common.h"

class TextureManager {
public:
    static sf::Texture* get(std::string const& name);
private:
    TextureManager() = default;

    static TextureManager instance;

    std::map<std::string, std::unique_ptr<sf::Texture>> textures;
};


#endif //TDP005_TEXTUREMANAGER_H
