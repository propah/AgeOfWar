#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "World.h"
#include "Gui.h"
#include "Resources.h"
using namespace sf;
using namespace std;
class Game
{
public:
    // Constructors / Destructors
    Game();
    ~Game();

    /////
    // Functions
    /////

    //void updateStatistics(Time elapsed_time);
    void render();
    void update(const float dt);
    void updateViews(const float dt);
    void updateEntities(const float dt);
    void pollEvents();
    const bool running();
    void run();
private:

    /////
    // Variables
    /////

    /// Windows
    RenderWindow* window;

    //Views
    View g_view;
    View g_gui_view;

    // Events
    Event g_ev;

    // Frame
    Time time_per_frame;

    //Gui
    Gui g_gui;

    // Fonts
    Font g_font;

    // Music and sounds
    Music g_mu_bg;

    // Entities
    //vector <Entity> g_enemies;
    //vector <Entity> g_allies;

    // World
    World g_world;

    /////
    // Functions
    /////
    void initWindow();
    void initVariables();
    void initSounds();
    void initEntities();

};

