# MINE based on TensorFlow Serving


----

To note some few features:

-   Can compute MI in multiple models, or multiple versions of the same model
    simultaneously
-   Exposes both gRPCi/REST as well as HTTP inference endpoints
-   Allows deployment of new model versions without changing any client code
-   Supports canarying new versions and A/B testing experimental models
-   Adds minimal latency to inference time due to efficient, low-overhead
    implementation

## Serve a Tensorflow model in 60 seconds
```bash
# Download the TensorFlow Serving Docker image and repo
docker pull tensorflow/serving

git clone https://github.com/dabidgs3/mineserv
# Location of demo models
TESTDATA="$(pwd)/serving/tensorflow_serving/servables/tensorflow/testdata"

# Start TensorFlow Serving container and open the REST API port
docker run -t --rm -p 8501:8501 \
    -v "$TESTDATA/saved_model_half_plus_two_cpu:/models/half_plus_two" \
    -e MODEL_NAME=half_plus_two \
    tensorflow/serving &

# Query the model using the predict API
curl -d '{"mine": channel}' \
    -X POST http://localhost:8501/v1/models/half_plus_two:predict

# Returns => { "mine": [2.5, 3.0, 4.5] }
```

## End-to-End Training & Serving Tutorial

Refer to the official Tensorflow documentations site for [a complete tutorial to train and serve a Tensorflow Model](https://www.tensorflow.org/tfx/tutorials/serving/rest_simple).


## Documentation

### Set up

The easiest and most straight-forward way of using TensorFlow Serving is with
Docker images. We highly recommend this route unless you have specific needs
that are not addressed by running in a container.

*   [Install Tensorflow Serving using Docker](tensorflow_serving/g3doc/docker.md)
    *(Recommended)*
*   [Install Tensorflow Serving without Docker](tensorflow_serving/g3doc/setup.md)
    *(Not Recommended)*
*   [Build Tensorflow Serving from Source with Docker](tensorflow_serving/g3doc/building_with_docker.md)
*   [Deploy Tensorflow Serving on Kubernetes](tensorflow_serving/g3doc/serving_kubernetes.md)

### Use



#### Configure and Use
## Contribute


**If you'd like to contribute to TensorFlow Serving, be sure to review the
[contribution guidelines](CONTRIBUTING.md).**


## For more information

Please refer to the official [TensorFlow website](http://tensorflow.org) for
more information.
