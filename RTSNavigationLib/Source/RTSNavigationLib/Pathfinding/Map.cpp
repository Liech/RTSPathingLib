#include "Map.h"

#include <stdexcept>

namespace RTSNavigationLib {
  Map::Map(const std::vector<float>& obstacles_, const glm::ivec2 resolution_, const glm::ivec2& subResolution_, bool eikonal_) {
    resolution    = resolution_;
    subResolution = subResolution_;
    obstacles     = obstacles_;
    eikonal       = eikonal_;
  }

  size_t Map::getMap(const glm::ivec2& from, const glm::ivec2& to) {
    throw std::runtime_error("Not implemented Yet!");
  }

  float Map::getDistance(const glm::ivec2& from, const glm::ivec2& to) {
    throw std::runtime_error("Not implemented Yet!");
  }

  bool Map::hasMap(size_t id) const {
    throw std::runtime_error("Not implemented Yet!");
  }

  const FlowField& Map::getMap(size_t id) const {
    throw std::runtime_error("Not implemented Yet!");
  }

  size_t Map::addCostStamp(const std::vector<float>& obstacles, const glm::ivec2 resolution) {
    throw std::runtime_error("Not implemented Yet!");
  }

  void Map::removeCostStamp(size_t) {
    throw std::runtime_error("Not implemented Yet!");
  }
}