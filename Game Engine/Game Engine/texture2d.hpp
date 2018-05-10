#ifndef _TEXTURE2D_HPP_
#define _TEXTURE2D_HPP_

#include <string>
#include "texturebase.hpp"

class Texture2D : public Texture
{
public:
	Texture2D();
	virtual ~Texture2D();

	virtual void loadTexture(std::string &filepath);
};

#endif // !_TEXTURE2D_HPP_