#include <catch2/catch_test_macros.hpp>

#include <glm/gtc/matrix_transform.hpp>

#include <RTSPathingLib/Body.h>
#include "RTSPathingLib/Formation/FormationCalculator.h"
#include "RTSPathingLib/Formation/Formation.h"
#include "RTSPathingLib/Formation/FormationShape/RectangleFormationShape.h"
#include "RTSPathingLib/Formation/FormationShape/ArcFormationShape.h"
#include "RTSPathingLib/Formation/FormationShape/TriangleFormationShape.h"

TEST_CASE("Formation/RectangleSingle", "[FormationSingle]") {
  RTSPathingLib::Body b;
  b.category = 0;
  b.size = 1;
  b.position = glm::vec2(99, 99);

  std::vector<RTSPathingLib::Body> input = { b };
  RTSPathingLib::Formation formation(nullptr);
  formation.setShape(std::make_unique<RTSPathingLib::RectangleFormationShape>());
  auto places = RTSPathingLib::FormationCalculator::calculate(formation, input);

  REQUIRE(places.size() == input.size());
  REQUIRE(places[0].category == b.category);
  REQUIRE(places[0].size == b.size);
  REQUIRE(places[0].position.x == 0);
  REQUIRE(places[0].position.y == 0);
}

TEST_CASE("Formation/RectangleDouble", "[FormationDouble]") {
  RTSPathingLib::Body b;
  b.category = 0;
  b.size = 1;
  b.position = glm::vec2(99, 99);

  std::vector<RTSPathingLib::Body> input = { b, b };
  RTSPathingLib::Formation formation(nullptr);
  formation.setShape(std::make_unique<RTSPathingLib::RectangleFormationShape>());
  auto places = RTSPathingLib::FormationCalculator::calculate(formation, input);

  REQUIRE(places.size() == input.size());
  REQUIRE(places[0].category == b.category);
  REQUIRE(places[0].size == b.size);
  REQUIRE(places[0].position.x == -0.5);
  REQUIRE(places[0].position.y == 0);
  REQUIRE(places[1].category == b.category);
  REQUIRE(places[1].size == b.size);
  REQUIRE(places[1].position.x == 0.5);
  REQUIRE(places[1].position.y == 0);
}

TEST_CASE("Formation/ArcSingle", "[FormationSingle]") {
  RTSPathingLib::Body b;
  b.category = 0;
  b.size = 1;
  b.position = glm::vec2(99, 99);

  std::vector<RTSPathingLib::Body> input = { b };
  RTSPathingLib::Formation formation(nullptr);
  formation.setShape(std::make_unique<RTSPathingLib::ArcFormationShape>());
  auto places = RTSPathingLib::FormationCalculator::calculate(formation, input);

  REQUIRE(places.size() == input.size());
  REQUIRE(places[0].category == b.category);
  REQUIRE(places[0].size == b.size);
  REQUIRE(places[0].position.x == 0);
  REQUIRE(places[0].position.y == 0);
}

TEST_CASE("Formation/TriangleSingle", "[FormationSingle]") {
  RTSPathingLib::Body b;
  b.category = 0;
  b.size = 1;
  b.position = glm::vec2(99, 99);

  std::vector<RTSPathingLib::Body> input = { b };
  RTSPathingLib::Formation formation(nullptr);
  formation.setShape(std::make_unique<RTSPathingLib::TriangleFormationShape>());
  auto places = RTSPathingLib::FormationCalculator::calculate(formation, input);

  REQUIRE(places.size() == input.size());
  REQUIRE(places[0].category == b.category);
  REQUIRE(places[0].size == b.size);
  REQUIRE(places[0].position.x == 0);
  REQUIRE(places[0].position.y == 0);
}