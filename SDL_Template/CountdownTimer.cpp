#include "CountdownTimer.h"

CountdownTimer::CountdownTimer()
{
	//Time(0);
	mTimeRemaining = 400;
}

CountdownTimer::~CountdownTimer()
{
	for (int i = 0; i < m_pCountDown.size(); i++) {
		delete m_pCountDown[i];
		m_pCountDown[i] = nullptr;
	}

}

int CountdownTimer::TimeRemaining()
{
	return mTimeRemaining;
}

void CountdownTimer::SetGameTime(int time)
{
	mTimeRemaining -= time;
}

void CountdownTimer::Time(int time)
{
	
	for (int i = 0; i < 1; i++) {
		m_pCountDown.push_back(new TextureGL(std::to_string(mTimeRemaining), "emulogic.ttf", 20, {255,255,255 }));
		m_pCountDown[i]->Parent(this);
		m_pCountDown[i]->Position(Vector2(-22.0f * i, 0.0f));
	}

}


void CountdownTimer::Update()
{
	
	//for (unsigned i = 0; i < m_pCountDown.size(); i++) {
	//	if (m_pCountDown[i] != nullptr) {
	//		delete m_pCountDown[i];
	//		//mTimeRemaining += time;
	//	}

	//}
	
	
}


void CountdownTimer::Render()
{
	for (auto digit : m_pCountDown) {
		digit->Render();
	}
	
}
