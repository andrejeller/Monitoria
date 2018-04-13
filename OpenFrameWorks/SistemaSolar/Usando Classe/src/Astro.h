//Codigo escrito por Andr� Jeller
#pragma once
#include "ofMain.h"

class Astro {

public:

	float m_size, m_period; //tamanho e periodo de rota��o
	ofVec2f m_pos, m_anc; //posi��o e ancora(ponto de rota��o) do astro
	ofColor m_color; //Cor do astro

	//Construtor
	Astro(float size, float period, ofVec2f pos, ofColor color);

	//Rotaciona o Astro em torno de um outro pr� estabelecido.
	void update(Astro pivo);

	//Desenha o astro com base na posi��o da camera
	void draw(ofVec2f camera);

};
