#pragma once
//Codigo escrito por Andr� Jeller
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


	ofImage background; //Declarando que haver� uma imagem background
	ofImage player; ////Declarando que haver� uma imagem do player

	ofVec2f posPlayer; // Declarando Vetor de posi��o do player
	/// Um vetor de posi��o n�o � nada mais que uma unica variavel que contem um X e um Y
	///Logo para n�o precisar declarar dois int(s) usamos um vetor

	//Vetores para anima��o
	ofVec2f spriteSize, spriteToDraw;
	bool Idle; // Bool para saber se o player est� parado ou n�o
	float ultimaTroca = 0; //CountDown para troca de frames na animacao


	//Fun��o para controle das sprites e anima�oes
	void Animacoes() {
		if(!Idle) {  //Animacao Andando
			if(spriteToDraw.x > 3)
				spriteToDraw.x = 0;
		}
		else if(Idle) { //Animacao Parado
			if(spriteToDraw.x > 1)
				spriteToDraw.x = 0;
		}

			//Troca de imagens por milisegundos
			//Mini contagem regressiva para trocar as imagens da animacao
		if(ofGetElapsedTimeMillis() - ultimaTroca > 90) {
			spriteToDraw.x++;
			ultimaTroca = ofGetElapsedTimeMillis();
		}

	}

	void Input() {
		//Se apertar tecla 'a' e o player estiver dentro da tela
		if(ofGetKeyPressed('a') && posPlayer.x > 3) {
			posPlayer.x -= 300 * ofGetLastFrameTime();
			spriteToDraw.y = 1;
			Idle = false;
		}

		//Se apertar tecla 'd' e o player estiver dentro da tela
		if(ofGetKeyPressed('d') && posPlayer.x < ofGetWidth() - 50) {
			posPlayer.x += 300 * ofGetLastFrameTime();
			spriteToDraw.y = 0;
			Idle = false;
		}

		//Se nem a tecla 'a' ou a tecla 'b' estiver pressionada
		if(!ofGetKeyPressed('a') && !ofGetKeyPressed('d')) {
			Idle = true;
			spriteToDraw.y = 2;
		}

	}

};
