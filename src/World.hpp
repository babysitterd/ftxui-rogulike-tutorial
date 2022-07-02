#pragma once

#include "Actor.hpp"
#include "Map.hpp"
#include "Point.hpp"

#include <ftxui/component/event.hpp>
#include <ftxui/dom/elements.hpp>

#include <set>

struct World
{
    World(Point const& playerPosition, int mapWidth, int mapHeight);

    ftxui::Element Render() const;

    bool EventHandler(ftxui::Event const& event);

    Actor m_player;
    Map m_map;
    std::set<Actor, Compare> m_actors;
};