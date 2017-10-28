//Codigo escrito por André Jeller
#pragma once
#include "ofMain.h"

class Astro {

public:

	float m_size, m_period; //tamanho e periodo de rotação
	ofVec2f m_pos, m_anc; //posição e ancora(ponto de rotação) do astro
	ofColor m_color; //Cor do astro

	//Construtor
	Astro(float size, float period, ofVec2f pos, ofColor color);

	//Rotaciona o Astro em torno de um outro pré estabelecido.
	void update(Astro pivo);

	//Desenha o astro com base na posição da camera
	void draw(ofVec2f camera);

};
