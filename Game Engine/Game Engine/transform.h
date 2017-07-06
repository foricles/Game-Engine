#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include <vectors.h>
#include <matrices.h>

class Transform
{
public:
	Transform();
	~Transform();

	kmu::mat4 transMatrix();
//-----------inline geter/seter------------------------------------------------------------
	void position(const kmu::vec3 &pos) { oPos = pos; }
	void scaling(const kmu::vec3 &scl) { oScl = scl; }
	void rotation(const kmu::quaternion &rot) { oRot = rot; }

	void position(float X, float Y, float Z) { oPos = kmu::vec3(X, Y, Z); }
	void scaling(float X, float Y, float Z) { oScl = kmu::vec3(X, Y, Z); }

	const kmu::vec3 & position() { return oPos; }
	const kmu::vec3 & scaling() { return oScl; }
	const kmu::quaternion &rotation() { return oRot; }
private:
	kmu::vec3 oPos;
	kmu::vec3 oScl;
	kmu::quaternion oRot;
};

#endif // !_TRANSFORM_H_