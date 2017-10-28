//Codigo escrito por André Jeller
#include "Nave.h"

Nave::Nave(string spriteName, float vel, ofVec2f pos) {
	m_vel = 2; //Define velocidade da nave
	m_pos = pos; //Coloca a nave no centro da tela
	m_sprite.load("player.png"); //Inicializa a Sprite
	m_sprite.setAnchorPercent(0.5f, 0.5f); //Coloca o Pivo de rotação no centro da imagem	
}


void Nave::update(ofVec2f mouse) {

	//Calcula a distancia entre a nave a a posição do clique do mouse
	distancia = mouse - m_pos;

	//Se essa distancia for maior que 2, ele movimenta a nave
	if(distancia.length() >= 2)
		m_pos += distancia.normalize() * m_vel;
}


void Nave::draw(ofVec2f camera) {
	
	//Calcula rotação da nave	
	float rotation = ofRadToDeg(atan2f(distancia.y, distancia.x)) + 90;

	//Nem pergunte, + avançado
	//Basicamente translada o Sistema de Cordenadas para a posição do player 
	//para poder rotaciona-lo e ficar mais bonito

	ofTranslate(m_pos - camera);
	ofRotateZ(rotation);

	ofSetColor(255);
	m_sprite.draw(ofVec2f(0, 0));

	//Devolve o Sist para a posição (0, 0)
	ofTranslate(0, 0);
}
