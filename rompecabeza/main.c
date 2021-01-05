/*Rompecabezas hecho por Hans. Ingenieria en computacion - UNI*/
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main() 
{	
	struct positions
	{
		float x;
		float y;
	};	
	
	char *mensaje[]=
    {
		"Cargando graficos", "Cargando interfaz", "Generando estructura",
    	"Cargando datos", "Entrando a modo protegido", "Inicializando mouse",
		"Calculando dimensiones", "Generando coordenadas", "Registrando sesion",
		"Proteccion del sistema", "Cargando capa externa"
    };
    
    
	const int totalImagenes = 10;
	int FPS = 60;
	const int width = 740;
	const int height = 665;
	const int tamX = 180;
	const int tamY = 140;
	int mouseX, mouseY;
	int salir = 0, salir2 = 0, gameOver = 0, i;
	int  jj = 150, k = 185, l, barra = 0;
	float temp1, temp2;
    
	float rightPos[totalImagenes][2] = 
	{
		100, 100,
		280, 100,
		460, 100,
		100, 240,
		280, 240,
		460, 240,
		100, 380,
		280, 380,
		460, 380,
		280, 520
	};
	
	struct positions currentPos[totalImagenes];
		
	ALLEGRO_BITMAP *imagenes[totalImagenes];
	ALLEGRO_BITMAP *fondos[4], *autores;
	ALLEGRO_BITMAP *cursor;
	ALLEGRO_BITMAP *fondo;
	ALLEGRO_BITMAP *pedazo;
	ALLEGRO_DISPLAY *pantalla;
	ALLEGRO_FONT *fuente, *fuente2;
	ALLEGRO_EVENT_QUEUE *evento;
	ALLEGRO_EVENT tipoDeEvento;	
	ALLEGRO_TIMER *timer1;
	ALLEGRO_COLOR colores[11];
	
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
		
	al_install_keyboard();
	al_install_mouse();
	
	pantalla = al_create_display(width, height);
	fuente = al_load_font("fuente.ttf", 20, 0);
	fuente2 = al_load_font("fuente.ttf", 50, 0);
	timer1 = al_create_timer(1.0 / FPS);
	evento = al_create_event_queue();
	al_register_event_source(evento, al_get_mouse_event_source());
	al_register_event_source(evento, al_get_keyboard_event_source());
	al_register_event_source(evento, al_get_display_event_source(pantalla));
	al_register_event_source(evento, al_get_timer_event_source(timer1));
	
	colores[0] = al_map_rgb(121, 174, 253);
	colores[1] = al_map_rgb(100, 162, 253);
	colores[2] = al_map_rgb(73, 145, 252);
	colores[3] = al_map_rgb(44, 126, 252);
	colores[4] = al_map_rgb(12, 107, 252);
	colores[5] = al_map_rgb(3, 95, 231);
	colores[6] = al_map_rgb(3, 86, 209);
	colores[7] = al_map_rgb(3, 78, 188);
	colores[8] = al_map_rgb(2, 64, 155);
	colores[9] = al_map_rgb(1, 36, 156);
	colores[10] = al_map_rgb(17, 1, 156);
	
	imagenes[0] = al_load_bitmap("pieza1.png");
	imagenes[1] = al_load_bitmap("pieza2.png");
	imagenes[2] = al_load_bitmap("pieza3.png");
	imagenes[3] = al_load_bitmap("pieza4.png");
	imagenes[4] = al_load_bitmap("pieza5.png");
	imagenes[5] = al_load_bitmap("pieza6.png");
	imagenes[6] = al_load_bitmap("pieza7.png");
	imagenes[7] = al_load_bitmap("pieza8.png");
	imagenes[8] = al_load_bitmap("pieza9.png");
	imagenes[9] = al_load_bitmap("vacio.png");
	
	fondos[0] = al_load_bitmap("fondo1.png");
	fondos[1] = al_load_bitmap("fondo2.png");
	fondos[2] = al_load_bitmap("fondo3.png");
	fondos[3] = al_load_bitmap("fondo4.png");
	autores = al_load_bitmap("autores.png");
	cursor = al_load_bitmap("cursor.png");
	fondo = al_load_bitmap("fondo.png");
	pedazo = al_load_bitmap("pedazo.png");
	al_convert_mask_to_alpha(cursor, al_map_rgb(0, 0, 0));
	
	currentPos[0].x = 100;
	currentPos[0].y = 380;
	currentPos[1].x = 460;
	currentPos[1].y = 100;
	currentPos[2].x = 460;
	currentPos[2].y = 240;
	currentPos[3].x = 100;
	currentPos[3].y = 100;
	currentPos[4].x = 280;
	currentPos[4].y = 380;
	currentPos[5].x = 460;
	currentPos[5].y = 380;
	currentPos[6].x = 280;
	currentPos[6].y = 100;
	currentPos[7].x = 280;
	currentPos[7].y = 520;
	currentPos[8].x = 100;
	currentPos[8].y = 240;
	currentPos[9].x = 280;
	currentPos[9].y = 240;
	
	al_hide_mouse_cursor(pantalla);
	while (!salir2)
	{		
		al_wait_for_event(evento, &tipoDeEvento);
		if (tipoDeEvento.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			mouseX = tipoDeEvento.mouse.x;
			mouseY = tipoDeEvento.mouse.y;
		}
		
		if (tipoDeEvento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			salir2 = 1;
			salir = 1;
		}
		
		if (mouseX >= 274 && mouseX <= 437 && mouseY >= 218 && mouseY <= 263)
		{
			al_draw_bitmap(fondos[1], 0, 0, 0);
			al_flip_display();
			if (tipoDeEvento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (tipoDeEvento.mouse.button & 1)
				{
					salir2 = 1;
					barra = 1;
				}
			}
		}
		else if (mouseX >= 121 && mouseX <= 671 && mouseY >= 286 && mouseY <= 328)
		{
			al_draw_bitmap(fondos[2], 0, 0, 0);
			al_flip_display();
			if (tipoDeEvento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (tipoDeEvento.mouse.button & 1)
				{
					al_draw_bitmap(autores, 0, 0, 0);
					al_flip_display();
					al_rest(5);
				}
			}
		}
		else if (mouseX >= 272 && mouseX <= 671 && mouseY >= 345 && mouseY <= 385)
		{
			al_draw_bitmap(fondos[3], 0, 0, 0);
			al_flip_display();
			if (tipoDeEvento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (tipoDeEvento.mouse.button & 1)
				{
					salir2 = 1;
					salir = 1;
				}
			}
		}
		else
		{
			al_draw_bitmap(fondos[0], 0, 0, 0);
			al_flip_display();			
		}
		al_draw_bitmap(cursor, mouseX, mouseY, 0);
		al_flip_display();
	}
	
	if (barra)
	{
		fondo = al_load_bitmap("fondo.png");
    		al_draw_bitmap(fondo, 0, 0, 0);
	    al_flip_display();
	    	
		for (i = 0; i < 11; i++)
    	{
       		for (; jj <= k; jj++)
	       	{
    	   		al_draw_line(jj, 195, jj, 185, colores[i], 1);
       			al_rest(0.03);
       			al_flip_display();
	       	}
    	   	al_draw_text(fuente, al_map_rgb(245, 198, 0), 200, 215 + (i * 22), 0, mensaje[i]);
       		for (l = 410; l < 446; l += 3)
	       	{
    	   		al_draw_text(fuente, al_map_rgb(245, 198, 0), l, 215 + (i * 22), 0, ". ");	
       			al_flip_display();
       			al_rest(0.03);
	       	}
    	   	al_draw_text(fuente, al_map_rgb(245, 198, 0), 450, 215 + (i * 22), 0, "Listo");	
	       	al_flip_display();
    	   	if (i != 10)
       		{
       			al_draw_filled_rectangle(150, 185, k, 195, colores[i + 1]);
	       		al_flip_display();	
    	   	}
       		k += 35;
       	}
	    al_rest(1);
    }
    
	al_start_timer(timer1);
	while(!salir && !gameOver)
	{
		
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_wait_for_event(evento, &tipoDeEvento);
		
		if (tipoDeEvento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			salir = 1;
		
	   else if (tipoDeEvento.type == ALLEGRO_EVENT_KEY_DOWN)
			if (tipoDeEvento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				salir = 1;
		
	    if (tipoDeEvento.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			mouseX = tipoDeEvento.mouse.x;
			mouseY = tipoDeEvento.mouse.y;
		}
		
		else if (tipoDeEvento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (tipoDeEvento.mouse.button & 1)
			{
				for (i = 0; i < totalImagenes; i++)
				{
					if ((currentPos[9].x + tamX == currentPos[i].x && currentPos[9].y == currentPos[i].y) || 
						(currentPos[9].x - tamX == currentPos[i].x && currentPos[9].y == currentPos[i].y) ||
						(currentPos[9].y + tamY == currentPos[i].y && currentPos[9].x == currentPos[i].x) ||
						(currentPos[9].y - tamY == currentPos[i].y && currentPos[9].x == currentPos[i].x))
					{
						if (mouseX >= currentPos[i].x && mouseX <= currentPos[i].x + tamX
							&& mouseY >= currentPos[i].y && mouseY <= currentPos[i].y + tamY)
						{
							temp1 = currentPos[i].x;
							temp2 = currentPos[i].y;
							currentPos[i].x = currentPos[9].x;
							currentPos[i].y = currentPos[9].y;
							currentPos[9].x = temp1;
							currentPos[9].y = temp2;							
							break;
						}
					}
				}					
			}
		}
		
		
		if (tipoDeEvento.type == ALLEGRO_EVENT_TIMER)
		{
			al_draw_bitmap(fondo, 0, 0, 0);
			al_draw_text(fuente2, al_map_rgb(255, 198, 0), width / 2, 0, ALLEGRO_ALIGN_CENTRE, "ROMPECABEZAS");
			al_draw_bitmap(imagenes[0], currentPos[0].x, currentPos[0].y, 0);
			al_draw_bitmap(imagenes[1], currentPos[1].x, currentPos[1].y, 0);
			al_draw_bitmap(imagenes[2], currentPos[2].x, currentPos[2].y, 0);
			al_draw_bitmap(imagenes[3], currentPos[3].x, currentPos[3].y, 0);
			al_draw_bitmap(imagenes[4], currentPos[4].x, currentPos[4].y, 0);
			al_draw_bitmap(imagenes[5], currentPos[5].x, currentPos[5].y, 0);
			al_draw_bitmap(imagenes[6], currentPos[6].x, currentPos[6].y, 0);
			al_draw_bitmap(imagenes[7], currentPos[7].x, currentPos[7].y, 0);
			al_draw_bitmap(imagenes[8], currentPos[8].x, currentPos[8].y, 0);
			al_draw_bitmap(imagenes[9], currentPos[9].x, currentPos[9].y, 0);
			al_draw_bitmap(cursor, mouseX, mouseY, 0);
			al_flip_display();
			
			for (i = 0; i < totalImagenes; i++)
			{
				if (currentPos[i].x == rightPos[i][0] && currentPos[i].y == rightPos[i][1])
				{
					gameOver = 1;
				}
				else
				{
					gameOver = 0;
					break;
				}
			}
				
		}
	}
	
	if (gameOver)
	{	
		al_draw_bitmap(pedazo, 280, 520, 0);
		al_flip_display();
		al_rest(3);
		al_clear_to_color(al_map_rgb(0, 0, 0));		
		al_draw_bitmap(fondo, 0, 0, 0);
		al_draw_text(fuente2, al_map_rgb(255, 198, 0), width / 2, height / 2, ALLEGRO_ALIGN_CENTRE, "Felicidades, has ganado!");
		al_flip_display();
		al_rest(5);
	}
	
	al_destroy_event_queue(evento);
	al_destroy_display(pantalla);
	for (i = 0; i < totalImagenes; i++)
		al_destroy_bitmap(imagenes[i]);
	for (i = 0; i < 4; i++)
		al_destroy_bitmap(fondos[i]);
	al_destroy_bitmap(fondo);
	al_destroy_bitmap(pedazo);
	al_destroy_bitmap(cursor);
	al_destroy_bitmap(autores);
	al_destroy_font(fuente);
	al_destroy_font(fuente2);
	al_destroy_timer(timer1);
    return 0;
}
