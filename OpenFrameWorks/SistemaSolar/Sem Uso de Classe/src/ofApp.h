//Codigo escrito por André Jeller
#pragma once
#include "ofMain.h"
#define QUANTIDADE_DE_ESTRELAS 1000

struct Player {
	ofImage sprite; //Sprite da Nave
	ofVec2f pos; //Vetore de Posição
	float vel; //Velocidade de movimentação
};

struct Astro {
	float size, period; //tamanho e periodo de rotação
	ofVec2f pos, anc; //posição e ancora(ponto de rotação) do astro
	ofColor color; //Cor do astro
};

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

	Player ship; //Declarando um player
	ofVec2f camera, mouse; //Declarando vetor para o mouse e camera
	ofVec2f distancia; //Vetor de distancia entre clique do mouse e player
	ofVec2f stars[QUANTIDADE_DE_ESTRELAS]; //Array de posicoes para estrelas

	//Declarando astros
	Astro sol, mercurio, venus, terra, lua, marte;
	
	//Funções para deixar mais pratico a montagem do codigo, iniciar, rotacionar e desenhar os Astros.

	//Inicializa astro (Astro para inicializar, tamanho, periodo de rotação, posiçao em relação a orbita, cor)
	void InicializaAstro(Astro* as, float size, float period, ofVec2f pos, ofColor color) {
		//Astro deve ser recebido por referencia, pois os valores dentro dele serão alterados
		as->size = size;
		as->period = period;
		as->pos = pos;
		as->anc = pos;
		as->color = color;
	}

	//Desenha o Astro racebido por parametro
	void DesenharAstro(Astro as) {
		ofSetColor(as.color);
		ofDrawCircle(as.pos - camera, as.size);
	}

	//Rotaciona o Astro em torno de um outro pré estabelecido.
	void RotacionarAstro(Astro* as, Astro pivo) {
		//Astro deve ser recebido por referencia, pois os valores dentro dele serão alterados
		as->anc.rotate(as->period);
		as->pos = as->anc;
		as->pos += pivo.pos;
	}

};
