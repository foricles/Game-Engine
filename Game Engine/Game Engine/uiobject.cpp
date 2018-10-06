#include "uiobject.hpp"



UIObject::UIObject()
{
}


UIObject::~UIObject()
{
}

inline MeshData UIObject::getRenderData() const
{
	MeshData renderData;

	renderData.oVertexes.resize(4);
	renderData.oIndexes.resize(6);

	auto pMin = getNormalizedMinPoint();
	auto pMax = getNormalizedMaxPoint();
	auto oW = getNormalizedWeight();
	auto oH = getNormalizedHeight();

	renderData.oVertexes[0].pPos.x = pMin.x;
	renderData.oVertexes[0].pPos.y = pMin.y;
	renderData.oVertexes[0].pNor = VEC3_FRONT;
	renderData.oVertexes[0].pUV = kmu::vec2(0.0f, 0.0f);
	renderData.oVertexes[0].pCol = kmu::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	renderData.oVertexes[1].pPos.x = pMin.x;
	renderData.oVertexes[1].pPos.y = pMax.y;
	renderData.oVertexes[1].pNor = VEC3_FRONT;
	renderData.oVertexes[1].pUV = kmu::vec2(0.0f, 1.0f);
	renderData.oVertexes[1].pCol = kmu::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	renderData.oVertexes[2].pPos.x = pMax.x;
	renderData.oVertexes[2].pPos.y = pMax.y;
	renderData.oVertexes[2].pNor = VEC3_FRONT;
	renderData.oVertexes[2].pUV = kmu::vec2(1.0f, 1.0f);
	renderData.oVertexes[2].pCol = kmu::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	renderData.oVertexes[3].pPos.x = pMax.x;
	renderData.oVertexes[3].pPos.y = pMin.y;
	renderData.oVertexes[3].pNor = VEC3_FRONT;
	renderData.oVertexes[3].pUV = kmu::vec2(1.0f, 0.0f);
	renderData.oVertexes[3].pCol = kmu::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	renderData.oIndexes[0] = 0;
	renderData.oIndexes[1] = 1;
	renderData.oIndexes[2] = 2;
	renderData.oIndexes[3] = 0;
	renderData.oIndexes[4] = 0;
	renderData.oIndexes[5] = 0;

	return renderData;
}
