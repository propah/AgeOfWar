#include "Game.h"

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initSounds();
	this->initEntities();
}

Game::~Game()
{
}

/*void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}*/

void Game::render()
{
	this->window->clear();
	this->window->setView(this->g_view);
	this->g_world.render(window);
	this->window->setView(this->g_gui_view);
	this->g_gui.render(window);
	this->window->display();
}

void Game::update(const float dt)
{
	
	this->g_gui.update(dt);//this->g_world.getAllyBaseLevel());
	this->g_world.update(dt);
	this->updateViews(dt);
	this->pollEvents();
}

void Game::updateViews(const float dt)
{
	int direction = 0;
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		direction++;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		direction--;
	}
	if (direction == -1 && this->g_view.getCenter().x > 445) {
		this->g_view.move(Vector2f(300.f * direction * dt, 0));
	}
	if (direction == 1 && this->g_view.getCenter().x < 1000) {
			this->g_view.move(Vector2f(300.f * direction * dt, 0));
	}
}

void Game::updateEntities(const float dt)
{
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->g_ev))
	{
		switch (this->g_ev.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				this->window->close();
			}
		}
	}
}


const bool Game::running()
{
	return this->window->isOpen();
}

void Game::run()
{
	Clock clock;
	Time time_since_last_frame = Time::Zero;
	while (this->running()) {
		Time elapsed_time = clock.restart();
		time_since_last_frame += elapsed_time;
		while (time_since_last_frame >= this->time_per_frame) {
			time_since_last_frame -= this->time_per_frame;
			this->update(this->time_per_frame.asSeconds());
		}

		//this->updateStatistics(elapsed_time);
		this->render();
	}
}

void Game::initWindow()
{
	ifstream ifs("r_config/window.ini");
	string title_name = "None";
	VideoMode window_res(1280, 720);
	unsigned int framerate_limit = 144;
	bool vsyncEnabled = false;
	if (ifs.is_open()) {
		getline(ifs, title_name);
		ifs >> window_res.width >> window_res.height;
		ifs >> framerate_limit;
		ifs >> vsyncEnabled;
	}
	ifs.close();
	this->window = new RenderWindow(window_res, title_name);//, Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(framerate_limit);
	this->time_per_frame = seconds(1.f / static_cast<float>(framerate_limit));
	this->window->setVerticalSyncEnabled(vsyncEnabled);
	//this->window->setKeyRepeatEnabled(false);
}

void Game::initVariables()
{
	this->window = nullptr;
	this->g_view.reset(FloatRect(20, 0, 850, 480));
	this->g_gui_view.reset(FloatRect(0, 0, 850, 480));
}

void Game::initSounds()
{
	this->g_mu_bg.openFromFile("r_sounds/epic_background.wav");
	this->g_mu_bg.setLoop(true);
	this->g_mu_bg.setVolume(70);
	this->g_mu_bg.play();
}

void Game::initEntities()
{
}
