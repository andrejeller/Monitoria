//Codigo escrito por André Jeller
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//Deixar o fundo preto
	ofBackground(0); 

	//Cria posiçoes para estrelas
	for(int i = 0; i < QUANTIDADE_DE_ESTRELAS; i++)
		stars[i] = ofVec2f(ofRandom(-500, 1500), ofRandom(-1500, 1500));
	
	//Coloca o "clique" inicial do mouse no centro da tela	
	mouse.set(ofGetWidth() / 2, ofGetHeight() / 2); 

}

//--------------------------------------------------------------
void ofApp::update() {

	//Chama funcao update dos astros e passa por parametro sua "orbita"
	mercurio.update(sol);
	venus.update(sol);
	terra.update(sol);
	lua.update(terra);
	marte.update(sol);	
	
	//Chama função update da nave
	player.update(mouse);

	//Define que a posição da camera é no centro da tela (CENTRALIZA O PLAYER)
	camera.set(player.m_pos.x - (ofGetWidth() / 2), player.m_pos.y - (ofGetHeight() / 2));
}

//--------------------------------------------------------------
void ofApp::draw() {

	//Desenha estrelas
	for(int i = 0; i < QUANTIDADE_DE_ESTRELAS; i++)
		ofDrawCircle(stars[i] - camera, ofRandom(3));

	//Desenha Astros
	sol.draw(camera);
	mercurio.draw(camera);
	venus.draw(camera);
	terra.draw(camera);
	lua.draw(camera);
	marte.draw(camera);
	
	//Desenha Player
	player.draw(camera);	
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//Define a posição de clique do mouse
	mouse.set(x + camera.x, y + camera.y);
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