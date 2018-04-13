#pragma once
//Codigo escrito por André Jeller
#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);


	ofImage background; //Declarando que haverá uma imagem background
	ofImage player; ////Declarando que haverá uma imagem do player

	ofVec2f posPlayer; // Declarando Vetor de posição do player
	/// Um vetor de posição não é nada mais que uma unica variavel que contem um X e um Y
	///Logo para não precisar declarar dois int(s) usamos um vetor


	bool isJumping; // Bool para saber se a tecla de pulo foi pressionada
	float jumpCountDown; // Float para calcular a duração do pulo

	//Funcao para reconhecer os Inputs
	//Perguntar para André Jeller o motivo de sua utilizacao e
	// a nao utilizacao do proprio keyPress
	void Inputs() {

		//Se apertar tecla 'a'
		if(ofGetKeyPressed('a') && posPlayer.x > 3)
			posPlayer.x -= 300 * ofGetLastFrameTime();

		//Se apertar tecla 'd'
		if(ofGetKeyPressed('d') && posPlayer.x < ofGetWidth() - 50)
			posPlayer.x += 300 * ofGetLastFrameTime();
		
		//Se apertar tecla 'espaco'
		if(ofGetKeyPressed(32) && posPlayer.x < ofGetWidth() - 5 && !isJumping) {
			isJumping = true;
			jumpCountDown = 10.0f;
		}

	}

};
