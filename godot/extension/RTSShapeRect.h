#pragma once

#include "RTSFormationShape.h"

namespace godot {
  class RTSShapeRect : public RTSFormationShape {
    GDCLASS(RTSShapeRect, RTSFormationShape)

  protected:
    static void _bind_methods();

  public:
    RTSShapeRect();
    virtual ~RTSShapeRect();

    virtual std::unique_ptr<RTSNavigationLib::FormationShape> toShape() const override;
  };
}