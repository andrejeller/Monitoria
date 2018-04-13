//Codigo escrito por André Jeller
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0); //Deixar o fundo preto

	//Cria posiçoes para estrelas
	for(int i = 0; i < QUANTIDADE_DE_ESTRELAS; i++)
		stars[i] = ofVec2f(ofRandom(-500, 1500), ofRandom(-1500, 1500));

	

	ship.vel = 2; //Define velocidade da nave
	ship.sprite.load("player.png"); //Inicializa a Sprite
	ship.sprite.setAnchorPercent(0.5f, 0.5f); //Coloca o Pivo de rotação no centro da imagem
	ship.pos.set(ofGetWidth() / 2, ofGetHeight() / 2); //Coloca a nave no centro da tela
	mouse.set(ofGetWidth() / 2, ofGetHeight() / 2); //Coloca o "clique" inicial do mouse no centro da tela
	
	
	//Inicializa os Astros
	InicializaAstro(&sol, 100, 0, ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), ofColor(255, 255, 0));
	InicializaAstro(&mercurio, 8, 0.2, ofVec2f(90, 90), ofColor(255, 0, 0));
	InicializaAstro(&venus, 15, 0.3, ofVec2f(120, 120), ofColor(255, 100, 0));
	InicializaAstro(&terra, 25, 0.4f, ofVec2f(160, 160), ofColor(100, 100, 255));
	InicializaAstro(&lua, 5, 0.8f, ofVec2f(25, 25), ofColor(255, 255, 255));
	InicializaAstro(&marte, 25, 0.6f, ofVec2f(210, 210), ofColor(255, 0, 0));	

}

//--------------------------------------------------------------
void ofApp::update() {

	//Rotaciona os astros
	RotacionarAstro(&mercurio, sol);
	RotacionarAstro(&venus, sol);
	RotacionarAstro(&terra, sol);
	RotacionarAstro(&marte, sol);	
	RotacionarAstro(&lua, terra);


	//Calcula a distancia entre a nave a a posição do clique do mouse
	distancia = mouse - ship.pos;

	//Se essa distancia for maior que 2, ele movimenta a nave
	if(distancia.length() >= 2)		
		ship.pos += distancia.normalize() * ship.vel;


	//Define que a posição da camera é no centro da tela (CENTRALIZA O PLAYER)
	camera.set(ship.pos.x - (ofGetWidth() / 2), ship.pos.y - (ofGetHeight() / 2));	
}

//--------------------------------------------------------------
void ofApp::draw() {

	//Desenha estrelas
	for(int i = 0; i < QUANTIDADE_DE_ESTRELAS; i++)
		ofDrawCircle(stars[i] - camera, ofRandom(3));

	//Desenhas Astros
	DesenharAstro(sol);
	DesenharAstro(mercurio);
	DesenharAstro(venus);
	DesenharAstro(terra);
	DesenharAstro(lua);
	DesenharAstro(marte);
	

	ofSetColor(255);
	
	//Calcula rotação da nave
	float rotation = ofRadToDeg(atan2f(distancia.y, distancia.x)) + 90;

	//Nem pergunte, + avançado
	//Basicamente translada o sistema de coordenadas para a posição do player 
	//para poder rotaciona-lo e ficar mais bonito
	
	ofTranslate(ship.pos - camera);
	ofRotateZ(rotation);	
	ship.sprite.draw(0, 0);
	
	//Devolve o Sist para a posição (0, 0)
	ofTranslate(0, 0);
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