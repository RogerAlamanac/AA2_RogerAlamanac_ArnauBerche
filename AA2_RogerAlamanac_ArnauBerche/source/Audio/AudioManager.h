#pragma once
#include "SDL_mixer.h"
#include <unordered_map>
#include <string>
#include <cassert>

#define AM AudioManager::GetInstance()

class AudioManager
{
private:
	std::unordered_map<std::string, Mix_Chunk*> _clips;
	std::unordered_map<std::string, Mix_Music*> _songs;

	bool _muted = false;

	AudioManager() 
	{
		int result = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

		bool succes = result >= 0;

		if (!succes)
			throw SDL_GetError();
	}

	AudioManager(const AudioManager&) = delete;
	AudioManager& operator = (const AudioManager&) = delete;

public:
	inline static AudioManager& GetInstance() 
	{
		static AudioManager am;
		return am;
	}

	inline void LoadClip(std::string name) 
	{
		assert(_clips.find(name) == _clips.end());

		Mix_Chunk* loadChunck = Mix_LoadWAV(("resources/audio/sfx/" + name + ".wav").c_str());

		assert(loadChunck != nullptr);

		_clips.emplace(name, loadChunck);

	}

	inline void LoadSong(std::string name) 
	{
		assert(_songs.find(name) == _songs.end());

		Mix_Music* loadedMusic = Mix_LoadMUS(("resources/audio/music/" + name + ".mp3").c_str());
	
		assert(loadedMusic != nullptr);

		_songs.emplace(name, loadedMusic);
	}

	inline void PlayClip(std::string name, int repetitions) 
	{
		assert(_clips.find(name) != _clips.end());

		Mix_PlayChannel(-1, _clips[name], repetitions);
	}

	inline void PlaySong(std::string name) 
	{
		assert(_songs.find(name) != _songs.end());
		
		Mix_FadeInMusic(_songs[name], -1, 200);
	}

	inline void Mute() 
	{
		_muted = true;
	}

	inline void UnMute() 
	{
		_muted = false;
	}

	inline bool GetMuted() { return _muted; }

	inline void StopAudio() 
	{
		Mix_HaltMusic();
		Mix_HaltChannel(-1);
	}


};

