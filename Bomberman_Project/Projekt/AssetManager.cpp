#include "AssetManager.h"
#include <windows.h>

void AssetManager::LoadTexture(std::string name, std::string file_name)
{
	sf::Texture tex;	

	if (tex.loadFromFile(file_name))	
		_texture[name] = tex;		
	else							
	{
		int _msgBox = MessageBox(NULL, "Failed to load texture! Exiting application", "Fatal Error", MB_OK | MB_ICONERROR);	

		if (_msgBox == IDOK)
			_closeWindow = true;
	}
}

sf::Texture & AssetManager::getTexture(std::string name)
{
	if (_texture.find(name) != _texture.end())	
		return _texture.at(name);
}

void AssetManager::LoadFont(std::string name, std::string file_name)	
{
	sf::Font fon;

	if (fon.loadFromFile(file_name))
		_font[name] = fon;
	else
	{
		int _msgBox = MessageBox(NULL, "Failed to load font! Exiting application", "Fatal Error", MB_OK | MB_ICONERROR);

		if (_msgBox == IDOK)
			_closeWindow = true;
	}
}

sf::Font & AssetManager::getFont(std::string name)	
{
	if(_font.find(name) != _font.end())
		return _font.at(name);
}