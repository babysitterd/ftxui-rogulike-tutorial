#include "ApprovalTests.hpp"

#include <catch2/catch.hpp>

#include "../src/FovMap.hpp"
#include "../src/Map.hpp"
#include "../src/NaiveMapGenerator.hpp"

#include <random>
#include <string>
#include <vector>

namespace
{

std::vector<std::string> const dungeon{
    "###########################################################",
    "#...........#.............................................#",
    "#...........#........#....................................#",
    "#.....................#...................................#",
    "#....####..............#..................................#",
    "#.......#.......................#####################.....#",
    "#.......#...........................................#.....#",
    "#.......#...........##..............................#.....#",
    "#####........#......##..........##################..#.....#",
    "#...#...........................#................#..#.....#",
    "#...#............#..............#................#..#.....#",
    "#...............................#..###############..#.....#",
    "#...............................#...................#.....#",
    "#...............................#...................#.....#",
    "#...............................#####################.....#",
    "#.........................................................#",
    "#.........................................................#",
    "###########################################################"};

} // namespace

TEST_CASE("MapGenerator")
{
    RNG rng(8'109'330);
    Map map(80, 45, rng);
    ApprovalTests::Approvals::verify(map);
}

TEST_CASE("Map deserialize")
{
    Map map(dungeon);
    ApprovalTests::Approvals::verify(map);
}

TEST_CASE("FOV")
{
    FovMap map(dungeon, 10);
    map.LineOfSight({36, 13});
    ApprovalTests::Approvals::verify(map);
}
