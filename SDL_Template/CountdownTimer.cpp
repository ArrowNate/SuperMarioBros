#include "CountdownTimer.h"

CountdownTimer::CountdownTimer()
{
	Time(0);
}

CountdownTimer::~CountdownTimer()
{
	for (unsigned i = 0; i < m_pCountDown.size(); i++) {
		delete m_pCountDown[i];
		m_pCountDown[i] = nullptr;
	}
}

void CountdownTimer::Time(int time)
{

	if (time == 0) {
		for (int i = 0; i < 3; i++) {
			m_pCountDown.push_back(new TextureGL("0", "emulogic.ttf", 20, { 255,0,0 }));
			m_pCountDown[i]->Parent(this);
			m_pCountDown[i]->Position(Vector2(-22.0f * i, 0.0f));
		}
	}
	else {
		std::string str = std::to_string(time);
		unsigned lastIndex = (unsigned)str.length() - 1;

		for (unsigned i = 0; i <= lastIndex; i++) {
			m_pCountDown.push_back(new Texture(str.substr(i, 1), "emulogic.ttf", 20, { 255,0,0 }));
			m_pCountDown[i]->Parent(this);
			m_pCountDown[i]->Position(Vector2(-22.0f * (lastIndex - i), 0.0f));
		}
	}

}


void CountdownTimer::Render()
{
	for (auto digit : m_pCountDown) {
		digit->Render();
	}
}
