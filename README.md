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
    -v "$TESTDATA/saved_model:/models/mine" \
    -e MODEL_NAME=mine \
    tensorflow/serving &

# Query the model using the predict API
curl -d '{"mine": channel}' \
    -X POST http://localhost:8501/v1/models/mine:mine

# Returns => { "mine": [2.5, 3.0, 4.5] }
```

## End-to-End Training & Serving Tutorial

Refer to the official Tensorflow documentations site for [a complete tutorial to train and serve a Tensorflow Model](https://www.tensorflow.org/tfx/tutorials/serving/rest_simple).


## Documentation

### Set up
### Use

#### Configure and Use
## Contribute
## For more information

