#pragma once

#include "op.h"

namespace opennmt {
  namespace ops {

    class Identity : public UnaryOp {
    public:
      void operator()(const StorageView& x, StorageView& y) const override {
        y = x;
      }
    };

  }
}
