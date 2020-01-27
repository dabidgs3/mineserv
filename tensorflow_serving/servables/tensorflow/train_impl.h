/* Copyright David Guzman. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_SERVING_SERVABLES_TENSORFLOW_TRAIN_IMPL_H_
#define TENSORFLOW_SERVING_SERVABLES_TENSORFLOW_TRAIN_IMPL_H_

#include "tensorflow/core/framework/tensor.pb.h"
#include "tensorflow/core/lib/core/status.h"
#include "tensorflow/core/protobuf/config.pb.h"
#include "tensorflow_serving/apis/train.pb.h"
#include "tensorflow_serving/model_servers/server_core.h"

namespace tensorflow {
namespace serving {

// Utility methods for implementation of PredictionService::Train.
class TensorflowTrainer {
 public:
  explicit TensorflowTrainer(bool use_saved_model)
      : use_saved_model_(use_saved_model) {}

  Status Train(const RunOptions& run_options, ServerCore* core,
                 const TrainRequest& request, TrainResponse* response);

  // Like Train(), but uses 'model_spec' instead of the one embedded in
  // 'request'.
  Status TrainWithModelSpec(const RunOptions& run_options, ServerCore* core,
                              const ModelSpec& model_spec,
                              const TrainRequest& request,
                              TrainResponse* response);

 private:
  // If use_saved_model_ is true, a SavedModelBundle handle will be retrieved
  // from the ServerCore and the new SavedModel SignatureDef format will be
  // used.
  bool use_saved_model_;
};

}  // namespace serving
}  // namespace tensorflow

#endif  // TENSORFLOW_SERVING_SERVABLES_TENSORFLOW_PREDICT_IMPL_H_
