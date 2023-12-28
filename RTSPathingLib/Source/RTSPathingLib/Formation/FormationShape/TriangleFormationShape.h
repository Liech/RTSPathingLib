#pragma once

#include "FormationShape.h"

namespace RTSPathingLib {
  class TriangleFormationShape : public FormationShape {
  public:
    TriangleFormationShape();
    virtual ~TriangleFormationShape();
    virtual std::string getType() const override;

    virtual std::vector<glm::dvec2> getPolygon() const        override;
    virtual size_t getNumberOfInterfacePoints() const        override;
    virtual glm::dvec2 getInterfacePoint(size_t number) const override; //center, edge0 start, edge0 center, edge1 start,... edge2 center
    virtual glm::dvec2 getInterfaceNormal(size_t number) const override;
    virtual double getInterfaceWidth(size_t number, const glm::dvec2& scale) const;

    virtual void fromJson(const nlohmann::json&) override;
    virtual nlohmann::json toJson() override;
  };
}