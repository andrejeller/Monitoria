//Codigo escrito por Andr� Jeller
#pragma once
#include "ofMain.h"

class Nave {

public:

	ofImage m_sprite; //Sprite da Nave
	ofVec2f m_pos, distancia; //Vetore de Posi��o e distancia entre clique do mouse e posicao atual
	float m_vel; //Velocidade de movimenta��o

	//Cosntrutor 
	Nave(string spriteName, float vel, ofVec2f pos);
	
	//Rotaciona o Astro em torno de um outro pr� estabelecido.
	void update(ofVec2f mouse);

	//Desenha a nave com base na posi��o da camera
	void draw(ofVec2f camera);

};
