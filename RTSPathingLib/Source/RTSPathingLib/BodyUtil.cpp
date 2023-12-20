#include "BodyUtil.h"

#include "Body.h"

namespace RTSPathingLib {

  Body BodyUtil::transform(const Body& b, const glm::mat4& transformation) {
    Body result;
    result.blueprintID = b.blueprintID;
    result.position = transformation * glm::vec4(b.position,0,1);
    return result;
  }

  std::vector<Body> BodyUtil::transform(const std::vector<Body>& b, const glm::mat4& transformation) {
    std::vector<Body> result;
    result.resize(b.size());

    for (size_t i = 0; i < b.size();i++) {
      result[i].blueprintID = b[i].blueprintID;
      result[i].position = transformation * glm::vec4(b[i].position, 0, 1);
    }

    return result;
  }
  
  glm::vec2 BodyUtil::getCenter(const std::vector<Body>& b) {
    glm::vec2 result = glm::vec2(0,0);
    for (const auto& x : b) {
      result += x.position;
    }
    result = glm::vec2(result[0] / b.size(), result[1] / b.size());
    return result;
  }
}