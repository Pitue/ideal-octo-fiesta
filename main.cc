#include <iostream>
#include <string>
#include <fstream>

#include <ctime>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>


#include "SDL_Utility/include.h"

#define ERROR_LOG_FILE "error_log.txt"

bool Init();
void Quit();
void ErrorHandle(std::string message);
std::string GetTimeString();

int main(int argc, char** argv) {
	if (!Init()) {
		ErrorHandle(SDL_GetError());
		return 1;
	}
	
	mh::SDL_Container container("test", mh::Rect(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900),
															SDL_INIT_VIDEO, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	Quit();
	return 0;
}

bool Init() {
	bool error = true;
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		int img_flags = IMG_INIT_PNG;
		if (IMG_Init(img_flags) == img_flags) {
			int mixer_flags = MIX_INIT_MP3 | MIX_INIT_FLAC;
			if (Mix_Init(mixer_flags) == mixer_flags) {
				if (TTF_Init() == 0) {
					error = false;
				}
			}
		}
	}
	return !error;
}
void Quit() {
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}
void ErrorHandle(std::string message) {
	static std::fstream file_stream;
	if (!file_stream.is_open()) {
		file_stream.open(ERROR_LOG_FILE, std::ios::out | std::ios::app);
	}
	if (file_stream.is_open()) {
		file_stream << message << " um " << GetTimeString() << std::endl;
		file_stream.close();
	}
}
std::string GetTimeString() {
	std::time_t sec = 0;
	char str[128];

	std::time(&sec);

#ifndef _MSC_VER
	std::tm* time = NULL;
	time = std::localtime(&sec);
#else
	std::tm time;
	localtime_s(&time, &sec);
#endif

	std::strftime(str, sizeof str, "%T %d/%m/%Y", &time);
	
	return str;
}