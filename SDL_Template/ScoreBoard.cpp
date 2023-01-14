#include "ScoreBoard.h"

void ScoreBoard::ClearBoard() {
	for (unsigned i = 0; i < m_pScore.size(); i++) {
		delete m_pScore[i];
		m_pScore[i] = nullptr;
	}
	m_pScore.clear();
}

void ScoreBoard::Score(int score) {
	ClearBoard();
	if (score == 0) {
		for (int i = 0; i < 2; i++) {
			m_pScore.push_back(new TextureGL("0", "emulogic.ttf", 20, { 255,255,255 }));
			m_pScore[i]->Parent(this);
			m_pScore[i]->Position(Vector2(-22.0f * i, 0.0f));
		}
	}
	else {
		std::string str = std::to_string(score);
		unsigned lastIndex = (unsigned)str.length() - 1;

		for (unsigned i = 0; i <= lastIndex; i++) {
			m_pScore.push_back(new TextureGL(str.substr(i, 1), "emulogic.ttf", 20, { 255,255,255 }));
			m_pScore[i]->Parent(this);
			m_pScore[i]->Position(Vector2(-22.0f * (lastIndex - i), 0.0f));
		}
	}
}

ScoreBoard::ScoreBoard() : ScoreBoard({ 230,230,230 }) {

}

ScoreBoard::ScoreBoard(SDL_Color color) {
	mColor = color;
	Score(0);
}

ScoreBoard::~ScoreBoard() {
	ClearBoard();
}

void ScoreBoard::Render() {
	for (auto digit : m_pScore) {
		digit->Render();
	}
}