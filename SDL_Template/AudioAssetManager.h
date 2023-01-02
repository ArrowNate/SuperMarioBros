#pragma once
#ifndef AUDIO_ASSETMANAGER_H
#define AUDIO_ASSETMANAGER_H

#include <SDL_mixer.h>
#include <string>
#include <map>

class AudioAssetManager
{
public:
    AudioAssetManager();
    ~AudioAssetManager();

    bool Load(const std::string& path, const std::string& name);
    void Unload(const std::string& name);
    Mix_Chunk* Get(const std::string& name) const;

private:
    std::map<std::string, Mix_Chunk*> m_Audios;
};

#endif