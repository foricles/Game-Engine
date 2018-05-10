#ifndef _CUBEMAP_HPP_
#define _CUBEMAP_HPP_

#include "texturebase.hpp"

class CubeMap : public Texture
{
public:
	CubeMap();
	virtual ~CubeMap();

	void begin();
	void end();

	void loadPosiX(const std::string &filePath);
	void loadNegaX(const std::string &filePath);

	void loadPosiY(const std::string &filePath);
	void loadNegaY(const std::string &filePath);

	void loadPosiZ(const std::string &filePath);
	void loadNegaZ(const std::string &filePath);

private:
	void loadCubeSide(const std::string &path, GLenum side);
};



#endif // !_CUBEMAP_HPP_
