//
// Created by albin on 2022-12-05.
//

#ifndef TDP005_TEXTURE_MANAGER_H
#define TDP005_TEXTURE_MANAGER_H

#include <map>
#include "common.h"

class Texture_Manager {
public:
    static sf::Texture* get(std::string const& name);
private:
    Texture_Manager() = default;

    static Texture_Manager instance;

    std::map<std::string, std::unique_ptr<sf::Texture>> textures;
};


#endif //TDP005_TEXTURE_MANAGER_H
