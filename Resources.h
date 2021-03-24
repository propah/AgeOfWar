#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <unordered_map>
using namespace std;
using namespace sf;
template<typename RESOURCE, typename IDENTIFIER = int>
class Resources {
public:
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	Resources() = default;

	template<typename ... Args>
	void load(const IDENTIFIER& id, Args&& ... args);

	RESOURCE& get(const IDENTIFIER& id)const;
private:
	unordered_map<int, unique_ptr<Texture>> map;
};

//Music loading

template<typename IDENTIFIER>
class Resources<Music, IDENTIFIER> 
{ 
public:
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	Resources() = default;
	template<typename ... Args>
	void load(const IDENTIFIER& id, Args&& ... args);

	Music& get(const IDENTIFIER& id)const;
private:
	unordered_map<IDENTIFIER, unique_ptr<Music>> map;
};


template<typename RESOURCE, typename IDENTIFIER>
template<typename ...Args>
inline void Resources<RESOURCE, IDENTIFIER>::load(const IDENTIFIER& id, Args && ...args)
{
	unique_ptr<RESOURCE> ptr(new RESOURCE);
	if (not ptr->loadFromFile(forward<Args>(args)...))
		throw runtime_error("Impossible to load file");
	map.emplace(id, move(ptr));
}

template<typename RESOURCE, typename IDENTIFIER>
inline RESOURCE& Resources<RESOURCE, IDENTIFIER>::get(const IDENTIFIER& id) const
{
	return *map.at(id);
}

template<typename IDENTIFIER>template<typename ... Args>
void Resources<Music, IDENTIFIER>::load(const IDENTIFIER& id, Args&& ... args)
{
	unique_ptr<Music> ptr(new Music);
	if (not ptr->openFromFile(forward<Args>(args)...))
		throw runtime_error("Impossible to load file");
	map.emplace(id, move(ptr));
};
template<typename IDENTIFIER>
Music& Resources<Music, IDENTIFIER>::get(const IDENTIFIER& id) const
{
	return *map.at(id);
}

