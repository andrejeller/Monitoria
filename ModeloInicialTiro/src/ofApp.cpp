//Codigo escrito por André Jeller
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//Faz o jogo rodar a 60 FPS
	ofSetFrameRate(60);

	//Carregando imagens para o projeto.
	ship.sprite.load("player.png");

	for(int i = 0; i < QUANTIDADE_DE_TIROS; i++) {
		tiros[i].sprite.load("laser.png");
	}

	//Definindo cor do fundo
	ofSetBackgroundColor(0);


	//Inicializa a posicao do player com X no centro da tela e Y em 450
	ship.pos.set(ofGetWidth() / 2, 450);
	///ofGetWidth() retorna a largura da Janela.


	FireCount = ofGetElapsedTimeMillis();

}

//--------------------------------------------------------------
void ofApp::update() {

	//Atualiza constantemente a posição de todos os tiros no array
	for(int i = 0; i < QUANTIDADE_DE_TIROS; i++) {
		tiros[i].pos += tiros[i].vel * ofGetLastFrameTime();
	}


	if(tiros_para_desenhar > QUANTIDADE_DE_TIROS)
		tiros_para_desenhar = QUANTIDADE_DE_TIROS;

}

//--------------------------------------------------------------
void ofApp::draw() {

	//Desenha o Background e o Player
	//background.draw(0, 0, ofGetWidth(), ofGetHeight());
	ship.sprite.draw(ship.pos.x - ship.sprite.getWidth() / 2, ship.pos.y - ship.sprite.getHeight() / 2);

	for(int i = 0; i < tiros_para_desenhar; i++)
		tiros[i].sprite.draw(tiros[i].pos.x - tiros[i].sprite.getWidth() / 2, tiros[i].pos.y - tiros[i].sprite.getHeight() / 2);


}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	//Chama funcao Atirar quando a tecla espaco é pressionada
	if(key == 32) //Espaco
		Shoot();

}

#pragma region NaoUtilizados
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
