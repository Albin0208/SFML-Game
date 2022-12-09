//
// Created by albin on 2022-12-05.
//

#include "Texture_Manager.h"

sf::Texture* Texture_Manager::get(std::string const& name) {
    auto found = instance.textures.find(name);
    if (found != instance.textures.end())
        return found->second.get();

    sf::Texture* t{new sf::Texture()};
    if (!t->loadFromFile("../resources/textures/" + name))
        throw std::logic_error("Failed to load texture!");

    instance.textures.insert(std::make_pair(name, std::unique_ptr<sf::Texture>(t)));
    return t;

}

Texture_Manager Texture_Manager::instance;