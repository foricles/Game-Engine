#include "GlutEngine.h"
#include <time.h>
#include <iostream>


using std::cout;
using std::endl;

UI *edit1;
UI *edit2;
UI *edit3;

void Initialize()
{
	Settings::Antialissing = false;
}

void Start()
{
	edit1 = new UI("edit1");
	edit1->setWidth(Settings::Window_Widght);
	edit1->setBackgroundColor(Colors::SoftBlue());
	Render::Add(edit1);

	edit2 = new UI("edit2");
	edit2->setPosition(0, 200);
	edit2->setWidth(Settings::Window_Widght/3);
	edit2->setBackgroundColor(Colors::SoftBlue());
	Render::Add(edit2);

	edit3 = new UI("edit3");
	edit3->setPosition(0, 400);
	edit3->setWidth(Settings::Window_Widght/3);
	edit3->setBackgroundColor(Colors::SoftBlue());
	Render::Add(edit3);
}

void Update()
{	

}

void End()
{
	
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	GlutEngine = new Engine(&argc, argv, Initialize);

	GlutEngine->SetAwakeFunk   ( Start );
	GlutEngine->SetRunableFunc ( Update);
	GlutEngine->SetShutDownFunc( End   );

	if (!GlutEngine->GetEngine())
	{
		delete GlutEngine;
		return 1;
	}

	delete GlutEngine;
	
	return 0;
}