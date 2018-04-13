//Codigo escrito por André Jeller
#pragma once
#include "ofMain.h"
#include "Astro.h"
#include "Nave.h"
#define QUANTIDADE_DE_ESTRELAS 1000


class ofApp : public ofBaseApp {

public:
#pragma region Coisas OF
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
#pragma endregion

	
	ofVec2f camera, mouse; //Declarando vetor para o mouse e camera
	ofVec2f stars[QUANTIDADE_DE_ESTRELAS]; //Array de posicoes para estrelas

	//Declarando um player, e inicializando-o com seu construtor
	Nave player = Nave("player.png", 20, ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2)); 

	//Declarando astros	e inicializando-os com seus construtores
	Astro sol = Astro(100, 0, ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), ofColor(255, 255, 0));
	Astro mercurio = Astro(8, 0.2, ofVec2f(90, 90), ofColor(255, 0, 0));
	Astro venus = Astro(15, 0.3, ofVec2f(120, 120), ofColor(255, 100, 0));
	Astro terra = Astro(25, 0.4f, ofVec2f(160, 160), ofColor(100, 100, 255));
	Astro lua = Astro(5, 0.8f, ofVec2f(25, 25), ofColor(255, 255, 255));
	Astro marte = Astro(25, 0.6f, ofVec2f(210, 210), ofColor(255, 0, 0));

};
