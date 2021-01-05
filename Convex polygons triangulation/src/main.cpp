#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include "graficarpoligono.h"

int main()
{			
	GraficarPoligono Graficar;

	bool terminar{};
	bool dibujar{};
	
	float mouseX{};
	float mouseY{};

	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_FONT *font;
	ALLEGRO_EVENT_QUEUE *evento;
	ALLEGRO_EVENT e;
	
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	
	al_install_mouse();
	al_install_keyboard();
	
	display = al_create_display(640, 480);
	evento = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	font = al_load_font("arial.ttf", 15, 0);
	
	al_register_event_source(evento, al_get_timer_event_source(timer));
	al_register_event_source(evento, al_get_mouse_event_source());
	al_register_event_source(evento, al_get_display_event_source(display));
	al_register_event_source(evento, al_get_keyboard_event_source());

	al_start_timer(timer);
	while (!terminar)
	{
		al_wait_for_event(evento, &e);
		
		if (e.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (e.mouse.button & 1)
			{
				Graficar.setPosX(e.mouse.x);
				Graficar.setPosY(e.mouse.y);
			}
			
			else if (e.mouse.button & 2)
			{
				Graficar.borrar();
			}
		}
		
		else if (e.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				Graficar.limpiar();
			}
		}
		
		else if (e.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			mouseX = e.mouse.x;
			mouseY = e.mouse.y;
		}
		
		
		else if (e.type == ALLEGRO_EVENT_TIMER)
		{
			dibujar = true;
		}				
		
		else if (e.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			terminar = true;
		}		
		
		if (dibujar && al_is_event_queue_empty(evento))
		{
			Graficar.triangular();
			Graficar.graficar();	

			al_draw_textf(font, al_map_rgb(255, 255, 255), 590, 450, 0, "x = %0.f", mouseX);	
			al_draw_textf(font, al_map_rgb(255, 255, 255), 590, 463, 0, "y = %0.f", mouseY);						
		}
				
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));	
	}
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(evento);
	
	return 0;
}

