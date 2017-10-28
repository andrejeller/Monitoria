//Codigo escrito por André Jeller
#include "Astro.h"

Astro::Astro(float size, float period, ofVec2f pos, ofColor color) {
	m_pos = pos;
	m_anc = pos;
	m_size = size;
	m_color = color;
	m_period = period;
}

void Astro::update(Astro pivo) {

	m_anc.rotate(m_period);	
	m_pos = m_anc;
	m_pos += pivo.m_pos;	

}

void Astro::draw(ofVec2f camera) {
	ofSetColor(m_color);
	ofDrawCircle(m_pos - camera, m_size);
}
