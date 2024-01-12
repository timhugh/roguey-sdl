#include <catch2/catch_all.hpp>
#include <catch2/matchers/catch_matchers_all.hpp>
#include "core/services/TilesetLoader.h"
#include <iostream>

using namespace roguey::services;

TEST_CASE("test loads tileset") {
    auto loader = roguey::services::TilesetLoader("assets/");

    std::vector<Tile> expectedTiles = {
            {1,  1, 0,  true,  "ground.blank"},
            {8,  3, 22, true,  "chair"},
            {14, 0, 29, false, "character.woman.2"},
            {15, 1, 35, false, "flag.1"}
    };

    auto actualTileset = loader.load("test-tileset.json");
    REQUIRE(actualTileset.spritesheet == "test-tileset.png");
    REQUIRE(actualTileset.tilesize == 8);

    REQUIRE_THAT(actualTileset.tiles, Catch::Matchers::UnorderedEquals(expectedTiles));
}