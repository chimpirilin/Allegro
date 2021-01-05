#include "graficarpoligono.h"

using namespace std;

GraficarPoligono::GraficarPoligono()
{
}

GraficarPoligono::~GraficarPoligono()
{
}

void GraficarPoligono::setPosX(float x)
{
	posX.push_back(x);
}

void GraficarPoligono::setPosY(float y)
{
	posY.push_back(y);
}

void GraficarPoligono::graficar() const
{
	if (posX.size() >= 3)
	{			
		for (auto i = 0; i < posX.size() - 1; ++i)
		{	
			al_draw_line(posX[i], posY[i], posX[i + 1], posY[i + 1], al_map_rgb(255, 255, 255), 2);
			al_draw_line(posX.back(), posY.back(), posX.front(), posY.front(), al_map_rgb(255, 255, 255), 2);	
			
			al_draw_filled_circle(posX[i + 1], posY[i + 1], 3, al_map_rgb(25, 255, 5));
			al_draw_filled_circle(posX.back(), posY.back(), 3, al_map_rgb(236, 36, 36));									
		}
		al_draw_filled_circle(posX[0], posY[0], 3, al_map_rgb(236, 36, 36));		
	}
}

void GraficarPoligono::triangular()
{
	if (posX.size() >= 3)
	for (auto j = 2; j < posX.size() - 1; ++j)
		al_draw_line(posX[0], posY[0], posX[j], posY[j], al_map_rgb(0, 255, 255), 1);
}

void GraficarPoligono::borrar() 
{
	if (posX.size() > 3)
	{
		posX.pop_back();
		posY.pop_back();
	}

}

void GraficarPoligono::limpiar()
{
	posX.clear();
	posY.clear();
}
