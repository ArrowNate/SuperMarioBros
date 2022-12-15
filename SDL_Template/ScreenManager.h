#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H

class ScreenManager {
private:
	static ScreenManager * sInstance;

public:
	static ScreenManager * Instance();
	static void Release();

	void Update();
	void Render();

private:
	ScreenManager();
	~ScreenManager();
};
#endif