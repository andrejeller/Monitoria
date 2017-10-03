//Codigo escrito por André Jeller
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//Faz o jogo rodar a 60 FPS
	ofSetFrameRate(60);


	//Definindo cor do fundo
	ofSetBackgroundColor(0);

	//Carregando imagens para o projeto.
	ship.sprite.load("player.png");

	for(int i = 0; i < QUANTIDADE_DE_TIROS; i++)
		tiros[i].sprite.load("laser.png");

	for(int i = 0; i < QUANTIDADE_DE_INIMIGOS; i++)
		inimigos[i].sprite.load("ufo.png");


	//Inicializa a posicao do player com X no centro da tela e Y em 450
	ship.pos.set(ofGetWidth() / 2, 450);
	///ofGetWidth() retorna a largura da Janela.


	FireCount = ofGetElapsedTimeMillis();

	//Posiciona os inimigos lado a lado
	for(int i = 0; i < QUANTIDADE_DE_INIMIGOS; i++)
		inimigos[i].pos.set(i * 100 + 50, 200);

}

//--------------------------------------------------------------
void ofApp::update() {

	//Comente e Descomente as fun~çoes abaixo para testas os dois tipos de colisão
	//CheckCollisionWithBox();
	CheckCollisionWithRadius(50.0f);

	//Atualiza constantemente a posição de todos os tiros no array
	for(int i = 0; i < QUANTIDADE_DE_TIROS; i++)
		tiros[i].pos += tiros[i].vel * ofGetLastFrameTime();

	//Atualizando posição do player para se movimentar
	ship.pos += ship.vel * ofGetLastFrameTime();
	ship.vel += ship.vel.normalized() * - 0.7f; //Mini "Atrito" para fazer ele parar


	if(tiros_para_desenhar > QUANTIDADE_DE_TIROS)
		tiros_para_desenhar = QUANTIDADE_DE_TIROS;

}

//--------------------------------------------------------------
void ofApp::draw() {

	//Desenha Tudo
	
	ship.sprite.draw(ship.pos.x - ship.sprite.getWidth() / 2, ship.pos.y - ship.sprite.getHeight() / 2);

	for(int i = 0; i < tiros_para_desenhar; i++)
		tiros[i].sprite.draw(tiros[i].pos.x - tiros[i].sprite.getWidth() / 2, tiros[i].pos.y - tiros[i].sprite.getHeight() / 2);


	for(int i = 0; i < QUANTIDADE_DE_INIMIGOS; i++) {
		//Apenas desenha inimigo se ele não estiver morto
		if(inimigos[i].isDead == false)
			inimigos[i].sprite.draw(inimigos[i].pos.x - inimigos[i].sprite.getWidth() / 2, inimigos[i].pos.y - inimigos[i].sprite.getHeight() / 2);
	}


}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	//Chama funcao Atirar quando a tecla espaco é pressionada
	if(key == 32) //Espaco
		Shoot();

	if(key == 'a')
		ship.vel.x -= 4;

	if(key == 'd')
		ship.vel.x += 4;
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
