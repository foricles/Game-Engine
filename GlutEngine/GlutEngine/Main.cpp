#include "mesh.h"
#include "meshloader.h"
#include "transform.h"

#include <iostream>

int main(int argc, char **argv)
{
	MeshLoader loader;
	loader.load("C:\\Users\\foricles\\Desktop\\Cathedral.FBX");

	system("pause");
	return 0;
}