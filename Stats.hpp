#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <map>
using namespace std;
using namespace sf;
namespace Stats {
	namespace ClubMan {
		static vector<float> clubman_floats = { 50.f, 18.f, 0.f, 2.f, 1.f, 1.f, 14.f, 22.f, 25.f };
		//Frame sizes order: ATK WALK STAND
		static vector <Vector2i> clubman_frame_sizes = { Vector2i(143, 147), Vector2i(87, 113), Vector2i(62, 110) };
		static const vector<float>& getFloats() {
			return clubman_floats;
		}
		static const vector<Vector2i>& getFrameSizes() {
			return clubman_frame_sizes;
		}
	}
}