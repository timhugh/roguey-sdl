#include <catch2/catch_all.hpp>
#include <catch2/matchers/catch_matchers_all.hpp>
#include "core/services/LevelLoader.h"

using roguey::services::LevelLoader;

TEST_CASE("test loads level") {
    auto loader = LevelLoader("assets/");

    auto actualLevel = loader.load("test-level.json");
    REQUIRE(actualLevel.name == "test level");
    REQUIRE(actualLevel.width == 2);
    REQUIRE(actualLevel.height == 2);
    REQUIRE(actualLevel.baseColorHex == "#000000");
    REQUIRE_THAT(actualLevel.baseTiles, Catch::Matchers::Equals(std::vector<std::vector<int>>{
            {0, 2},
            {4, 3}
    }));

    REQUIRE_THAT(actualLevel.entities, Catch::Matchers::UnorderedEquals(std::vector<LevelLoader::Entity>{
            {"player", "character.man.1", 0, 0},
            {"door",   "door.h.closed",   0, 1},
            {"chest",  "chest",           1, 0}
    }));
}