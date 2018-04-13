//Codigo escrito por André Jeller
#pragma once
#include "ofMain.h"

class Nave {

public:

	ofImage m_sprite; //Sprite da Nave
	ofVec2f m_pos, distancia; //Vetore de Posição e distancia entre clique do mouse e posicao atual
	float m_vel; //Velocidade de movimentação

	//Cosntrutor 
	Nave(string spriteName, float vel, ofVec2f pos);
	
	//Rotaciona o Astro em torno de um outro pré estabelecido.
	void update(ofVec2f mouse);

	//Desenha a nave com base na posição da camera
	void draw(ofVec2f camera);

};
