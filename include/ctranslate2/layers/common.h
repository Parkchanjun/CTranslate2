#pragma once

#include "ctranslate2/ops/ops.h"
#include "ctranslate2/models/model.h"

namespace ctranslate2 {
  namespace layers {

    class Embeddings
    {
    public:
      Embeddings(const models::Model& model, const std::string& scope);
      void operator()(const StorageView& ids, StorageView& output);
    private:
      ops::Gather _gather_op;
      const StorageView& _embeddings;
      const StorageView* _qscale;
    };

    class Dense
    {
    public:
      Dense(const models::Model& model, const std::string& scope);
      void operator()(const StorageView& input, StorageView& output);
      void mask_weights(const StorageView& index);
      void reset_mask();
    private:
      const StorageView& _weight;
      const StorageView* _bias;
      const StorageView* _qscale;
      StorageView _partial_weight;
      StorageView _partial_bias;
      StorageView _partial_qscale;
    };

    class LayerNorm
    {
    public:
      LayerNorm(const models::Model& model, const std::string& scope);
      void operator()(const StorageView& input, StorageView& output);
    private:
      ops::LayerNorm _norm_op;
      const StorageView& _beta;
      const StorageView& _gamma;
    };

  }
}
