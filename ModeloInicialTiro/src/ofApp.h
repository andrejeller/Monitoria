#pragma once
//Codigo escrito por Andr� Jeller
#include "ofMain.h"

//Se realmente quiser saber o que � um #define poergunte ao monitor Andr�Jeller
#define QUANTIDADE_DE_TIROS 20


struct Player {
	ofImage sprite; ////Declarando que haver� uma imagem do player
	ofVec2f pos, vel; // Declarando Vetor de posi��o e velocidade do player
  /* Velocidade n�o foi utiliza no exemplo, 
	mas continua aqui para caso queira usar este exemplo em seu projeto, 
	n�o esquecer de coloca-la*/

	/// Um vetor de n�o � nada mais que uma unica variavel que contem um X e um Y
	///Logo para n�o precisar declarar dois int(s) usamos um vetor
	
};

//Sim!, a struct Laser e a Player possuem os mesmo atributos
//por�m para melhor entendimento, e, por serem coisas diferentes
//resolvi trabalhar com eles separados
struct Laser {
	ofImage sprite;
	ofVec2f pos, vel;
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

	//Variavel define qual tiro (no array) ser� disparado no momento em que apertar Espa�o
	int tiro_para_disparar = 0;
	//Variavel define quantos tiros ja foram disparados para poder desenhalos
	int tiros_para_desenhar = 0;


	//Esta variavel � utilizada para fazer uma "contagem regressiva" e saber se o player pode atirar ou n�o
	// (Usada para medir os Tiros por Segundo)
	float FireCount;
	float FireRate = 2; //2 Tiros por Segundo

	//Declarando a existencia de um Player
	Player ship;
	//Declarando a existencia de um array de Lasers
	Laser tiros[QUANTIDADE_DE_TIROS];


	//Fun��o para atirar
	void Shoot() {
		//Se (tempo de jogo - tempo de ultimo tiro > TirosPorSegundo){
		if(ofGetElapsedTimeMillis() - FireCount > 1000 / FireRate) {
			//Coloca o tiro na posicao do player
			tiros[tiro_para_disparar].pos = ship.pos;
			//Define que agora ele tem uma velocidade
			tiros[tiro_para_disparar].vel.y = -400;
			//Diz que a proxima vez que chamar a fun��o dever� atirar o proximo laser do array
			tiro_para_disparar++;

			//Diz que o proximo tiro ja pode ser desenhado
			tiros_para_desenhar++;

			//Se o proximo tiro for maior que a quantidade existente no array voltamos ao primeiro
			//Assim reutilizamos todos os tiros sem precisar realocar memoria
			if(tiro_para_disparar > QUANTIDADE_DE_TIROS)
				tiro_para_disparar = 0;

			//Salva o momento do ultimo tiro
			FireCount = ofGetElapsedTimeMillis();
		}
	}


};
