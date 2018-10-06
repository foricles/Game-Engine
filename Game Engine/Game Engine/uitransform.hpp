#ifndef _UITANSFORM_HPP_
#define _UITANSFORM_HPP_

#include <vec2.hpp>
#include <point.hpp>
#include "transform.h"

class UITransform : public Transform
{
private:
	float oWeight;
	float oHeight;
public:
	UITransform();
	UITransform(float w, float h);

	virtual ~UITransform();

	float getWeight() const;
	float getHeight() const;

	float getNormalizedWeight() const;
	float getNormalizedHeight() const;

	const kmu::vec2 &getMinPoint() const;
	const kmu::vec2 &getMaxPoint() const;

	const kmu::vec2 &getNormalizedMinPoint() const;
	const kmu::vec2 &getNormalizedMaxPoint() const;
};

#endif // !_UITANSFORM_HPP_