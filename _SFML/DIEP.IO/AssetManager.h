#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <assert.h>
// Audio

class AssetManager
{

public:
    AssetManager();

    // Getters
    static sf::Font &GetFont(std::string const &file_name);
    // Texture
    // SoundBuffer

private:
    std::map<std::string, sf::Font> m_fonts;
    // Textures
    // Sounds

    static AssetManager *sInstance;
};