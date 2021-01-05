#ifndef GRAFICARPOLIGONO_H
#define GRAFICARPOLIGONO_H

#include <vector>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

using namespace std;

class GraficarPoligono
{
	public:
		GraficarPoligono();
		~GraficarPoligono();
		void graficar() const;
		void borrar();
		void limpiar();

		void setPosX(float);
		void setPosY(float);
		
 		void triangular();
	private:
		vector <float> posX;
		vector <float> posY;
};

#endif
