#pragma once

#include <vector>
#include <glm/glm.hpp>

//https://howtorts.github.io/2014/01/04/basic-flow-fields.html
//https://www.jdxdev.com/blog/2020/05/03/flowfields/
//https://www.gameaipro.com/GameAIPro/GameAIPro_Chapter23_Crowd_Pathfinding_and_Steering_Using_Flow_Field_Tiles.pdf
//https://www.sanctuaryshatteredsun.com/post/pathfinding-1
//https://howtorts.github.io/
//https://howtorts.github.io/2014/01/05/flow-field-improvements.html
//https://github.com/bjkarasek/flowfield-unity  //Eikonal 

namespace RTSNavigationLib {
  class FlowField {
  public:
    FlowField(const std::vector<float>& obstacles, const glm::ivec2& resolution, const glm::ivec2& target);

    glm::dvec2 getDirection(const glm::ivec2& location) const;
  private:
    void initField(const std::vector<float>& obstacles);

    glm::ivec2                    resolution;
    glm::ivec2                    target;
    std::vector<glm::lowp_i8vec2> field;
  };
}