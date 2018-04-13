//Codigo escrito por André Jeller
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//Faz o jogo rodar a 60 FPS
	ofSetFrameRate(60);

	//Carregando imagens para o projeto.
	background.load("background.jpg");
	player.load("player.png");

	//Inicializa a posicao do player com X no centro da tela e Y em 310
	posPlayer.set(ofGetWidth() / 2, 310);
	//ofGetWidth() retorna a largura da Janela.

	//Inicializa A bool pulo e sua "Contagem Regressiva".
	isJumping = false;
	jumpCountDown = 0.0f;
}

//--------------------------------------------------------------
void ofApp::update() {
	//Faz a função "Input" rodar a cada update.
	Inputs();

	//Adiciona "Gravidade" ao Player o tempo todo
	posPlayer.y += 100 * ofGetLastFrameTime();

	//Faz o player ficar no chão (não ultrapassar)
	if(posPlayer.y >= 360)
		posPlayer.y = 360;
	
	//Se ele está pulando e a contagem for maior que Zero ele pula
	if(isJumping && jumpCountDown > 0) {
		posPlayer.y -= 200 * ofGetLastFrameTime();
		jumpCountDown -= 0.2f;
	}
	//Caso contrario fica falso para poder acionar a tela de pulo
	else if (isJumping && jumpCountDown < 0) {
		isJumping = false;
	}
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	//Desenha o Background e o Player
	background.draw(0, 0, ofGetWidth(), ofGetHeight());
	player.draw(posPlayer, 50, 70);

}

#pragma region NaoUtilizados

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	//cout << key << endl;
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
