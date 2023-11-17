#include "AssetManager.h"

AssetManager *AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
    assert(sInstance == nullptr);
    sInstance = this;
}

sf::Font &AssetManager::GetFont(std::string const &file_name)
{
    auto &fontMap = sInstance->m_fonts;

    auto finded = fontMap.find(file_name);

    if (finded != fontMap.end())
    {
        return finded->second;
    }
    else
    {
        fontMap[file_name] = sf::Font();
        auto &font = fontMap[file_name];
        font.loadFromFile(file_name);
        return font;
    }
}