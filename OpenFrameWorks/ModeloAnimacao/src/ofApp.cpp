//Codigo escrito por André Jeller
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//Faz o jogo rodar a 60 FPS
	ofSetFrameRate(60);


#pragma region Setup - Coisas de Imagem
	//Carregando imagens para o projeto.
	background.load("background.jpg");
	player.load("PlayerSpriteSheet.png");

	//Definindo tamanho das sprites dentro da spritesheet
	//Neste caso ela tem 73px de largura e 97px de Altura
	spriteSize.set(73, 97);

	//Definindo que a sprite inicial será a de numero 0, tanto em altura como em largura
	/* Sprite Sheet e posição das sprites escolhidas
		0,0 - 0,1 - 0,2 - 0,3...
		1,0 - 1,1 - 1,2 - 1,3...
	*/
	spriteToDraw.set(0, 2);
#pragma endregion


	//Inicializa a posicao do player com X no centro da tela e Y em 310
	posPlayer.set(ofGetWidth() / 2, 310);
	//ofGetWidth() retorna a largura da Janela.

}

//--------------------------------------------------------------
void ofApp::update() {

	//Adiciona "Gravidade" ao Player o tempo todo, caso queira fazer pulo
	posPlayer.y += 100 * ofGetLastFrameTime();

	//Faz o player ficar no chão (não ultrapassar)
	if(posPlayer.y >= 330)
		posPlayer.y = 330;
	
	//Chamando funcoes
	Input();
	Animacoes();
}

//--------------------------------------------------------------
void ofApp::draw() {

	//Desenha o Background e o Player
	background.draw(0, 0, ofGetWidth(), ofGetHeight());
	player.drawSubsection(posPlayer.x, posPlayer.y, spriteSize.x, spriteSize.y, spriteSize.x * spriteToDraw.x, spriteSize.y * spriteToDraw.y);
	
	//player.drawSubsection(posPlayer.x, posPlayer.y, spriteSize.x * MovingSide, spriteSize.y, )
	//drawSubsection desenha apenas um pedaço da imagem, definido pelo programador

	// Explicação do DrawSubsection;
	/*
	### Ordem dos parametros ###

	player.drawSubsection(Posição do player em X, pos em Y, tamanho do 'recorte' a ser desenhado e X, recorte em Y, pos da sprite escolhida na imagem original em X, sprite escolhida em Y)

	Descrevendo
	Pos do player na imagem XY -- Posição em que o player será desenhado (pivo no canto superior esquerdo)
	'Recorte' da Imagem XY -- Tamano em pixels da imagem final a ser recortada da imagem original
	Pos da sprite XY -- Pos da sprite na imagem original que será desenhada, neste caso se multiplica a quantidade de pixels em X ou Y pela quantidade de imagens que se quer 'avançar' no tabela/Imagem original

	EXEMPLO: - Isso é sua imagem com as posiçoes das sprites que voce deve escolher para ser desenhado
	###########################
	## 0,0 # 0,1 # 0,2 # 0,3 ##
	## 1,0 # 1,1 # 1,2 # 1,3 ##
	## 2,0 # 2,1 # 2,2 # 2,3 ##
	###########################
	*/

}

#pragma region NaoUtilizados
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

#pragma endregion
