#pragma once
//Codigo escrito por André Jeller
#include "ofMain.h"

//Se realmente quiser saber o que é um #define poergunte ao monitor AndréJeller
#define QUANTIDADE_DE_TIROS 20
#define QUANTIDADE_DE_INIMIGOS 10


struct Player {
	ofImage sprite; ////Declarando que haverá uma imagem do player
	ofVec2f pos, vel; // Declarando Vetor de posição e velocidade do player
  /* Velocidade não foi utiliza no exemplo,
	mas continua aqui para caso queira usar este exemplo em seu projeto,
	não esquecer de coloca-la*/

	/// Um vetor de não é nada mais que uma unica variavel que contem um X e um Y
	///Logo para não precisar declarar dois int(s) usamos um vetor

};

//Sim!, a struct Laser e a Player possuem os mesmo atributos
//porém para melhor entendimento, e, por serem coisas diferentes
//resolvi trabalhar com eles separados
struct Laser {
	ofImage sprite;
	ofVec2f pos, vel;
};

//SIM! o inimigo é praticamente igual ao player também, mas por serem coisas diferentes
//prefiro trabalhar com eles separados, como introdução a OO (Classes).
struct Enemy {
	ofVec2f pos;
	ofImage sprite;	
	bool isDead = false; 
	//bool para saber no momento se o inimigo esta morto ou não
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

	//Variavel define qual tiro (no array) será disparado no momento em que apertar Espaço
	int tiro_para_disparar = 0;
	//Variavel define quantos tiros ja foram disparados para poder desenhalos
	int tiros_para_desenhar = 0;


	//Esta variavel é utilizada para fazer uma "contagem regressiva" e saber se o player pode atirar ou não
	// (Usada para medir os Tiros por Segundo)
	float FireCount;
	float FireRate = 2; //2 Tiros por Segundo

	//Declarando a existencia de um Player
	Player ship;
	//Declarando a existencia de um array de Lasers
	Laser tiros[QUANTIDADE_DE_TIROS];
	//Declarando a existencia de Inimigos
	Enemy inimigos[QUANTIDADE_DE_INIMIGOS];


	//Função para atirar
	void Shoot() {
		//Se (tempo de jogo - tempo de ultimo tiro > TirosPorSegundo){
		if(ofGetElapsedTimeMillis() - FireCount > 1000 / FireRate) {
			//Coloca o tiro na posicao do player
			tiros[tiro_para_disparar].pos = ship.pos;
			//Define que agora ele tem uma velocidade
			tiros[tiro_para_disparar].vel.y = -400;
			//Diz que a proxima vez que chamar a função deverá atirar o proximo laser do array
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

	//Função para verificar colisao entre tiro e inimigo
	//Colisao "Box" seria utilizando o proprio tamanho da sprite para verificar de forma quadrada a colisao
	void CheckCollisionWithBox() {
		//Para cada Inimigo Verifica os tiros individualmene
		for(int i = 0; i < QUANTIDADE_DE_INIMIGOS; i++) {
			for(int j = 0; j < QUANTIDADE_DE_TIROS; j++) {
				//Compara se alguma parte do tiro está dentro do quadrado de denenho do inimigo
				if(tiros[j].pos.x + tiros[j].sprite.getWidth() > inimigos[i].pos.x && tiros[j].pos.x < inimigos[i].pos.x + inimigos[i].sprite.getWidth()
				   && tiros[j].pos.y + tiros[j].sprite.getHeight() > inimigos[i].pos.y && tiros[j].pos.y < inimigos[i].pos.y + inimigos[i].sprite.getHeight()) {

					inimigos[i].isDead = true;
				}
			}
		}
	}

	//Função para verificar colisao entre tiro e inimigo
	//Colisao "Radius" seria utilizando um raio de tamanho definido pelo usuario para verificar a colisão
	void CheckCollisionWithRadius(float distPermit) {
		//Para cada Inimigo Verifica os tiros individualmene
		for(int i = 0; i < QUANTIDADE_DE_INIMIGOS; i++) {
			for(int j = 0; j < QUANTIDADE_DE_TIROS; j++) {

				//Calcula vetor de distancia entre pos tiro e inimigo
				ofVec2f vDistance = (inimigos[i].pos - tiros[j].pos);
				//Pega a distancia real entre os pontos
				float distance = vDistance.length();

				//Compara o para ver se a distancia entre os dois é menor que a definida (distPermit)
				//E diz para o inimigo que ele morreu
				if(distance <= distPermit)
					inimigos[i].isDead = true;

			}
		}
	}


};
